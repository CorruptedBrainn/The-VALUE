"""
Name: interface.py
Version: 0.0.4-alpha
Description: This file contains the classes for all the widgets I use
Author: Nicolas Martens
"""

import sys
from functools import partial

from PySide6.QtCore import ( # type: ignore
	QFile,
	QIODeviceBase,
	Slot,
	Qt,
	Signal,
	SignalInstance,
	)
from PySide6.QtWidgets import ( # type: ignore
	QWidget,
	QApplication,
	QMainWindow,
	QDialog,
	QDialogButtonBox,
	QListWidget,
	QListWidgetItem,
	QPushButton,
	)
from PySide6.QtGui import (# type: ignore
	QResizeEvent,
	QMoveEvent,
	)
from PySide6.QtUiTools import ( # type: ignore
	QUiLoader,
	)

# C:\Users\User\AppData\Local\Programs\Python\Python313\Scripts\pyside6-uic.exe interface.ui -o interface_file.py
# C:\Users\User\AppData\Local\Programs\Python\Python313\Scripts\pyside6-uic.exe save_slot.ui -o save_slot_file.py
# C:\Users\User\AppData\Local\Programs\Python\Python313\Scripts\pyside6-uic.exe settings_dialog.ui -o settings_dialog_file.py
from Widgets.interface_file import Ui_MainWindow
from Widgets.save_slot_file import Ui_SaveSlot
from Widgets.settings_dialog_file import Ui_Settings

from data import DataPackage

WIDGETPATH = "Widgets/"

@Slot(str)
def loadWidget(FILEPATH:str)->QWidget:
	file = QFile(WIDGETPATH + FILEPATH)
	loader = QUiLoader()
	file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
	ret:QWidget = loader.load(file)
	file.close()
	return ret

