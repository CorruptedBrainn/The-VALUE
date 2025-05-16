import sys

from window_classes import *

from PySide6.QtWidgets import QApplication

def openApplication():
    app = QApplication(sys.argv)
    appWindow = window()
    appWindow.show()
    return app.exec()

def main():
    sys.exit(openApplication())

if __name__ == "__main__":
    main()