import sys

import main_menu as mainMenu
import main_game as mainGame
import main_editor as mainEditor

from PySide6 import QtWidgets as QtW
from PySide6 import QtCore as QtC

class window(QtW.QMainWindow):
    def __init__(self, parent: QtW.QMainWindow = None):
        super().__init__(parent)
        
        # Central Widget
        self.grapics = QtW.QGraphicsScene()
        self.grapics.addText("The VALUE")
        self.startButton = QtW.QPushButton()

        self.view = QtW.QGraphicsView(self.grapics)
        self.setCentralWidget(self.view)

def openApplication():
    app = QtW.QApplication(sys.argv)
    mainWindow = window()
    mainWindow.show()
    return app.exec()

def main():
    sys.exit(openApplication())

if __name__ == "__main__":
    main()