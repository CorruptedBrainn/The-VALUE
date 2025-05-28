import sys
from functools import partial

from PySide6.QtWidgets import QApplication, QWidget, QMainWindow, QPushButton, QDialog, QDialogButtonBox, QFrame
from PySide6.QtUiTools import QUiLoader
from PySide6.QtCore import QFile, QIODeviceBase, Qt, Slot, Signal, QObject
from PySide6.QtGui import QAction

import filemanager as fm

'''
    A class to allow me to cleanly store filepaths
     for everything in the game in variables
    This enables me to keep filepaths central, in
     case I decide to change some file heirachies
'''
class filepathStorage():
    ui = "UI Widgets/"
    startup = ui + "Startup/"
    mainWindow = startup + "Main_WINDOW.ui"
    homePage = startup + "HOME_PAGE.ui"
    settings = ui + "Settings/"
    settingsDialog = settings + "Settings_DIALOG.ui"
    savefiles = ui + "Savefiles/"
    savePage = savefiles + "Saves_PAGE.ui"
    saveDialog = savefiles + "Saveinfo_DIALOG.ui"
    newsaveDialog = savefiles + "Newsave_DIALOG.ui"
    game = ui + "Game/"
    gamePage = game + "Game_PAGE.ui"
    techtree = ui + "Techtree/"
    techtreePage = techtree + "Techtree_PAGE.ui"
    journal = ui + "Journal/"
    journalDialog = journal + "Journal_DIALOG.ui"
    foeinfoPage = journal + "Foeinfo_PAGE.ui"
    documentationPage = journal + "Documentation_PAGE.ui"
    storylinePage = journal + "Storyline_PAGE.ui"
    fleets = ui + "Fleets/"
    fleetviewPage = fleets + "Fleetview_PAGE.ui"
    unitinfoDialog = fleets + "Unitinfo_DIALOG.ui"
    editor = ui + "Editor/"
    editorPage = editor + "Editor_PAGE.ui"

