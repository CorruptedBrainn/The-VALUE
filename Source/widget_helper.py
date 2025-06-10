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

@Slot(QStackedLayout, list, int)
def changeMainScreen(layout:QStackedLayout, buttonList:list, buttonIdx:int):
    buttonList[0].setText("Journal")
    buttonList[1].setText("Technology Tree")
    buttonList[2].setText("Fleet Control")
    if (gs.mainCurrentPage == buttonIdx + 1): gs.mainCurrentPage = 0
    else: gs.mainCurrentPage = buttonIdx + 1
    if (gs.mainCurrentPage != 0):
        buttonList[buttonIdx].setText("The Expanse")
    changeScreen(layout, gs.mainCurrentPage)
    return
    
@Slot(QDialog)
def showSettings(settings:QDialog):
    loadSettingValues(settings)
    showDialog(settings)
    return

@Slot(QDialog)
def loadSettingValues(obj):
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

@Slot(QWidget, int)
def updateMainStats(obj, index:int):
    if (index != 0): return
    deep = copy.deepcopy(gs.saveData)

    gameDifficulty = ""
    if (deep["Difficulty"] == 0): gameDifficulty = "Easy"
    elif (deep["Difficulty"] == 1): gameDifficulty = "Normal"
    elif (deep["Difficulty"] == 2): gameDifficulty = "Advanced"
    elif (deep["Difficulty"] == 3): gameDifficulty = "Experienced"

    obj.characterName.setText(deep["Name"])
    obj.gameDifficulty.setText(gameDifficulty)

    obj.scrapMetals.setText(str(deep["Resources"]["SM"]) + " Units")
    obj.preciousMetals.setText(str(deep["Resources"]["PM"]) + " Units")
    obj.plasma.setText(str(deep["Resources"]["PL"]) + " Units")
    return

@Slot(QWidget, int)
def updateSaveStats(obj, saveIndex:int):
    from file_helper import updateSaveLoad

    updateSaveLoad(saveIndex)
    updateMainStats(obj, 0)
    return