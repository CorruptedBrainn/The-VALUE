from PySide6.QtCore import QFile, QIODeviceBase, Slot
from PySide6.QtWidgets import QWidget, QStackedLayout, QStackedWidget, QDialog, QPushButton
from PySide6.QtUiTools import QUiLoader

import global_storage as gs

widgetPath = "Widgets/"

@Slot(str)
def loadWidget(filepath:str):
    file = QFile(widgetPath + filepath)
    loader = QUiLoader()
    file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
    ret:QWidget = loader.load(file)
    file.close()
    return ret

@Slot(QStackedLayout, int, int)
def changeScreen(mainLayout:QStackedLayout, rootIndex = 0, containerIndex = 0):
    mainLayout.setCurrentIndex(rootIndex)
    if mainLayout.currentWidget().inherits("QStackedWidget") == False:
        return
    container:QStackedWidget = mainLayout.currentWidget() # type: ignore
    container.setCurrentIndex(containerIndex)
    return

@Slot(QDialog)
def showDialog(dialog:QDialog):
    dialog.show()
    return

@Slot(QStackedLayout, QPushButton, str)
def changeMainScreen(layout:QStackedLayout, button:QPushButton, buttonIdx:str):
    if (gs.mainCurrentPage == 0): button.setText("The Expanse")
    if (gs.mainCurrentPage == 1): button.setText("Journal")
    if (gs.mainCurrentPage == 2): button.setText("Technology Tree")
    if (gs.mainCurrentPage == 3): button.setText("Fleet Control")
    if (buttonIdx == 'A'): gs.mainCurrentPage, gs.buttonA = gs.buttonA, gs.mainCurrentPage
    if (buttonIdx == 'B'): gs.mainCurrentPage, gs.buttonB = gs.buttonB, gs.mainCurrentPage
    if (buttonIdx == 'C'): gs.mainCurrentPage, gs.buttonC = gs.buttonC, gs.mainCurrentPage
    changeScreen(layout, gs.mainCurrentPage)
    return