class TVSettingsDialog(QDialog):
	def __init__(self, parent):
		super().__init__(parent.window)

		self.package:DataPackage = parent.package

		self.dialog = Ui_Settings()
		self.dialog.setupUi(self)
		
		self.dialog.gameplayButton.clicked.connect(partial(self.dialog.stackedWidget.setCurrentIndex, 1))
		self.dialog.audioButton.clicked.connect(partial(self.dialog.stackedWidget.setCurrentIndex, 2))
		self.dialog.graphicsButton.clicked.connect(partial(self.dialog.stackedWidget.setCurrentIndex, 3))

		self.restore:SignalInstance = self.dialog.buttonBox.button(QDialogButtonBox.StandardButton.RestoreDefaults).clicked
		self.apply:SignalInstance = self.dialog.buttonBox.button(QDialogButtonBox.StandardButton.Apply).clicked

		self.accepted.connect(partial(self.applySettings))
		self.rejected.connect(partial(self.rejectSettings))
		self.restore.connect(partial(self.restoreDefaults))
		self.apply.connect(partial(self.applySettings))

		self.dialog.pushButton_4.clicked.connect(partial(self.dialog.stackedWidget.setCurrentIndex, 0))
		self.dialog.pushButton_5.clicked.connect(partial(self.dialog.stackedWidget.setCurrentIndex, 0))
		self.dialog.pushButton_6.clicked.connect(partial(self.dialog.stackedWidget.setCurrentIndex, 0))

		self.dialog.DebuggingModeComboBox.currentTextChanged.connect(partial(self.assign, self.package.settings.Gameplay["Information"], "Mode"))
		self.dialog.UnitDataComboBox.currentTextChanged.connect(partial(self.assign, self.package.settings.Gameplay["Information"], "Unit"))
		self.dialog.FoeDataComboBox.currentTextChanged.connect(partial(self.assign, self.package.settings.Gameplay["Information"], "Foe"))

		self.dialog.MusicSlider.valueChanged.connect(partial(self.assign, self.package.settings.Audio["Volume"], "Master"))
		self.dialog.EffectsSlider.valueChanged.connect(partial(self.assign, self.package.settings.Audio["Volume"], "SFX"))
		self.dialog.BackgroundSlider.valueChanged.connect(partial(self.assign, self.package.settings.Audio["Volume"], "Ambiance"))

		self.dialog.GameMusicList.itemSelectionChanged.connect(partial(self.manage, self.package.settings.Audio["Sound"], "Master", self.dialog.GameMusicList))
		self.dialog.SoundEffectsList.itemSelectionChanged.connect(partial(self.manage, self.package.settings.Audio["Sound"], "SFX", self.dialog.SoundEffectsList))
		self.dialog.AmbientList.itemSelectionChanged.connect(partial(self.manage, self.package.settings.Audio["Sound"], "Ambiance", self.dialog.AmbientList))

		self.dialog.InterfaceThemeList.currentItemChanged.connect(partial(self.select, self.package.settings.Graphic["Themes"], "GUI"))
		self.dialog.UnitThemeList.currentItemChanged.connect(partial(self.select, self.package.settings.Graphic["Themes"], "Units"))
		self.dialog.EnvironmentThemeList.currentItemChanged.connect(partial(self.select, self.package.settings.Graphic["Themes"], "Environment"))

		return

	@Slot(dict, str, str)
	@Slot(dict, str, int)
	def assign(self, obj:dict, key:str, val:str|int)->None:
		obj[key] = val
		return

	@Slot(dict, str, QListWidget)
	def manage(self, obj:dict, key:str, widget:QListWidget)->None:
		arr:list = widget.selectedItems()
		for i in range(len(arr)):
			arr[i] = arr[i].text()
		obj[key] = arr
		return

	@Slot(dict, str, QListWidgetItem, QListWidgetItem)
	def select(self, obj:dict, key:str, curr:QListWidgetItem, form:QListWidgetItem)->None:
		obj[key] = curr.text()
		return

	@Slot()
	def show(self)->None:
		self.updateValues()
		self.dialog.stackedWidget.setCurrentIndex(0)
		super().show()
		return

	@Slot()
	def updateValues(self)->None:
		self.dialog.DebuggingModeComboBox.setCurrentText(self.package.settings.Gameplay["Information"]["Mode"])
		self.dialog.UnitDataComboBox.setCurrentText(self.package.settings.Gameplay["Information"]["Unit"])
		self.dialog.FoeDataComboBox.setCurrentText(self.package.settings.Gameplay["Information"]["Foe"])

		self.dialog.MusicSlider.setValue(self.package.settings.Audio["Volume"]["Master"])
		self.dialog.EffectsSlider.setValue(self.package.settings.Audio["Volume"]["SFX"])
		self.dialog.BackgroundSlider.setValue(self.package.settings.Audio["Volume"]["Ambiance"])

		for i in range(self.dialog.GameMusicList.count()):
			item = self.dialog.GameMusicList.item(i)
			item.setSelected(item.text() in self.package.settings.Audio["Sound"]["Master"])
		for i in range(self.dialog.SoundEffectsList.count()):
			item = self.dialog.SoundEffectsList.item(i)
			item.setSelected(item.text() in self.package.settings.Audio["Sound"]["SFX"])
		for i in range(self.dialog.AmbientList.count()):
			item = self.dialog.AmbientList.item(i)
			item.setSelected(item.text() in self.package.settings.Audio["Sound"]["Ambiance"])

		arr:list = self.dialog.InterfaceThemeList.findItems(self.package.settings.Graphic["Themes"]["GUI"], Qt.MatchFlag.MatchExactly)
		self.dialog.InterfaceThemeList.setCurrentItem(arr[0])
		arr:list = self.dialog.UnitThemeList.findItems(self.package.settings.Graphic["Themes"]["Units"], Qt.MatchFlag.MatchExactly)
		self.dialog.UnitThemeList.setCurrentItem(arr[0])
		arr:list = self.dialog.EnvironmentThemeList.findItems(self.package.settings.Graphic["Themes"]["Environment"], Qt.MatchFlag.MatchExactly)
		self.dialog.EnvironmentThemeList.setCurrentItem(arr[0])

		return

	@Slot()
	def rejectSettings(self)->None:
		self.package.settings.readSettings()
		self.updateValues()
		return

	@Slot()
	def applySettings(self)->None:
		self.package.settings.storeSettings()
		self.updateValues()
		return

	@Slot()
	def restoreDefaults(self)->None:
		self.package.settings.resetSettings()
		self.updateValues()
		return

class TVSaveSlot(QWidget):
	selected = Signal(int)
	CLICKABLESTYLESHEET = """QPushButton {
		background-color: #33CCCCEE;
		}
		QPushButton:hover {
		background-color: #55CCCCEE;
		}"""
	CREATABLESTYLESHEET = """QPushButton {
		background-color: #77CCCCEE;
		}
		QPushButton:hover {
		background-color: #99CCCCEE;
		}"""

	def __init__(self, package:DataPackage, idx:int):
		super().__init__()

		self.package = package
		self.idx = idx

		self.slot = Ui_SaveSlot()
		self.slot.setupUi(self)
		self.clickable = QPushButton(self)

		self.clickable.setSizePolicy(self.sizePolicy())
		self.clickable.setGeometry(self.geometry())
		buttonFont = self.clickable.font()
		buttonFont.setBold(True)
		buttonFont.setPointSize(54)
		self.clickable.setFont(buttonFont)
		self.clickable.clicked.connect(partial(self.selected.emit, self.idx))

		self.updateData()
		return

	def updateData(self)->None:
		data = self.package.manager.readSave(self.idx)

		"""
		TODO:
		- Update as I go along to make proper formatting
		"""
		self.slot.slotNumber.setText(str(self.idx))
		if data["Data"]["Index"] == 0:
			self.clickable.setStyleSheet(TVSaveSlot.CREATABLESTYLESHEET)
			self.clickable.setText("+")
		else:
			self.clickable.setStyleSheet(TVSaveSlot.CLICKABLESTYLESHEET)
			self.clickable.setText("")
			self.slot.slotName.setText(data["Data"]["Name"])
			self.slot.slotDifficulty.setText(str(data["Data"]["Difficulty"]))
			self.slot.slotAge.setText(str(data["Prog"]["Age"]))
			self.slot.slotLastPlayed.setText(data["Data"]["Last"])
		return

	def resizeEvent(self, event:QResizeEvent)->None:
		self.clickable.resize(event.size())
		return super().resizeEvent(event)

