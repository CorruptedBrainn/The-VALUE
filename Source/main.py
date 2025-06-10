import sys
from functools import partial

from PySide6.QtCore import (
    Slot,
    Qt
    )
from PySide6.QtWidgets import (
    QApplication,
    QStackedLayout,
    QStackedWidget,
    QMainWindow,
    QPushButton,
    QDialog,
    )
from PySide6.QtGui import (
    QAction,
    )

from home_container import TVHomeContainer
from game_container import TVGameContainer
from dialog_container import TVSettingsDialog
from widget_helper import (
    loadWidget,
    changeScreen,
    showSettings,
    )
from file_helper import setupWorkspace

@Slot()
def quitApp():
    return sys.exit(0)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    setupWorkspace()
    window:QMainWindow = loadWidget("main_window.ui") # type: ignore
    mainLayout = QStackedLayout()
    homeContainer = TVHomeContainer(mainLayout)
    gameContainer = TVGameContainer(mainLayout)
    settingsDialog = TVSettingsDialog(loadWidget("settings_dialog.ui"))
    mainLayout.addWidget(homeContainer)
    mainLayout.addWidget(gameContainer)
    window.centralWidget().setLayout(mainLayout)
    actionQuit:QAction = window.findChild(QAction, "actionQuit") # type: ignore
    actionQuit.triggered.connect(quitApp)
    actionMain_Menu:QAction = window.findChild(QAction, "actionMain_Menu") # type: ignore
    actionMain_Menu.triggered.connect(partial(changeScreen, mainLayout, 0, 0))
    actionLoad_Save:QAction = window.findChild(QAction, "actionLoad_Save") # type: ignore
    actionLoad_Save.triggered.connect(partial(changeScreen, mainLayout, 0, 1))
    actionSettings:QAction = window.findChild(QAction, "actionOptions") # type: ignore
    actionSettings.triggered.connect(partial(showSettings, settingsDialog))
    window.setWindowState(Qt.WindowState.WindowFullScreen)
    window.show()
    sys.exit(app.exec())