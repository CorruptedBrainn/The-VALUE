from functools import partial

from PySide6.QtCore import (
    Qt,
    )
from PySide6.QtWidgets import (
    QStackedWidget,
    QPushButton,
    QDialogButtonBox,
    QDialog,
    )

from widget_helper import changeScreen
from file_helper import closeSettings, resetSettings, applySettings

class TVSettingsDialog(QDialog):
    def __new__(cls, obj):
        buttonBox:QDialogButtonBox = obj.findChild(QDialogButtonBox, "buttonBox") # type: ignore
        stack:QStackedWidget = obj.findChild(QStackedWidget, "stackedWidget") # type: ignore
        obj.setWindowModality(Qt.ApplicationModal)
        stack.setCurrentIndex(0)

        gameplayButton:QPushButton = obj.findChild(QPushButton, "gameplayButton") # type: ignore
        gameplayButton.clicked.connect(partial(changeScreen, stack, 1))

        audioButton:QPushButton = obj.findChild(QPushButton, "audioButton") # type: ignore
        audioButton.clicked.connect(partial(changeScreen, stack, 2))

        graphicsButton:QPushButton = obj.findChild(QPushButton, "graphicsButton") # type: ignore
        graphicsButton.clicked.connect(partial(changeScreen, stack, 3))

        obj.finished.connect(partial(changeScreen, stack, 0))
        back1:QPushButton = obj.findChild(QPushButton, "pushButton_4") # type: ignore
        back2:QPushButton = obj.findChild(QPushButton, "pushButton_5") # type: ignore
        back3:QPushButton = obj.findChild(QPushButton, "pushButton_6") # type: ignore
        back1.clicked.connect(partial(changeScreen, stack, 0))
        back2.clicked.connect(partial(changeScreen, stack, 0))
        back3.clicked.connect(partial(changeScreen, stack, 0))

        restoreDefaults:QPushButton = buttonBox.button(QDialogButtonBox.StandardButton.RestoreDefaults)
        apply:QPushButton = buttonBox.button(QDialogButtonBox.StandardButton.Apply)
        obj.finished.connect(partial(closeSettings))
        restoreDefaults.clicked.connect(partial(resetSettings))
        apply.clicked.connect(partial(applySettings))

        return obj