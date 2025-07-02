import sys
from functools import partial

from PySide6.QtCore import ( # type: ignore
    Slot,
    )
from PySide6.QtWidgets import ( # type: ignore
    QStackedWidget,
    QPushButton,
    QStackedLayout,
    QLabel,
    QGridLayout,
    )

from widget_helper import loadWidget, changeScreen, updateSaveStats
from file_helper import updateSaveLoad, deleteSave

@Slot()
def quitApp():
    return sys.exit(0)

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
        saveDeletes = []
        saveNumbers = []

        for i in range(3):
            saveWidgets.append(loadWidget("save_slot_widget.ui"))
            updateSaveStats(saveWidgets[i], i + 1)
            page1Layout.addWidget(saveWidgets[i], 1, i + 1)
            saveButtons.append(saveWidgets[i].findChild(QPushButton, "saveLoadButton"))
            # Add something for new saves
            saveButtons[i].clicked.connect(partial(updateSaveLoad, i + 1))
            saveButtons[i].clicked.connect(partial(changeScreen, parent, 1, 0))
            saveDeletes.append(saveWidgets[i].findChild(QPushButton, "saveDeleteButton"))
            saveDeletes[i].clicked.connect(partial(deleteSave, i + 1))
            saveDeletes[i].clicked.connect(partial(changeScreen, parent, 0, 1))
            saveNumbers.append(saveWidgets[i].findChild(QLabel, "saveNumber"))
            saveNumbers[i].setText("Save " + str(i + 1))