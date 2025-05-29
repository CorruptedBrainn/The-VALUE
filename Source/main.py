import sys

from PySide6.QtCore import (
    Slot,
    Signal
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

from home_container import TVHomeContainer
from widget_helper import loadWidget

widgetPath = "Widget/"

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window:QMainWindow = loadWidget(widgetPath + "main_window.ui") # type: ignore
    homeContainer = TVHomeContainer()
    # Create other container
    window.setCentralWidget(homeContainer)
    window.show()
    sys.exit(app.exec())