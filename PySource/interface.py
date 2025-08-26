"""
Name: interface.py
Version: 0.0.4-alpha
Description: This file contains the classes for all the widgets I use
Author: Nicolas Martens
"""

import sys
from functools import partial

from PySide6.QtCore import (
	QFile,
	QIODeviceBase,
	Slot,
	Qt,
	)
from PySide6.QtWidgets import (
	QApplication,
	QWidget,
	QMainWindow,
	QStackedLayout,
	QStackedWidget,
	QDialog,
	QPushButton,
	QLabel,
	QListWidget,
	QDialogButtonBox,
	QComboBox,
	QSlider,
	QVBoxLayout,
	QTextEdit,
	)
from PySide6.QtGui import (
	QAction,
	)
from PySide6.QtUiTools import (
	QUiLoader,
	)

WIDGETPATH = "Widgets/"

class TVApplication(QApplication):
	def __init__(self):
		super().__init__(sys.argv)

		self.window:QMainWindow = loadWidget("main_window.ui") # type: ignore
		self.mainLayout = QStackedLayout()
		self.homeContainer = TVHomescreen(self.mainLayout)
		self.gameContainer = TVGamePage(self.mainLayout)
		self.settingsDialog = TVSettings(loadWidget("settings_dialog.ui"))
		self.mainLayout.addWidget(self.homeContainer)
		self.mainLayout.addWidget(self.gameContainer)
		self.window.centralWidget().setLayout(self.mainLayout)

		self.actionQuit:QAction = self.window.findChild(QAction, "actionQuit") # type: ignore
		#self.actionQuit.triggered.connect(partial(storeSave))
		self.actionQuit.triggered.connect(partial(self.exit))
		self.actionMain_Menu:QAction = self.window.findChild(QAction, "actionMain_Menu") # type: ignore
		#self.actionMain_Menu.triggered.connect(partial(storeSave))
		self.actionMain_Menu.triggered.connect(partial(self.mainLayout.setCurrentIndex, 0))
		self.actionMain_Menu.triggered.connect(partial(self.homeContainer.setCurrentIndex, 0))
		self.actionLoad_Save:QAction = self.window.findChild(QAction, "actionLoad_Save") # type: ignore
		#self.actionLoad_Save.triggered.connect(partial(storeSave))
		self.actionLoad_Save.triggered.connect(partial(self.mainLayout.setCurrentIndex, 0))
		self.actionLoad_Save.triggered.connect(partial(self.homeContainer.setCurrentIndex, 1))
		self.actionSettings:QAction = self.window.findChild(QAction, "actionOptions") # type: ignore
		self.actionSettings.triggered.connect(partial(self.settingsDialog.show))

		#self.mainLayout.currentChanged.connect(partial(do something with changing current index so we can update data as needed))
		self.window.setWindowState(Qt.WindowState.WindowFullScreen)
		self.window.show()

		return

class TVGamePage(QStackedWidget):
	def __init__(self, parent:QStackedLayout):
		super().__init__()

		self.page0 = loadWidget("main_game.ui")
		self.page1 = loadWidget("editor.ui")
		self.addWidget(self.page0)
		self.addWidget(self.page1)

		self.page0Layout:QVBoxLayout = self.page0.layout()
		self.mainGameLayout:QStackedWidget = QStackedWidget()
		self.theExpanse:QWidget = loadWidget("the_expanse.ui")
		self.theJournal:QWidget = loadWidget("journal.ui")
		self.theTechTree:QWidget = loadWidget("tech_tree.ui")
		self.theFleetControl:QWidget = loadWidget("fleet_control.ui")
		self.mainGameLayout.addWidget(self.theExpanse)
		self.mainGameLayout.addWidget(self.theJournal)
		self.mainGameLayout.addWidget(self.theTechTree)
		self.mainGameLayout.addWidget(self.theFleetControl)
		self.page0Layout.addWidget(self.mainGameLayout)
		self.page0Layout.setStretch(1, 6)
		#self.mainGameLayout.currentChanged.connect(partial(self.changeState))

		self.ButtonA:QPushButton = self.page0.findChild(QPushButton, "GenericButton1") # type: ignore
		self.ButtonB:QPushButton = self.page0.findChild(QPushButton, "GenericButton2") # type: ignore
		self.ButtonC:QPushButton = self.page0.findChild(QPushButton, "GenericButton3") # type: ignore
		self.buttonList = [self.ButtonA, self.ButtonB, self.ButtonC]
		self.ButtonA.clicked.connect(partial(self.changeMainScreen, 0))
		self.ButtonB.clicked.connect(partial(self.changeMainScreen, 1))
		self.ButtonC.clicked.connect(partial(self.changeMainScreen, 2))

		self.editorButton:QPushButton = self.theFleetControl.findChild(QPushButton, "EditorButton") # type: ignore
		self.editorButton.clicked.connect(partial(self.setCurrentIndex, 1))

		self.codeEditor:QTextEdit = self.page1.findChild(QTextEdit, "codeEditor") # type: ignore
		self.mainExpanseButton:QPushButton = self.page1.findChild(QPushButton, "BackButton") # type: ignore
		#self.mainExpanseButton.clicked.connect(partial(self.parseValuescript, self.codeEditor, parent))

		return

	@Slot(int)
	def changeMainScreen(self, idx:int):
		self.buttonList[0].setText("Journal")
		self.buttonList[1].setText("Technology Tree")
		self.buttonList[2].setText("Fleet Control")
		self.buttonList[idx].setText("The Expanse")
		self.mainGameLayout.setCurrentIndex(idx)
		return

