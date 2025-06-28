from functools import partial
from turtle import back
import unittest

from PySide6.QtCore import ( # type: ignore
    Qt,
    Slot,
    )
from PySide6.QtWidgets import ( # type: ignore
    QStackedWidget,
    QPushButton,
    QDialogButtonBox,
    QDialog,
    QListWidget,
    QListWidgetItem,
    QComboBox,
    QSlider,
    )

from widget_helper import changeScreen
from file_helper import closeSettings, resetSettings, applySettings
import global_storage as gs

class TVSettingsDialog(QDialog):
    def __new__(cls, obj:QDialog):
        buttonBox:QDialogButtonBox = obj.findChild(QDialogButtonBox, "buttonBox") # type: ignore
        stack:QStackedWidget = obj.findChild(QStackedWidget, "stackedWidget") # type: ignore
        obj.setWindowModality(Qt.WindowModality.ApplicationModal)
        stack.setCurrentIndex(0)

        gameplayButton:QPushButton = obj.findChild(QPushButton, "gameplayButton") # type: ignore
        gameplayButton.clicked.connect(partial(changeScreen, stack, 1))
        audioButton:QPushButton = obj.findChild(QPushButton, "audioButton") # type: ignore
        audioButton.clicked.connect(partial(changeScreen, stack, 2))
        graphicsButton:QPushButton = obj.findChild(QPushButton, "graphicsButton") # type: ignore
        graphicsButton.clicked.connect(partial(changeScreen, stack, 3))

        obj.finished.connect(partial(changeScreen, stack, 0))
        back1:QPushButton = obj.findChild(QPushButton, "pushButton_4") # type: ignore
        back2:QPushButton = obj.findChild(QPushButton, "pushButton_5") # type: ignore
        back3:QPushButton = obj.findChild(QPushButton, "pushButton_6") # type: ignore
        back1.clicked.connect(partial(changeScreen, stack, 0))
        back2.clicked.connect(partial(changeScreen, stack, 0))
        back3.clicked.connect(partial(changeScreen, stack, 0))

        restoreDefaults:QPushButton = buttonBox.button(QDialogButtonBox.StandardButton.RestoreDefaults)
        apply:QPushButton = buttonBox.button(QDialogButtonBox.StandardButton.Apply)
        obj.finished.connect(partial(closeSettings))
        restoreDefaults.clicked.connect(partial(resetSettings, obj))
        apply.clicked.connect(partial(applySettings))

        debuggingMode:QComboBox = obj.findChild(QComboBox, "DebuggingModeComboBox") # type: ignore
        debuggingMode.currentTextChanged.connect(partial(cls.assignSetting, "GPSet", "InfoUtils", "Mode"))
        unitData:QComboBox = obj.findChild(QComboBox, "UnitDataComboBox") # type: ignore
        unitData.currentTextChanged.connect(partial(cls.assignSetting, "GPSet", "InfoUtils", "UDisplay"))
        foeData:QComboBox = obj.findChild(QComboBox, "FoeDataComboBox") # type: ignore
        foeData.currentTextChanged.connect(partial(cls.assignSetting, "GPSet", "InfoUtils", "FDisplay"))

        musicSlider:QSlider = obj.findChild(QSlider, "MusicSlider") # type: ignore
        musicSlider.valueChanged.connect(partial(cls.assignSetting, "AudioSet", "VolSet", "Genval"))
        effectsSlider:QSlider = obj.findChild(QSlider, "EffectsSlider") # type: ignore
        effectsSlider.valueChanged.connect(partial(cls.assignSetting, "AudioSet", "VolSet", "SFXVal"))
        backgroundSlider:QSlider = obj.findChild(QSlider, "BackgroundSlider") # type: ignore
        backgroundSlider.valueChanged.connect(partial(cls.assignSetting, "AudioSet", "VolSet", "ABGVal"))

        gameMusic:QListWidget = obj.findChild(QListWidget, "GameMusicList") # type: ignore
        gameMusic.itemSelectionChanged.connect(partial(cls.manageList, "AudioSet", "SoundPacks", "GMusic", gameMusic))
        soundEffects:QListWidget = obj.findChild(QListWidget, "SoundEffectsList") # type: ignore
        soundEffects.itemSelectionChanged.connect(partial(cls.manageList, "AudioSet", "SoundPacks", "SFX", soundEffects))
        ambientMusic:QListWidget = obj.findChild(QListWidget, "AmbientList") # type: ignore
        ambientMusic.itemSelectionChanged.connect(partial(cls.manageList, "AudioSet", "SoundPacks", "Amb", ambientMusic))

        interfaceTheme:QListWidget = obj.findChild(QListWidget, "InterfaceThemeList") # type: ignore
        interfaceTheme.currentItemChanged.connect(partial(cls.singleSelect, "GraSet", "Themes", "GUI"))
        unitTheme:QListWidget = obj.findChild(QListWidget, "UnitThemeList") # type: ignore
        unitTheme.currentItemChanged.connect(partial(cls.singleSelect, "GraSet", "Themes", "Uni"))
        environmentTheme:QListWidget = obj.findChild(QListWidget, "EnvironmentThemeList") # type: ignore
        environmentTheme.currentItemChanged.connect(partial(cls.singleSelect, "GraSet", "Themes", "Env"))

        return obj

    @Slot(str, str, str, str)
    @Slot(str, str, str, int)
    def assignSetting(self, keyI:str, keyII:str, keyIII:str, val):
        gs.settingData[keyI][keyII][keyIII] = val
        return

    @Slot(str, str, str, QListWidget)
    def manageList(self, keyI:str, keyII:str, keyIII:str, widget:QListWidget):
        arr:list = widget.selectedItems()
        for i in range(len(arr)):
            arr[i] = arr[i].text()
        gs.settingData[keyI][keyII][keyIII] = arr
        return

    @Slot(str, str, str, QListWidgetItem, QListWidgetItem)
    def singleSelect(self, keyI:str, keyII:str, keyIII:str, current:QListWidgetItem, former:QListWidgetItem):
        gs.settingData[keyI][keyII][keyIII] = current.text()
        return