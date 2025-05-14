import sys

import main_menu as mainMenu
import main_game as mainGame
import main_editor as mainEditor

from PySide6 import QtWidgets as QtW

def openApplication():
    app = QtW.QApplication(sys.argv)
    return app.exec()

def main():
    sys.exit(openApplication())

if __name__ == "__main__":
    main()