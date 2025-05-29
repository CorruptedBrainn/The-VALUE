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
        label1 = QLabel("HI1")
        label2 = QLabel("HI2")
        label3 = QLabel("HI3")
        self.addWidget(label1)
        self.addWidget(label2)
        self.addWidget(label3)