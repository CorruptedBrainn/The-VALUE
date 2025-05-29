from functools import partial

from PySide6.QtWidgets import (
    QStackedWidget,
    QWidget,
    QPushButton,
    QStackedLayout,
    QLabel,
    QGridLayout,
    )

from widget_helper import loadWidget, changeScreen
from file_helper import updateSaveLoad
import global_storage

class TVHomeContainer(QStackedWidget):
    def __init__(self, parent:QStackedLayout):
        super().__init__()
        page0 = loadWidget("home_page.ui")
        page1 = loadWidget("save_page.ui")
        self.addWidget(page0)
        self.addWidget(page1)

        startButton:QPushButton = page0.findChild(QPushButton, "startButton") # type: ignore
        startButton.clicked.connect(partial(changeScreen, parent, 0, 1))

        page1Layout:QGridLayout = page1.layout() # type: ignore
        saveWidgets = []
        saveButtons = []
        saveNumbers = []

        for i in range(3):
            saveWidgets.append(loadWidget("save_slot_widget.ui"))
            page1Layout.addWidget(saveWidgets[i], 1, i + 1)
            saveButtons.append(saveWidgets[i].findChild(QPushButton, "saveLoadButton"))
            saveButtons[i].clicked.connect(partial(changeScreen, parent, 1, 0))
            saveButtons[i].clicked.connect(partial(updateSaveLoad, i))
            saveNumbers.append(saveWidgets[i].findChild(QLabel, "saveNumber"))
            saveNumbers[i].setText("Save " + str(i + 1))