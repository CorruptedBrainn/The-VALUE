import json

from PySide6.QtCore import Slot

currentSave = 0

def updateSettings(filepath, settings, result):
    if (result != 1): return
    with open(filepath, "w") as file:
        text = json.dumps(settings)
        file.write(text)
    return

def loadSettings(filepath):
    temp = open(filepath, "a")
    temp.close()
    with open(filepath, "r") as file:
        text = file.read()
        settings = json.loads(text)
    return settings

def loadSomething(fileidx):
    global currentSave
    if fileidx == currentSave: return
    print("Loaded / created a file!")
    print(fileidx)
    currentSave = fileidx
    # LATER
    return