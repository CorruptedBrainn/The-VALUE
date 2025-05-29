from PySide6.QtCore import QFile, QIODeviceBase
from PySide6.QtWidgets import QWidget
from PySide6.QtUiTools import QUiLoader

def loadWidget(filepath: str):
    file = QFile(filepath)
    loader = QUiLoader()
    file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
    ret:QWidget = loader.load(file)
    file.close()
    return ret