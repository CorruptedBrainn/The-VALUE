from functools import partial

from PySide6.QtWidgets import (
    QStackedWidget,
    QWidget,
    QPushButton,
    QStackedLayout,
    QVBoxLayout,
    )

from widget_helper import loadWidget, changeScreen, changeMainScreen
import global_storage as gs

class TVGameContainer(QStackedWidget):
    def __init__(self, parent:QStackedLayout):
        super().__init__()
        page0 = loadWidget("main_game.ui")
        page1 = loadWidget("editor.ui")
        self.addWidget(page0)
        self.addWidget(page1)

        page0Layout:QVBoxLayout = page0.layout()
        mainGameLayout:QStackedWidget = QStackedWidget()
        theExpanse:QWidget = loadWidget("the_expanse.ui")
        theJournal:QWidget = loadWidget("journal.ui")
        theTechTree:QWidget = loadWidget("tech_tree.ui")
        theFleetControl:QWidget = loadWidget("fleet_control.ui")
        mainGameLayout.addWidget(theExpanse)
        mainGameLayout.addWidget(theJournal)
        mainGameLayout.addWidget(theTechTree)
        mainGameLayout.addWidget(theFleetControl)
        page0Layout.addWidget(mainGameLayout)
        page0Layout.setStretch(1, 6)

        ButtonA:QPushButton = page0.findChild(QPushButton, "GenericButton1") # type: ignore
        ButtonB:QPushButton = page0.findChild(QPushButton, "GenericButton2") # type: ignore
        ButtonC:QPushButton = page0.findChild(QPushButton, "GenericButton3") # type: ignore
        buttonList = [ButtonA, ButtonB, ButtonC]
        ButtonA.clicked.connect(partial(changeMainScreen, mainGameLayout, buttonList, 0))
        ButtonB.clicked.connect(partial(changeMainScreen, mainGameLayout, buttonList, 1))
        ButtonC.clicked.connect(partial(changeMainScreen, mainGameLayout, buttonList, 2))

        editorButton:QPushButton = theFleetControl.findChild(QPushButton, "EditorButton") # type: ignore
        editorButton.clicked.connect(partial(changeScreen, parent, 1, 1))

        mainExpanseButton:QPushButton = page1.findChild(QPushButton, "BackButton") # type: ignore
        mainExpanseButton.clicked.connect(partial(changeScreen, parent, 1, 0))