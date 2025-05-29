from PySide6.QtWidgets import (
    QStackedWidget,
    QWidget,
    QLabel
    )

from widget_helper import loadWidget

class TVHomeContainer(QStackedWidget):
    def __init__(self):
        super().__init__()
        label = loadWidget("home_page.ui")
        self.addWidget(label)