class TVApplication(QApplication):
	gameLoaded = Signal()
	gamePaused = Signal()
	gameStopped = Signal()

	def __init__(self, package:DataPackage):
		super().__init__(sys.argv)

		self.package = package

		self.window = QMainWindow()
		self.interface = Ui_MainWindow()
		self.interface.setupUi(self.window)
		self.settingsDialog = TVSettingsDialog(self)

		"""
		TODO:
		- Automatic Saving
		- Savedata logic in "about to quit" slot
		- Comments
		"""
		self.interface.actionHome.triggered.connect(partial(self.interface.screenManager.setCurrentIndex, 0))
		self.interface.actionHome.triggered.connect(partial(self.gameStopped.emit))
		self.interface.actionLoadGame.triggered.connect(partial(self.interface.screenManager.setCurrentIndex, 1))
		self.interface.actionLoadGame.triggered.connect(partial(self.gameStopped.emit))
		self.interface.actionSaveGame.triggered.connect(partial(self.package.data.storeSave))
		self.interface.actionOptions.triggered.connect(partial(self.settingsDialog.show))
		self.interface.actionOptions.triggered.connect(partial(self.gamePaused.emit))
		self.interface.actionQuit.triggered.connect(partial(self.quit))
		
		self.interface.playGame.clicked.connect(partial(self.interface.screenManager.setCurrentIndex, 1))

		"""
		TODO:
		- Add the new save one
		- Make sure exeptions don't happen from my stupidity (namely the way I manage display data)
		- Do stuff to re-sort list
		"""
		self.saveSlotWidgets:list[TVSaveSlot] = []
		self.currentSelected = 0
		for i in range(1, len(self.package.manager.getSavesList()) + 1):
			self.addSaveSlot(i)

		self.interface.startGameButton.clicked.connect(partial(self.loadSave))
		self.interface.deleteGameButton.clicked.connect(partial(self.deleteSave))

		"""
		TODO:
		- Live game data
		- Implement game
		"""

		return

	@Slot(int)
	def addSaveSlot(self, idx:int)->None:
		slot = TVSaveSlot(self.package, idx)
		slot.selected.connect(partial(self.showSaveSlot))
		self.saveSlotWidgets.append(slot)
		self.interface.verticalLayout_9.addWidget(slot)
		return

	@Slot(int)
	def showSaveSlot(self, idx:int)->None:
		data = self.package.manager.readSave(idx)
		self.currentSelected = idx

		"""
		TODO:
		- Update formatting as I go along
		- Logic for buttons if save exists or not
		"""
		self.interface.saveName.setText(data["Data"]["Name"])
		self.interface.saveNumber.setText("Save " + str(idx))
		self.interface.characterName.setText(data["Data"]["Name"])
		self.interface.characterDifficulty.setText(str(data["Data"]["Difficulty"]))
		self.interface.characterLastPlayed.setText(data["Data"]["Last"])
		self.interface.characterAge.setText(str(data["Prog"]["Age"]))
		self.interface.characterAchievements.setText(str(data["Prog"]["Achivements"]))
		self.interface.characterTechnologies.setText(str(data["Prog"]["Technologies"]))
		self.interface.characterUnits.setText("N/A")
		self.interface.characterKills.setText(str(data["Data"]["Kills"]))
		self.interface.characterScrap.setText(str(data["Cons"]["Scrap"]))
		self.interface.characterPrecious.setText(str(data["Cons"]["Precious"]))
		self.interface.characterPlasma.setText(str(data["Cons"]["Plasma"]))

		self.interface.startGameButton.clicked.connect(partial(self.loadGame))
		
		return

	@Slot()
	def loadSave(self)->None:
		self.package.data.readSave(self.currentSelected)
		if self.package.data.Data["Index"] == 0:
			pass # We need to go through the save creation process -> update the current data package then immediately save to files
		else:
			self.interface.screenManager.setCurrentIndex(2)
		return

	@Slot()
	def deleteSave(self)->None:
		"""
		TODO:
		- Work out save deleting
		"""
		#...
		return

	@Slot()
	def loadGame(self)->None:
		"""
		TODO:
		- Either create new game then load, or load game
		"""
		self.gameLoaded.emit()
		return

	def start(self):
		self.window.setWindowState(Qt.WindowState.WindowFullScreen)
		self.window.show()

		self.interface.screenManager.setCurrentIndex(0)

		return sys.exit(self.exec())