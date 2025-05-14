from asyncio.windows_events import NULL
import sys

import main_menu as mainMenu
import main_game as mainGame
import main_editor as mainEditor

from PySide6 import QtWidgets as QtW

application = NULL

def openApplication():
    app = QtW.QApplication(sys.argv)
    label = QtW.QLabel("Hello World!")
    label.show()
    app.exec()

def main():
    openApplication()

if __name__ == "__main__":
    main()

    print ("Caleb wants his pink milkshake")