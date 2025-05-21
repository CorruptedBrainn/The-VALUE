import sys

from PySide6.QtWidgets import QApplication, QMainWindow
from PySide6.QtUiTools import QUiLoader
from PySide6.QtCore import QFile, QIODeviceBase, Qt, Slot
from PySide6.QtGui import QAction

@Slot()
def quit():
    return sys.exit(0)

@Slot()
def newSave():
    pass

@Slot()
def findSave():
    pass

@Slot()
def settings():
    pass

def openApplication():
    app = QApplication(sys.argv)
    loader = QUiLoader()

    windowFile = QFile("UI Widgets/MainWindow.ui")
    windowFile.open(QIODeviceBase.OpenModeFlag.ReadOnly)
    mainWindow:QMainWindow = loader.load(windowFile)
    windowFile.close()



    quitButton:QAction = mainWindow.findChild(QAction, "actionQuit")
    quitButton.triggered.connect(quit)

    settingsButton:QAction = mainWindow.findChild(QAction, "actionSettings")
    settingsButton.triggered.connect(settings)

    loadSaveButton:QAction = mainWindow.findChild(QAction, "actionLoad_Save")
    loadSaveButton.triggered.connect(findSave)

    newSaveButton:QAction = mainWindow.findChild(QAction, "actionNew_Save")
    newSaveButton.triggered.connect(newSave)

    mainWindow.setWindowState(Qt.WindowState.WindowFullScreen)

    mainWindow.show()
    return app.exec()

def main():
    sys.exit(openApplication())

if __name__ == "__main__":
    main()