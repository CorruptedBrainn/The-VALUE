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

class TVSettingsDialog(QDialog):
    def __init__(self):
        dialog:QDialog = loadWidget("settings_dialog.ui")
        dialogLayout = dialog.find