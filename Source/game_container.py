from PySide6.QtWidgets import (
    QStackedWidget,
    QWidget,
    QLabel
    )

from widget_helper import loadWidget

class TVGameContainer(QStackedWidget):
    def __init__(self):
        super().__init__()
        label = QLabel("HI")
        self.addWidget(label)