from PySide6.QtCore import Slot

import global_storage

@Slot(int)
def updateSaveLoad(saveIndex):
    global_storage.saveIndex = saveIndex
    print(saveIndex)
    return

@Slot(int)
def deleteSave(saveIndex):
    print("I deleted save " + str(saveIndex))
    return

@Slot(int)
def closeSettings(result):
    if result == 1: applySettings()
    print("Settings closed with result code " + str(result))
    return

@Slot()
def resetSettings():
    print("Settings restored to default")
    return

@Slot()
def applySettings():
    print("Settings applied")
    return