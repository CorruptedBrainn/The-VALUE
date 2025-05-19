import sys

from PySide6.QtWidgets import QApplication, QWidget
from PySide6.QtDesigner import QFormBuilder
from PySide6.QtCore import QFile, QIODeviceBase, Qt

def quit():
    return sys.exit(0)

def openApplication():
    app = QApplication(sys.argv)
    builder = QFormBuilder()

    mainWindow = QWidget()
    mainWindow.setWindowState(Qt.WindowState.WindowFullScreen)

    homepageFile = QFile("UI Widgets/Homepage.ui")
    homepageFile.open(QIODeviceBase.OpenModeFlag.ReadOnly)
    homepage = builder.load(homepageFile, mainWindow)
    homepageFile.close()

    mainWindow.show()
    homepage.show()
    return app.exec()

def main():
    sys.exit(openApplication())

if __name__ == "__main__":
    main()