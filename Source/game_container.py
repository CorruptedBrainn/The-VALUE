from functools import partial

from PySide6.QtWidgets import (
    QStackedWidget,
    QWidget,
    QPushButton,
    QStackedLayout,
    QLabel
    )

from widget_helper import loadWidget, changeScreen

class TVGameContainer(QStackedWidget):
    def __init__(self, parent):
        super().__init__()
        