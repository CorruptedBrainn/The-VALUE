from functools import partial

from PySide6.QtCore import (
    Qt,
    Slot,
    )
from PySide6.QtWidgets import (
    QStackedWidget,
    QPushButton,
    QDialogButtonBox,
    QDialog,
    QListWidget,
    QListWidgetItem,
    )

from widget_helper import changeScreen
from file_helper import closeSettings, resetSettings, applySettings
import global_storage as gs

class TVSettingsDialog(QDialog):
    def __new__(cls, obj):
        buttonBox:QDialogButtonBox = obj.findChild(QDialogButtonBox, "buttonBox") # type: ignore
        stack:QStackedWidget = obj.findChild(QStackedWidget, "stackedWidget") # type: ignore
        obj.setWindowModality(Qt.ApplicationModal)
        stack.setCurrentIndex(0)

        obj.gameplayButton.clicked.connect(partial(changeScreen, stack, 1))
        obj.audioButton.clicked.connect(partial(changeScreen, stack, 2))
        obj.graphicsButton.clicked.connect(partial(changeScreen, stack, 3))

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

        obj.DebuggingModeComboBox.currentTextChanged.connect(partial(cls.assignSetting, "GPSet", "InfoUtils", "Mode"))
        obj.UnitDataComboBox.currentTextChanged.connect(partial(cls.assignSetting, "GPSet", "InfoUtils", "UDisplay"))
        obj.FoeDataComboBox.currentTextChanged.connect(partial(cls.assignSetting, "GPSet", "InfoUtils", "FDisplay"))

        obj.MusicSlider.valueChanged.connect(partial(cls.assignSetting, "AudioSet", "VolSet", "Genval"))
        obj.EffectsSlider.valueChanged.connect(partial(cls.assignSetting, "AudioSet", "VolSet", "SFXVal"))
        obj.BackgroundSlider.valueChanged.connect(partial(cls.assignSetting, "AudioSet", "VolSet", "ABGVal"))

        obj.GameMusicList.itemSelectionChanged.connect(partial(cls.manageList, "AudioSet", "SoundPacks", "GMusic", obj.GameMusicList))
        obj.SoundEffectsList.itemSelectionChanged.connect(partial(cls.manageList, "AudioSet", "SoundPacks", "SFX", obj.SoundEffectsList))
        obj.AmbientList.itemSelectionChanged.connect(partial(cls.manageList, "AudioSet", "SoundPacks", "Amb", obj.AmbientList))

        obj.InterfaceThemeList.currentItemChanged.connect(partial(cls.singleSelect, "GraSet", "Themes", "GUI"))
        obj.UnitThemeList.currentItemChanged.connect(partial(cls.singleSelect, "GraSet", "Themes", "Uni"))
        obj.EnvironmentThemeList.currentItemChanged.connect(partial(cls.singleSelect, "GraSet", "Themes", "Env"))

        return obj

    @Slot(str, str, str, str)
    @Slot(str, str, str, int)
    def assignSetting(keyI:str, keyII:str, keyIII:str, val):
        gs.settingData[keyI][keyII][keyIII] = val
        return

    @Slot(str, str, str, QListWidget)
    def manageList(keyI:str, keyII:str, keyIII:str, widget:QListWidget):
        arr:list = widget.selectedItems()
        for i in range(len(arr)):
            arr[i] = arr[i].text()
        gs.settingData[keyI][keyII][keyIII] = arr
        return

    @Slot(str, str, str, QListWidgetItem, QListWidgetItem)
    def singleSelect(keyI:str, keyII:str, keyIII:str, current:QListWidgetItem, former:QListWidgetItem):
        gs.settingData[keyI][keyII][keyIII] = current.text()
        return