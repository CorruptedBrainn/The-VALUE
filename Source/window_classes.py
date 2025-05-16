from PySide6.QtWidgets import QMainWindow, QHBoxLayout, QVBoxLayout, QPushButton, QLabel, QStatusBar, QWidget
from PySide6.QtCore import Slot

class homepage(QMainWindow):
    def __init__(self, parent = None):
        super(homepage, self).__init__(parent)
        self.setWindowTitle("The VALUE - Home")
        
        settings = QPushButton("Settings")
        menuLayout = QHBoxLayout()
        menuLayout.addWidget(settings)
        menuControl = QWidget()
        menuControl.setLayout(menuLayout)
        self.setMenuWidget(menuControl)

        title = QLabel("The VALUE")
        start = QPushButton("Start")
        mainLayout = QVBoxLayout()
        mainLayout.addWidget(title)
        mainLayout.addWidget(start)
        mainControl = QWidget()
        mainControl.setLayout(mainLayout)
        self.setCentralWidget(mainControl)

        version = QLabel("Version 0.00.0")
        self.statusBar().addWidget(version)

        self.show()

    @Slot()
    def goToSave

class saveMenu(QMainWindow):
    def __init__(self, parent = None):
        super(saveMenu, self).__init__(parent)
        self.setWindowTitle("The VALUE - Savefile Selection")

        settings = QPushButton("Settings")
        back = QPushButton("Back")
        menuLayout = QHBoxLayout()
        menuLayout.addWidget(back)
        menuLayout.addWidget(settings)
        menuControl = QWidget()
        menuControl.setLayout(menuLayout)
        self.setMenuWidget(menuControl)

        self.show()