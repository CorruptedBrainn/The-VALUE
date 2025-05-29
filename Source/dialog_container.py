from functools import partial

from PySide6.QtWidgets import (
    QStackedWidget,
    QPushButton,
    QStackedLayout,
    QLabel,
    QGridLayout,
    QVBoxLayout,
    QDialog,
    )

from widget_helper import loadWidget, changeScreen

class TVSettingsDialog():
    def __init__(self):
        self = loadWidget("settings_dialog.ui")
        self.show()