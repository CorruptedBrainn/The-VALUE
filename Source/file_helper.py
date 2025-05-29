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