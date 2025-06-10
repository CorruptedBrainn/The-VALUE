import os
import json
import copy

from PySide6.QtCore import Slot
from PySide6.QtWidgets import QDialog

from widget_helper import showSettings
import global_storage as gs

dataFolder = "Data/"
settingsFile = dataFolder + "Global.tvsf"
saveAFolder = dataFolder + "I/"
saveBFolder = dataFolder + "II/"
saveCFolder = dataFolder + "III/"

def setupWorkspace():
    if (os.path.exists(dataFolder) == False): os.makedirs(dataFolder)
    if (os.path.exists(settingsFile) == False):
        with open(settingsFile, "x") as file:
            text = json.dumps(gs.settingDefault)
            file.write(text)
    if (os.path.exists(saveAFolder) == False): os.makedirs(saveAFolder)
    if (os.path.exists(saveBFolder) == False): os.makedirs(saveBFolder)
    if (os.path.exists(saveCFolder) == False): os.makedirs(saveCFolder)
    loadSettings()

@Slot(int)
def updateSaveLoad(saveIndex):
    gs.saveIndex = saveIndex
    print(saveIndex)
    return

@Slot(int)
def deleteSave(saveIndex):
    print("I deleted save " + str(saveIndex))
    return

@Slot()
def loadSettings():
    with open (settingsFile, "r") as file:
        text = file.read()
        gs.settingData = json.loads(text)
    return

@Slot(int)
def closeSettings(result):
    if result == 1: applySettings()
    loadSettings()
    return

@Slot(QDialog)
def resetSettings(obj:QDialog):
    gs.settingData = copy.deepcopy(gs.settingDefault)
    showSettings(obj)
    return

@Slot()
def applySettings():
    with open(settingsFile, "w") as file:
        text = json.dumps(gs.settingData)
        file.write(text)
    return