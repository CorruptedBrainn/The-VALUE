from PySide6.QtCore import QFile, QIODeviceBase
from PySide6.QtWidgets import QWidget
from PySide6.QtUiTools import QUiLoader

widgetPath = "Widgets/"

def loadWidget(filepath: str):
    file = QFile(widgetPath + filepath)
    loader = QUiLoader()
    file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
    ret:QWidget = loader.load(file)
    file.close()
    return ret