import copy

from PySide6.QtCore import QFile, QIODeviceBase, Slot, Qt
from PySide6.QtWidgets import QWidget, QStackedLayout, QStackedWidget, QDialog, QPushButton
from PySide6.QtUiTools import QUiLoader

import global_storage as gs

widgetPath = "Widgets/"

@Slot(str)
def loadWidget(filepath:str):
    file = QFile(widgetPath + filepath)
    loader = QUiLoader()
    file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
    ret:QWidget = loader.load(file)
    file.close()
    return ret

@Slot(QStackedLayout, int, int)
def changeScreen(mainLayout:QStackedLayout, rootIndex = 0, containerIndex = 0):
    mainLayout.setCurrentIndex(rootIndex)
    if mainLayout.currentWidget().inherits("QStackedWidget") == False:
        return
    container:QStackedWidget = mainLayout.currentWidget() # type: ignore
    container.setCurrentIndex(containerIndex)
    return

@Slot(QDialog)
def showDialog(dialog:QDialog):
    dialog.show()
    return

@Slot(QStackedLayout, QPushButton, str)
def changeMainScreen(layout:QStackedLayout, button:QPushButton, buttonIdx:str):
    # Needs a revamp / rewrite
    if (gs.mainCurrentPage == 0): button.setText("The Expanse")
    if (gs.mainCurrentPage == 1): button.setText("Journal")
    if (gs.mainCurrentPage == 2): button.setText("Technology Tree")
    if (gs.mainCurrentPage == 3): button.setText("Fleet Control")
    if (buttonIdx == 'A'): gs.mainCurrentPage, gs.buttonA = gs.buttonA, gs.mainCurrentPage
    if (buttonIdx == 'B'): gs.mainCurrentPage, gs.buttonB = gs.buttonB, gs.mainCurrentPage
    if (buttonIdx == 'C'): gs.mainCurrentPage, gs.buttonC = gs.buttonC, gs.mainCurrentPage
    changeScreen(layout, gs.mainCurrentPage)
    return

@Slot(QDialog)
def showSettings(settings:QDialog):
    loadSettingValues(settings)
    showDialog(settings)
    return

@Slot(QDialog)
def loadSettingValues(obj:QDialog):
    deep = copy.deepcopy(gs.settingData)

    obj.DebuggingModeComboBox.setCurrentText(deep["GPSet"]["InfoUtils"]["Mode"])
    obj.UnitDataComboBox.setCurrentText(deep["GPSet"]["InfoUtils"]["UDisplay"])
    obj.FoeDataComboBox.setCurrentText(deep["GPSet"]["InfoUtils"]["FDisplay"])

    obj.MusicSlider.setValue(deep["AudioSet"]["VolSet"]["Genval"])
    obj.EffectsSlider.setValue(deep["AudioSet"]["VolSet"]["SFXVal"])
    obj.BackgroundSlider.setValue(deep["AudioSet"]["VolSet"]["ABGVal"])
    for i in range(obj.GameMusicList.count()):
        item = obj.GameMusicList.item(i)
        item.setSelected(item.text() in deep["AudioSet"]["SoundPacks"]["GMusic"])
    for i in range(obj.SoundEffectsList.count()):
        item = obj.SoundEffectsList.item(i)
        item.setSelected(item.text() in deep["AudioSet"]["SoundPacks"]["SFX"])
    for i in range(obj.AmbientList.count()):
        item = obj.AmbientList.item(i)
        item.setSelected(item.text() in deep["AudioSet"]["SoundPacks"]["Amb"])

    arr:list = obj.InterfaceThemeList.findItems(deep["GraSet"]["Themes"]["GUI"], Qt.MatchFlag.MatchExactly)
    obj.InterfaceThemeList.setCurrentItem(arr[0])
    arr:list = obj.UnitThemeList.findItems(deep["GraSet"]["Themes"]["Uni"], Qt.MatchFlag.MatchExactly)
    obj.UnitThemeList.setCurrentItem(arr[0])
    arr:list = obj.EnvironmentThemeList.findItems(deep["GraSet"]["Themes"]["Env"], Qt.MatchFlag.MatchExactly)
    obj.EnvironmentThemeList.setCurrentItem(arr[0])
    return