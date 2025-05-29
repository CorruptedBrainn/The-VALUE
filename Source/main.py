import sys
from functools import partial

from PySide6.QtCore import (
    Slot,
    Signal,
    Qt
    )
from PySide6.QtWidgets import (
    QApplication,
    QHBoxLayout,
    QLabel,
    QMainWindow,
    QPushButton,
    QStackedLayout,
    QVBoxLayout,
    QWidget,
    )
from PySide6.QtGui import (
    QAction,
    )

from home_container import TVHomeContainer
from game_container import TVGameContainer
from widget_helper import loadWidget

@Slot()
def quitApp():
    return sys.exit(0)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window:QMainWindow = loadWidget("main_window.ui") # type: ignore
    homeContainer = TVHomeContainer()
    gameContainer = TVGameContainer()
    mainLayout = QStackedLayout()
    mainLayout.addWidget(homeContainer)
    mainLayout.addWidget(gameContainer)
    window.centralWidget().setLayout(mainLayout)
    quitButton:QAction = window.findChild(QAction, "actionQuit") # type: ignore
    quitButton.triggered.connect(quitApp)
    window.setWindowState(Qt.WindowState.WindowFullScreen)
    window.show()
    sys.exit(app.exec())