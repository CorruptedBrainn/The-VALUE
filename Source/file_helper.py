from PySide6.QtCore import Slot

import global_storage

@Slot(int)
def updateSaveLoad(saveIndex):
    global_storage.saveIndex = saveIndex
    print(saveIndex)
    return