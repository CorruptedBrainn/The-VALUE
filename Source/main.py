import sys

from window_classes import *

from PySide6.QtWidgets import QApplication

def openApplication():
    app = QApplication(sys.argv)
    mainMenu.homepage()
    windows = app.allWindows()
    return app.exec()

def main():
    sys.exit(openApplication())

if __name__ == "__main__":
    main()