'''
    A class with functions to allow me to change
     the "page" that is viewed with clean functions
'''
class pageManager():
    loader = QUiLoader()
    filepath = filepathStorage()
    past = None

    '''
        Allows me to schedule deletion for a widget's children
    '''
    @Slot(QObject)
    def removeChildren(self, parent):
        arr = parent.children()
        for item in arr:
            item.deleteLater()
        return

    '''
        Load the main window and homepage on startup
    '''
    @Slot()
    def __init__(self):
        file = QFile(self.filepath.mainWindow)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.mainWindow:QMainWindow = self.loader.load(file) # type: ignore
        file.close()

        self.quitButton:QAction = self.mainWindow.findChild(QAction, "actionQuit") # type: ignore
        self.quitButton.triggered.connect(quitApp)

        self.homeButton:QAction = self.mainWindow.findChild(QAction, "actionMain_Menu") # type: ignore
        self.homeButton.triggered.connect(self.setupHome)

        self.settingsButton:QAction = self.mainWindow.findChild(QAction, "actionSettings") # type: ignore
        self.settingsButton.triggered.connect(self.loadSettings)

        self.loadSaveButton:QAction = self.mainWindow.findChild(QAction, "actionSave_1") # type: ignore
        self.loadSaveButton.triggered.connect(partial(self.savePopup, 1))

        self.loadSaveButton:QAction = self.mainWindow.findChild(QAction, "actionSave_2") # type: ignore
        self.loadSaveButton.triggered.connect(partial(self.savePopup, 2))

        self.loadSaveButton:QAction = self.mainWindow.findChild(QAction, "actionSave_3") # type: ignore
        self.loadSaveButton.triggered.connect(partial(self.savePopup, 3))

        self.mainWindow.setWindowState(Qt.WindowState.WindowFullScreen)
        self.setupHome()

        self.mainWindow.show()
        return

    '''
        Load the homepage
    '''
    @Slot()
    def setupHome(self):
        file = QFile(self.filepath.homePage)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.homePage = self.loader.load(file)
        file.close()

        self.startButton:QPushButton = self.homePage.findChild(QPushButton, "startButton") # type: ignore
        self.startButton.clicked.connect(self.loadSaveselection)

        self.homePage.move(self.mainWindow.centralWidget().pos())
        self.homePage.resize(self.mainWindow.centralWidget().size())
        self.mainWindow.setCentralWidget(self.homePage)
        self.past = partial(self.setupHome)
        return
    
    '''
        Load the settings popup
    '''
    @Slot()
    def loadSettings(self):
        file = QFile(self.filepath.settingsDialog)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.settingsDialog:QDialog = self.loader.load(file) # type: ignore
        file.close()

        self.settingsButtonBox:QDialogButtonBox = self.settingsDialog.findChild(QDialogButtonBox, "buttonBox") # type: ignore

        self.settingsDialog.finished.connect(fm.doSomething)

        self.settingsDialog.open()
        return

    '''
        Load the saveselection page
    '''
    @Slot()
    def loadSaveselection(self):
        file = QFile(self.filepath.savePage)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.savePage = self.loader.load(file)
        file.close()

        self.saveBackButton:QPushButton = self.savePage.findChild(QPushButton, "SaveBackButton") # type: ignore
        self.saveBackButton.clicked.connect(self.past)

        self.saveILoad:QPushButton = self.savePage.findChild(QPushButton, "LoadSaveButton_I") # type: ignore
        self.saveILoad.clicked.connect(partial(self.savePopup, 1))

        self.saveIILoad:QPushButton = self.savePage.findChild(QPushButton, "LoadSaveButton_II") # type: ignore
        self.saveIILoad.clicked.connect(partial(self.savePopup, 2))

        self.saveIIILoad:QPushButton = self.savePage.findChild(QPushButton, "LoadSaveButton_III") # type: ignore
        self.saveIIILoad.clicked.connect(partial(self.savePopup, 3))

        self.savePage.move(self.mainWindow.centralWidget().pos())
        self.savePage.resize(self.mainWindow.centralWidget().size())
        self.mainWindow.setCentralWidget(self.savePage)
        self.past = partial(self.loadSaveselection)
        return

    '''
        Load the save popup
    '''
    @Slot(int)
    def savePopup(self, fileidx):
        file = QFile(self.filepath.saveDialog)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.loadSaveDialog:QDialog = self.loader.load(file) # type: ignore
        file.close()

        self.loadSaveDialog.finished.connect(partial(self.showMain, fileidx))

        self.loadSaveDialog.open()
        return

    '''
        Load the main game
    '''
    @Slot(int, int)
    def showMain(self, fileidx, result):
        if result == 0: return

        file = QFile(self.filepath.gamePage)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.mainPage = self.loader.load(file)
        file.close()

        fm.loadSomething(fileidx)

        self.editorButton:QPushButton = self.mainPage.findChild(QPushButton, "EditorButton") # type: ignore
        self.editorButton.clicked.connect(self.showEditor)

        self.journalButton:QPushButton = self.mainPage.findChild(QPushButton, "JournalButton") # type: ignore
        self.journalButton.clicked.connect(self.journalPopup)

        self.fleetButton:QPushButton = self.mainPage.findChild(QPushButton, "FleetButton") # type: ignore
        self.fleetButton.clicked.connect(self.showFleet)

        self.techtreeButton:QPushButton = self.mainPage.findChild(QPushButton, "TechtreeButton") # type: ignore
        self.techtreeButton.clicked.connect(self.showTechtree)

        self.mainPage.move(self.mainWindow.centralWidget().pos())
        self.mainPage.resize(self.mainWindow.centralWidget().size())
        self.mainWindow.setCentralWidget(self.mainPage)
        self.past = partial(self.showMain, fileidx, 80)
        return

    '''
        Load the editor
    '''
    @Slot()
    def showEditor(self):
        file = QFile(self.filepath.editorPage)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.editorPage = self.loader.load(file)
        file.close()

        self.editorBackButton:QPushButton = self.editorPage.findChild(QPushButton, "BackButton") # type: ignore
        self.editorBackButton.clicked.connect(self.past)

        self.editorPage.move(self.mainWindow.centralWidget().pos())
        self.editorPage.resize(self.mainWindow.centralWidget().size())
        self.mainWindow.setCentralWidget(self.editorPage)
        self.past = partial(self.showEditor)
        return

    '''
        Load the journal
    '''
    @Slot()
    def journalPopup(self):
        file = QFile(self.filepath.journalDialog)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.journalDialog:QDialog = self.loader.load(file) # type: ignore
        file.close()

        self.journalContainer:QWidget = self.journalDialog.findChild(QWidget, "Container") # type: ignore

        self.showStoryline()

        self.documentationButton:QPushButton = self.journalDialog.findChild(QPushButton, "DocumentationButton") # type: ignore
        self.documentationButton.clicked.connect(self.showDocumentation)

        self.storylineButton:QPushButton = self.journalDialog.findChild(QPushButton, "StorylineButton") # type: ignore
        self.storylineButton.clicked.connect(self.showStoryline)

        self.foeinfoButton:QPushButton = self.journalDialog.findChild(QPushButton, "FoeinfoButton") # type: ignore
        self.foeinfoButton.clicked.connect(self.showFoeinfo)

        self.journalDialog.open()
        return

    '''
        Load the documentation page
    '''
    @Slot()
    def showDocumentation(self):
        file = QFile(self.filepath.documentationPage)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.documentationPage:QWidget = self.loader.load(file) # type: ignore
        file.close()

        self.removeChildren(self.journalContainer)
        self.documentationPage.setParent(self.journalContainer)
        self.documentationPage.move(self.journalContainer.pos())
        self.documentationPage.resize(self.journalContainer.size())
        self.documentationPage.show()
        return

    '''
        Load the storyline page
    '''
    @Slot()
    def showStoryline(self):
        file = QFile(self.filepath.storylinePage)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.storylinePage:QWidget = self.loader.load(file) # type: ignore
        file.close()

        self.removeChildren(self.journalContainer)
        self.storylinePage.setParent(self.journalContainer)
        self.storylinePage.move(self.journalContainer.pos())
        self.storylinePage.resize(self.journalContainer.size())
        self.storylinePage.show()
        return

    '''
        Load the foe info page
    '''
    @Slot()
    def showFoeinfo(self):
        file = QFile(self.filepath.foeinfoPage)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.foeinfoPage:QWidget = self.loader.load(file) # type: ignore
        file.close()

        self.removeChildren(self.journalContainer)
        self.foeinfoPage.setParent(self.journalContainer)
        self.foeinfoPage.move(self.journalContainer.pos())
        self.foeinfoPage.resize(self.journalContainer.size())
        self.foeinfoPage.show()
        return

    '''
        Load the fleetview page
    '''
    @Slot()
    def showFleet(self):
        file = QFile(self.filepath.fleetviewPage)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.fleetviewPage = self.loader.load(file)
        file.close()

        self.fleetviewBackButton:QPushButton = self.fleetviewPage.findChild(QPushButton, "BackButton") # type: ignore
        self.fleetviewBackButton.clicked.connect(self.past)

        self.temp:QPushButton = self.fleetviewPage.findChild(QPushButton, "pushButton") # type: ignore
        self.temp.clicked.connect(quit)

        self.fleetviewPage.move(self.mainWindow.centralWidget().pos())
        self.fleetviewPage.resize(self.mainWindow.centralWidget().size())
        self.mainWindow.setCentralWidget(self.fleetviewPage)
        self.past = partial(self.showFleet)
        return

    '''
        Show a unit dialog
    '''
    @Slot()
    def showUnit(self):
        file = QFile(self.filepath.unitinfoDialog)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.unitinfoDialog = self.loader.load(file)
        file.close()

        self.unitinfoDialog.show()
        return

    '''
        Load the tech tree
    '''
    @Slot()
    def showTechtree(self):
        file = QFile(self.filepath.techtreePage)
        file.open(QIODeviceBase.OpenModeFlag.ReadOnly)
        self.techtreePage = self.loader.load(file)
        file.close()

        self.techtreeBackButton:QPushButton = self.techtreePage.findChild(QPushButton, "BackButton") # type: ignore
        self.techtreeBackButton.clicked.connect(self.past)

        self.techtreePage.move(self.mainWindow.centralWidget().pos())
        self.techtreePage.resize(self.mainWindow.centralWidget().size())
        self.mainWindow.setCentralWidget(self.techtreePage)
        self.past = partial(self.showTechtree)
        return

def openApplication():
    app = QApplication(sys.argv)
    slave = pageManager()
    return app.exec()

@Slot()
def quitApp():
    return sys.exit(0)

def main():
    sys.exit(openApplication())

if __name__ == "__main__":
    main()