from PySide6.QtCore import Slot

currentSave = 0

@Slot(int)
def doSomething(result):
    print("Saved some settings!")
    print(result)
    # SAVE FILES FOR LATERs
    return

@Slot(int)
def loadSomething(fileidx):
    global currentSave
    if fileidx == currentSave: return
    print("Loaded / created a file!")
    print(fileidx)
    currentSave = fileidx
    # LATER
    return