class TVHomescreen(QStackedWidget):
	def __init__(self, parent:QStackedLayout):
		super().__init__()

		self.page0 = loadWidget("home_page.ui")
		self.page1 = loadWidget("save_page.ui")
		self.newDialog = TVNewSave(loadWidget("new_save_dialog.ui"))
		self.addWidget(self.page0)
		self.addWidget(self.page1)

		self.startButton:QPushButton = self.page0.findChild(QPushButton, "startButton") # type: ignore
		self.startButton.clicked.connect(partial(self.setCurrentIndex, 1))

		self.page1Layout:QGridLayout = self.page1.layout() # type: ignore
		self.saveWidgets = []
		self.saveButtons = []
		self.saveDeletes = []
		self.saveNumbers = []

		for i in range(3):
			self.saveWidgets.append(loadWidget("save_slot_widget.ui"))
			#updateSaveStats(self.saveWidgets[i], i + 1)
			self.page1Layout.addWidget(self.saveWidgets[i], 1, i + 1)
			self.saveButtons.append(self.saveWidgets[i].findChild(QPushButton, "saveLoadButton"))
			#self.saveButtons[i].clicked.connect(partial(updateSaveLoad, i + 1))
			#self.saveButtons[i].clicked.connect(partial(createSave, parent))
			self.saveDeletes.append(self.saveWidgets[i].findChild(QPushButton, "saveDeleteButton"))
			#self.saveDeletes[i].clicked.connect(partial(deleteSave, i + 1, self.saveWidgets[i]))
			#self.saveDeletes[i].clicked.connect(partial(changeScreen, parent, 0, 1))
			self.saveNumbers.append(self.saveWidgets[i].findChild(QLabel, "saveNumber"))
			self.saveNumbers[i].setText("Save " + str(i + 1))

		return

class TVSettings(QDialog):
	def __new__(cls, obj:QDialog) -> QDialog:
		buttonBox:QDialogButtonBox = obj.findChild(QDialogButtonBox, "buttonBox") # type: ignore
		stack:QStackedWidget = obj.findChild(QStackedWidget, "stackedWidget") # type: ignore
		obj.setWindowModality(Qt.WindowModality.ApplicationModal)
		stack.setCurrentIndex(0)

		gameplayButton:QPushButton = obj.findChild(QPushButton, "gameplayButton") # type: ignore
		gameplayButton.clicked.connect(partial(stack.setCurrentIndex, 1))
		audioButton:QPushButton = obj.findChild(QPushButton, "audioButton") # type: ignore
		audioButton.clicked.connect(partial(stack.setCurrentIndex, 2))
		graphicsButton:QPushButton = obj.findChild(QPushButton, "graphicsButton") # type: ignore
		graphicsButton.clicked.connect(partial(stack.setCurrentIndex, 3))

		obj.finished.connect(partial(stack.setCurrentIndex, 0))
		back1:QPushButton = obj.findChild(QPushButton, "pushButton_4") # type: ignore
		back2:QPushButton = obj.findChild(QPushButton, "pushButton_5") # type: ignore
		back3:QPushButton = obj.findChild(QPushButton, "pushButton_6") # type: ignore
		back1.clicked.connect(partial(stack.setCurrentIndex, 0))
		back2.clicked.connect(partial(stack.setCurrentIndex, 0))
		back3.clicked.connect(partial(stack.setCurrentIndex, 0))

		restoreDefaults:QPushButton = buttonBox.button(QDialogButtonBox.StandardButton.RestoreDefaults)
		apply:QPushButton = buttonBox.button(QDialogButtonBox.StandardButton.Apply)
		#obj.finished.connect(partial(closeSettings))
		#restoreDefaults.clicked.connect(partial(resetSettings, obj))
		#apply.clicked.connect(partial(applySettings))

		return obj

	def __init__(self) -> None:
		self.debuggingMode:QComboBox = self.findChild(QComboBox, "DebuggingModeComboBox") # type: ignore
		self.unitData:QComboBox = self.findChild(QComboBox, "UnitDataComboBox") # type: ignore
		self.foeData:QComboBox = self.findChild(QComboBox, "FoeDataComboBox") # type: ignore

		self.musicSlider:QSlider = self.findChild(QSlider, "MusicSlider") # type: ignore
		self.effectsSlider:QSlider = self.findChild(QSlider, "EffectsSlider") # type: ignore
		self.backgroundSlider:QSlider = self.findChild(QSlider, "BackgroundSlider") # type: ignore

		self.gameMusic:QListWidget = self.findChild(QListWidget, "GameMusicList") # type: ignore
		self.soundEffects:QListWidget = self.findChild(QListWidget, "SoundEffectsList") # type: ignore
		self.ambientMusic:QListWidget = self.findChild(QListWidget, "AmbientList") # type: ignore

		self.interfaceTheme:QListWidget = self.findChild(QListWidget, "InterfaceThemeList") # type: ignore
		self.unitTheme:QListWidget = self.findChild(QListWidget, "UnitThemeList") # type: ignore
		self.environmentTheme:QListWidget = self.findChild(QListWidget, "EnvironmentThemeList") # type: ignore

		return

	@Slot()
	def show(self) -> None:


		super().show()
		return

class TVNewSave(QDialog):
	def __new__(cls, obj:QDialog):
		obj.setWindowModality(Qt.WindowModality.ApplicationModal)

		#obj.finished.connect(partial(cls.updateData, obj))

		return obj

@Slot(str)
def loadWidget(FILEPATH:str):
	file = QFile(WIDGETPATH + FILEPATH)
	loader = QUiLoader()
	file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
	ret:QWidget = loader.load(file)
	file.close()
	return ret