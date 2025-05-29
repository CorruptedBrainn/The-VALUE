from PySide6.QtCore import QFile, QIODeviceBase, Slot
from PySide6.QtWidgets import QWidget, QStackedLayout, QStackedWidget
from PySide6.QtUiTools import QUiLoader

widgetPath = "Widgets/"

@Slot(str)
def loadWidget(filepath:str):
    file = QFile(widgetPath + filepath)
    loader = QUiLoader()
    file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
    ret:QWidget = loader.load(file)
    file.close()
    return ret

@Slot(QStackedLayout, int, int, int)
def changeScreen(mainLayout:QStackedLayout, rootIndex = 0, containerIndex = 0):
    mainLayout.setCurrentIndex(rootIndex)
    if mainLayout.currentWidget().inherits("QStackedWidget") == False:
        return
    container:QStackedWidget = mainLayout.currentWidget() # type: ignore
    container.setCurrentIndex(containerIndex)
    return