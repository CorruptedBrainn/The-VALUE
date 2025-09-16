# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'interface.ui'
##
## Created by: Qt User Interface Compiler version 6.9.1
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QAction, QBrush, QColor, QConicalGradient,
    QCursor, QFont, QFontDatabase, QGradient,
    QIcon, QImage, QKeySequence, QLinearGradient,
    QPainter, QPalette, QPixmap, QRadialGradient,
    QTransform)
from PySide6.QtWidgets import (QApplication, QFormLayout, QFrame, QGraphicsView,
    QGridLayout, QHBoxLayout, QLabel, QLayout,
    QListView, QMainWindow, QMenu, QMenuBar,
    QPushButton, QScrollArea, QSizePolicy, QSpacerItem,
    QStackedWidget, QStatusBar, QTabWidget, QTextEdit,
    QVBoxLayout, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(1920, 1080)
        palette = QPalette()
        brush = QBrush(QColor(255, 255, 255, 255))
        brush.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.WindowText, brush)
        brush1 = QBrush(QColor(0, 85, 127, 255))
        brush1.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Button, brush1)
        brush2 = QBrush(QColor(0, 128, 190, 255))
        brush2.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Light, brush2)
        brush3 = QBrush(QColor(0, 106, 158, 255))
        brush3.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Midlight, brush3)
        brush4 = QBrush(QColor(0, 43, 63, 255))
        brush4.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Dark, brush4)
        brush5 = QBrush(QColor(0, 57, 85, 255))
        brush5.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Mid, brush5)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Text, brush)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.BrightText, brush)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.ButtonText, brush)
        brush6 = QBrush(QColor(0, 0, 0, 255))
        brush6.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Base, brush6)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Window, brush1)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Shadow, brush6)
        brush7 = QBrush(QColor(0, 125, 127, 255))
        brush7.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Highlight, brush7)
        brush8 = QBrush(QColor(0, 42, 63, 255))
        brush8.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.AlternateBase, brush8)
        brush9 = QBrush(QColor(255, 255, 220, 255))
        brush9.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.ToolTipBase, brush9)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.ToolTipText, brush6)
        brush10 = QBrush(QColor(255, 255, 255, 127))
        brush10.setStyle(Qt.BrushStyle.SolidPattern)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.PlaceholderText, brush10)
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Accent, brush6)
#endif
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.WindowText, brush)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Button, brush1)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Light, brush2)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Midlight, brush3)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Dark, brush4)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Mid, brush5)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Text, brush)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.BrightText, brush)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.ButtonText, brush)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Base, brush6)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Window, brush1)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Shadow, brush6)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Highlight, brush7)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.AlternateBase, brush8)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.ToolTipBase, brush9)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.ToolTipText, brush6)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.PlaceholderText, brush10)
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Accent, brush6)
#endif
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.WindowText, brush4)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Button, brush1)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Light, brush2)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Midlight, brush3)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Dark, brush4)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Mid, brush5)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Text, brush4)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.BrightText, brush)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.ButtonText, brush4)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Base, brush1)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Window, brush1)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Shadow, brush6)
        brush11 = QBrush(QColor(0, 124, 126, 255))
        brush11.setStyle(Qt.BrushStyle.SolidPattern)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Highlight, brush11)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.AlternateBase, brush1)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.ToolTipBase, brush9)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.ToolTipText, brush6)
        brush12 = QBrush(QColor(0, 43, 63, 127))
        brush12.setStyle(Qt.BrushStyle.SolidPattern)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.PlaceholderText, brush12)
#endif
        brush13 = QBrush(QColor(0, 60, 89, 255))
        brush13.setStyle(Qt.BrushStyle.SolidPattern)
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Accent, brush13)
#endif
        MainWindow.setPalette(palette)
        font = QFont()
        font.setFamilies([u"Bauhaus 93"])
        MainWindow.setFont(font)
        self.actionHome = QAction(MainWindow)
        self.actionHome.setObjectName(u"actionHome")
        self.actionLoadGame = QAction(MainWindow)
        self.actionLoadGame.setObjectName(u"actionLoadGame")
        self.actionLoadGame.setCheckable(False)
        self.actionSaveGame = QAction(MainWindow)
        self.actionSaveGame.setObjectName(u"actionSaveGame")
        self.actionOptions = QAction(MainWindow)
        self.actionOptions.setObjectName(u"actionOptions")
        self.actionQuit = QAction(MainWindow)
        self.actionQuit.setObjectName(u"actionQuit")
        self.actionQuit.setMenuRole(QAction.MenuRole.TextHeuristicRole)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.verticalLayout = QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(9, 9, 9, 9)
        self.screenManager = QStackedWidget(self.centralwidget)
        self.screenManager.setObjectName(u"screenManager")
        self.welcome = QWidget()
        self.welcome.setObjectName(u"welcome")
        self.gridLayout = QGridLayout(self.welcome)
        self.gridLayout.setObjectName(u"gridLayout")
        self.label = QLabel(self.welcome)
        self.label.setObjectName(u"label")
        font1 = QFont()
        font1.setFamilies([u"Bauhaus 93"])
        font1.setPointSize(90)
        font1.setBold(True)
        self.label.setFont(font1)
        self.label.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.gridLayout.addWidget(self.label, 1, 1, 1, 1)

        self.playGame = QPushButton(self.welcome)
        self.playGame.setObjectName(u"playGame")
        font2 = QFont()
        font2.setFamilies([u"Bauhaus 93"])
        font2.setPointSize(40)
        font2.setBold(False)
        font2.setUnderline(False)
        self.playGame.setFont(font2)
        self.playGame.setAutoDefault(False)
        self.playGame.setFlat(False)

        self.gridLayout.addWidget(self.playGame, 2, 1, 1, 1)

        self.horizontalSpacer_2 = QSpacerItem(40, 20, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Minimum)

        self.gridLayout.addItem(self.horizontalSpacer_2, 1, 2, 1, 1)

        self.verticalSpacer = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.gridLayout.addItem(self.verticalSpacer, 3, 1, 1, 1)

        self.horizontalSpacer = QSpacerItem(40, 20, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Minimum)

        self.gridLayout.addItem(self.horizontalSpacer, 1, 0, 1, 1)

        self.verticalSpacer_2 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.gridLayout.addItem(self.verticalSpacer_2, 0, 1, 1, 1)

        self.screenManager.addWidget(self.welcome)
        self.save = QWidget()
        self.save.setObjectName(u"save")
        self.horizontalLayout = QHBoxLayout(self.save)
        self.horizontalLayout.setSpacing(12)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.saveSlots = QScrollArea(self.save)
        self.saveSlots.setObjectName(u"saveSlots")
        self.saveSlots.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        self.saveSlots.setWidgetResizable(True)
        self.saveSlots.setAlignment(Qt.AlignmentFlag.AlignHCenter|Qt.AlignmentFlag.AlignTop)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollAreaWidgetContents.setObjectName(u"scrollAreaWidgetContents")
        self.scrollAreaWidgetContents.setGeometry(QRect(0, 0, 1132, 1008))
        self.verticalLayout_9 = QVBoxLayout(self.scrollAreaWidgetContents)
        self.verticalLayout_9.setObjectName(u"verticalLayout_9")
        self.verticalLayout_9.setSizeConstraint(QLayout.SizeConstraint.SetDefaultConstraint)
        self.saveSlots.setWidget(self.scrollAreaWidgetContents)

        self.horizontalLayout.addWidget(self.saveSlots)

        self.gridLayout_2 = QGridLayout()
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.verticalSpacer_3 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.gridLayout_2.addItem(self.verticalSpacer_3, 2, 1, 1, 1)

        self.horizontalSpacer_4 = QSpacerItem(40, 20, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Minimum)

        self.gridLayout_2.addItem(self.horizontalSpacer_4, 1, 2, 1, 1)

        self.horizontalSpacer_3 = QSpacerItem(40, 20, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Minimum)

        self.gridLayout_2.addItem(self.horizontalSpacer_3, 1, 0, 1, 1)

        self.frame = QFrame(self.save)
        self.frame.setObjectName(u"frame")
        font3 = QFont()
        font3.setFamilies([u"Bauhaus 93"])
        font3.setPointSize(10)
        self.frame.setFont(font3)
        self.frame.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame.setFrameShadow(QFrame.Shadow.Raised)
        self.verticalLayout_2 = QVBoxLayout(self.frame)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.saveName = QLabel(self.frame)
        self.saveName.setObjectName(u"saveName")
        font4 = QFont()
        font4.setFamilies([u"Bauhaus 93"])
        font4.setPointSize(27)
        font4.setBold(True)
        self.saveName.setFont(font4)
        self.saveName.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_2.addWidget(self.saveName)

        self.saveNumber = QLabel(self.frame)
        self.saveNumber.setObjectName(u"saveNumber")
        font5 = QFont()
        font5.setFamilies([u"Bauhaus 93"])
        font5.setPointSize(15)
        self.saveNumber.setFont(font5)
        self.saveNumber.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_2.addWidget(self.saveNumber)

        self.line_5 = QFrame(self.frame)
        self.line_5.setObjectName(u"line_5")
        self.line_5.setFrameShape(QFrame.Shape.HLine)
        self.line_5.setFrameShadow(QFrame.Shadow.Sunken)

        self.verticalLayout_2.addWidget(self.line_5)

        self.verticalSpacer_5 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.verticalLayout_2.addItem(self.verticalSpacer_5)

        self.saveIcon = QGraphicsView(self.frame)
        self.saveIcon.setObjectName(u"saveIcon")

        self.verticalLayout_2.addWidget(self.saveIcon)

        self.verticalSpacer_7 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.verticalLayout_2.addItem(self.verticalSpacer_7)

        self.line = QFrame(self.frame)
        self.line.setObjectName(u"line")
        self.line.setFrameShape(QFrame.Shape.HLine)
        self.line.setFrameShadow(QFrame.Shadow.Sunken)

        self.verticalLayout_2.addWidget(self.line)

        self.formLayout_2 = QFormLayout()
        self.formLayout_2.setObjectName(u"formLayout_2")
        self.formLayout_2.setLabelAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)
        self.formLayout_2.setContentsMargins(64, -1, 64, -1)
        self.label_3 = QLabel(self.frame)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setAlignment(Qt.AlignmentFlag.AlignLeading|Qt.AlignmentFlag.AlignLeft|Qt.AlignmentFlag.AlignVCenter)

        self.formLayout_2.setWidget(0, QFormLayout.ItemRole.LabelRole, self.label_3)

        self.characterName = QLabel(self.frame)
        self.characterName.setObjectName(u"characterName")

        self.formLayout_2.setWidget(0, QFormLayout.ItemRole.FieldRole, self.characterName)

        self.label_5 = QLabel(self.frame)
        self.label_5.setObjectName(u"label_5")
        self.label_5.setLayoutDirection(Qt.LayoutDirection.LeftToRight)
        self.label_5.setAlignment(Qt.AlignmentFlag.AlignLeading|Qt.AlignmentFlag.AlignLeft|Qt.AlignmentFlag.AlignVCenter)

        self.formLayout_2.setWidget(1, QFormLayout.ItemRole.LabelRole, self.label_5)

        self.characterDifficulty = QLabel(self.frame)
        self.characterDifficulty.setObjectName(u"characterDifficulty")

        self.formLayout_2.setWidget(1, QFormLayout.ItemRole.FieldRole, self.characterDifficulty)

        self.label_12 = QLabel(self.frame)
        self.label_12.setObjectName(u"label_12")

        self.formLayout_2.setWidget(2, QFormLayout.ItemRole.LabelRole, self.label_12)

        self.characterLastPlayed = QLabel(self.frame)
        self.characterLastPlayed.setObjectName(u"characterLastPlayed")

        self.formLayout_2.setWidget(2, QFormLayout.ItemRole.FieldRole, self.characterLastPlayed)

        self.line_6 = QFrame(self.frame)
        self.line_6.setObjectName(u"line_6")
        self.line_6.setFrameShape(QFrame.Shape.HLine)
        self.line_6.setFrameShadow(QFrame.Shadow.Sunken)

        self.formLayout_2.setWidget(3, QFormLayout.ItemRole.SpanningRole, self.line_6)

        self.label_6 = QLabel(self.frame)
        self.label_6.setObjectName(u"label_6")

        self.formLayout_2.setWidget(4, QFormLayout.ItemRole.LabelRole, self.label_6)

        self.characterAge = QLabel(self.frame)
        self.characterAge.setObjectName(u"characterAge")

        self.formLayout_2.setWidget(4, QFormLayout.ItemRole.FieldRole, self.characterAge)

        self.label_7 = QLabel(self.frame)
        self.label_7.setObjectName(u"label_7")

        self.formLayout_2.setWidget(5, QFormLayout.ItemRole.LabelRole, self.label_7)

        self.characterAchievements = QLabel(self.frame)
        self.characterAchievements.setObjectName(u"characterAchievements")

        self.formLayout_2.setWidget(5, QFormLayout.ItemRole.FieldRole, self.characterAchievements)

        self.label_8 = QLabel(self.frame)
        self.label_8.setObjectName(u"label_8")

        self.formLayout_2.setWidget(6, QFormLayout.ItemRole.LabelRole, self.label_8)

        self.characterTechnologies = QLabel(self.frame)
        self.characterTechnologies.setObjectName(u"characterTechnologies")

        self.formLayout_2.setWidget(6, QFormLayout.ItemRole.FieldRole, self.characterTechnologies)

        self.label_19 = QLabel(self.frame)
        self.label_19.setObjectName(u"label_19")

        self.formLayout_2.setWidget(8, QFormLayout.ItemRole.LabelRole, self.label_19)

        self.characterUnits = QLabel(self.frame)
        self.characterUnits.setObjectName(u"characterUnits")

        self.formLayout_2.setWidget(8, QFormLayout.ItemRole.FieldRole, self.characterUnits)

        self.label_20 = QLabel(self.frame)
        self.label_20.setObjectName(u"label_20")

        self.formLayout_2.setWidget(9, QFormLayout.ItemRole.LabelRole, self.label_20)

        self.characterKills = QLabel(self.frame)
        self.characterKills.setObjectName(u"characterKills")

        self.formLayout_2.setWidget(9, QFormLayout.ItemRole.FieldRole, self.characterKills)

        self.label_16 = QLabel(self.frame)
        self.label_16.setObjectName(u"label_16")

        self.formLayout_2.setWidget(11, QFormLayout.ItemRole.LabelRole, self.label_16)

        self.characterScrap = QLabel(self.frame)
        self.characterScrap.setObjectName(u"characterScrap")

        self.formLayout_2.setWidget(11, QFormLayout.ItemRole.FieldRole, self.characterScrap)

        self.label_17 = QLabel(self.frame)
        self.label_17.setObjectName(u"label_17")

        self.formLayout_2.setWidget(12, QFormLayout.ItemRole.LabelRole, self.label_17)

        self.characterPrecious = QLabel(self.frame)
        self.characterPrecious.setObjectName(u"characterPrecious")

        self.formLayout_2.setWidget(12, QFormLayout.ItemRole.FieldRole, self.characterPrecious)

        self.label_18 = QLabel(self.frame)
        self.label_18.setObjectName(u"label_18")

        self.formLayout_2.setWidget(13, QFormLayout.ItemRole.LabelRole, self.label_18)

        self.characterPlasma = QLabel(self.frame)
        self.characterPlasma.setObjectName(u"characterPlasma")

        self.formLayout_2.setWidget(13, QFormLayout.ItemRole.FieldRole, self.characterPlasma)

        self.line_7 = QFrame(self.frame)
        self.line_7.setObjectName(u"line_7")
        self.line_7.setFrameShape(QFrame.Shape.HLine)
        self.line_7.setFrameShadow(QFrame.Shadow.Sunken)

        self.formLayout_2.setWidget(7, QFormLayout.ItemRole.SpanningRole, self.line_7)

        self.line_8 = QFrame(self.frame)
        self.line_8.setObjectName(u"line_8")
        self.line_8.setFrameShape(QFrame.Shape.HLine)
        self.line_8.setFrameShadow(QFrame.Shadow.Sunken)

        self.formLayout_2.setWidget(10, QFormLayout.ItemRole.SpanningRole, self.line_8)


        self.verticalLayout_2.addLayout(self.formLayout_2)

        self.line_2 = QFrame(self.frame)
        self.line_2.setObjectName(u"line_2")
        self.line_2.setFrameShape(QFrame.Shape.HLine)
        self.line_2.setFrameShadow(QFrame.Shadow.Sunken)

        self.verticalLayout_2.addWidget(self.line_2)

        self.verticalSpacer_6 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.verticalLayout_2.addItem(self.verticalSpacer_6)

        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.startGameButton = QPushButton(self.frame)
        self.startGameButton.setObjectName(u"startGameButton")

        self.horizontalLayout_2.addWidget(self.startGameButton)

        self.deleteGameButton = QPushButton(self.frame)
        self.deleteGameButton.setObjectName(u"deleteGameButton")
        self.deleteGameButton.setEnabled(False)

        self.horizontalLayout_2.addWidget(self.deleteGameButton)


        self.verticalLayout_2.addLayout(self.horizontalLayout_2)


        self.gridLayout_2.addWidget(self.frame, 1, 1, 1, 1)

        self.verticalSpacer_4 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.gridLayout_2.addItem(self.verticalSpacer_4, 0, 1, 1, 1)

        self.gridLayout_2.setRowStretch(0, 1)
        self.gridLayout_2.setRowStretch(1, 30)
        self.gridLayout_2.setRowStretch(2, 1)
        self.gridLayout_2.setColumnStretch(0, 2)
        self.gridLayout_2.setColumnStretch(1, 15)
        self.gridLayout_2.setColumnStretch(2, 2)

        self.horizontalLayout.addLayout(self.gridLayout_2)

        self.horizontalLayout.setStretch(0, 3)
        self.horizontalLayout.setStretch(1, 2)
        self.screenManager.addWidget(self.save)
        self.game = QWidget()
        self.game.setObjectName(u"game")
        self.horizontalLayout_3 = QHBoxLayout(self.game)
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.horizontalLayout_3.setContentsMargins(0, 0, 0, 0)
        self.frame_2 = QFrame(self.game)
        self.frame_2.setObjectName(u"frame_2")
        self.frame_2.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame_2.setFrameShadow(QFrame.Shadow.Raised)
        self.verticalLayout_4 = QVBoxLayout(self.frame_2)
        self.verticalLayout_4.setObjectName(u"verticalLayout_4")
        self.label_10 = QLabel(self.frame_2)
        self.label_10.setObjectName(u"label_10")
        font6 = QFont()
        font6.setFamilies([u"Bauhaus 93"])
        font6.setPointSize(22)
        font6.setBold(True)
        self.label_10.setFont(font6)
        self.label_10.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_4.addWidget(self.label_10)

        self.formLayout = QFormLayout()
        self.formLayout.setObjectName(u"formLayout")
        self.formLayout.setLabelAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)
        self.label_2 = QLabel(self.frame_2)
        self.label_2.setObjectName(u"label_2")

        self.formLayout.setWidget(0, QFormLayout.ItemRole.LabelRole, self.label_2)

        self.gameName = QLabel(self.frame_2)
        self.gameName.setObjectName(u"gameName")

        self.formLayout.setWidget(0, QFormLayout.ItemRole.FieldRole, self.gameName)

        self.label_11 = QLabel(self.frame_2)
        self.label_11.setObjectName(u"label_11")

        self.formLayout.setWidget(1, QFormLayout.ItemRole.LabelRole, self.label_11)

        self.label_13 = QLabel(self.frame_2)
        self.label_13.setObjectName(u"label_13")

        self.formLayout.setWidget(2, QFormLayout.ItemRole.LabelRole, self.label_13)

        self.label_14 = QLabel(self.frame_2)
        self.label_14.setObjectName(u"label_14")

        self.formLayout.setWidget(3, QFormLayout.ItemRole.LabelRole, self.label_14)

        self.label_15 = QLabel(self.frame_2)
        self.label_15.setObjectName(u"label_15")

        self.formLayout.setWidget(4, QFormLayout.ItemRole.LabelRole, self.label_15)

        self.gameDifficulty = QLabel(self.frame_2)
        self.gameDifficulty.setObjectName(u"gameDifficulty")

        self.formLayout.setWidget(1, QFormLayout.ItemRole.FieldRole, self.gameDifficulty)

        self.gameAge = QLabel(self.frame_2)
        self.gameAge.setObjectName(u"gameAge")

        self.formLayout.setWidget(2, QFormLayout.ItemRole.FieldRole, self.gameAge)

        self.gameScrap = QLabel(self.frame_2)
        self.gameScrap.setObjectName(u"gameScrap")

        self.formLayout.setWidget(3, QFormLayout.ItemRole.FieldRole, self.gameScrap)

        self.gamePrecious = QLabel(self.frame_2)
        self.gamePrecious.setObjectName(u"gamePrecious")

        self.formLayout.setWidget(4, QFormLayout.ItemRole.FieldRole, self.gamePrecious)

        self.label_25 = QLabel(self.frame_2)
        self.label_25.setObjectName(u"label_25")

        self.formLayout.setWidget(5, QFormLayout.ItemRole.LabelRole, self.label_25)

        self.gamePlasma = QLabel(self.frame_2)
        self.gamePlasma.setObjectName(u"gamePlasma")

        self.formLayout.setWidget(5, QFormLayout.ItemRole.FieldRole, self.gamePlasma)


        self.verticalLayout_4.addLayout(self.formLayout)

        self.line_4 = QFrame(self.frame_2)
        self.line_4.setObjectName(u"line_4")
        self.line_4.setFrameShape(QFrame.Shape.HLine)
        self.line_4.setFrameShadow(QFrame.Shadow.Sunken)

        self.verticalLayout_4.addWidget(self.line_4)

        self.label_4 = QLabel(self.frame_2)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setFont(font6)
        self.label_4.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_4.addWidget(self.label_4)

        self.controlButtonA = QPushButton(self.frame_2)
        self.controlButtonA.setObjectName(u"controlButtonA")

        self.verticalLayout_4.addWidget(self.controlButtonA)

        self.controlButtonB = QPushButton(self.frame_2)
        self.controlButtonB.setObjectName(u"controlButtonB")

        self.verticalLayout_4.addWidget(self.controlButtonB)

        self.controlButtonC = QPushButton(self.frame_2)
        self.controlButtonC.setObjectName(u"controlButtonC")

        self.verticalLayout_4.addWidget(self.controlButtonC)

        self.line_9 = QFrame(self.frame_2)
        self.line_9.setObjectName(u"line_9")
        self.line_9.setFrameShape(QFrame.Shape.HLine)
        self.line_9.setFrameShadow(QFrame.Shadow.Sunken)

        self.verticalLayout_4.addWidget(self.line_9)

        self.currentlySelected = QLabel(self.frame_2)
        self.currentlySelected.setObjectName(u"currentlySelected")
        self.currentlySelected.setFont(font6)
        self.currentlySelected.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_4.addWidget(self.currentlySelected)

        self.selectedImage = QGraphicsView(self.frame_2)
        self.selectedImage.setObjectName(u"selectedImage")

        self.verticalLayout_4.addWidget(self.selectedImage)

        self.selectedInfo = QFormLayout()
        self.selectedInfo.setObjectName(u"selectedInfo")

        self.verticalLayout_4.addLayout(self.selectedInfo)


        self.horizontalLayout_3.addWidget(self.frame_2)

        self.stackedWidget_2 = QStackedWidget(self.game)
        self.stackedWidget_2.setObjectName(u"stackedWidget_2")
        self.expanse = QWidget()
        self.expanse.setObjectName(u"expanse")
        self.verticalLayout_5 = QVBoxLayout(self.expanse)
        self.verticalLayout_5.setObjectName(u"verticalLayout_5")
        self.graphicsView_2 = QGraphicsView(self.expanse)
        self.graphicsView_2.setObjectName(u"graphicsView_2")

        self.verticalLayout_5.addWidget(self.graphicsView_2)

        self.stackedWidget_2.addWidget(self.expanse)
        self.technology = QWidget()
        self.technology.setObjectName(u"technology")
        self.verticalLayout_6 = QVBoxLayout(self.technology)
        self.verticalLayout_6.setObjectName(u"verticalLayout_6")
        self.graphicsView_3 = QGraphicsView(self.technology)
        self.graphicsView_3.setObjectName(u"graphicsView_3")

        self.verticalLayout_6.addWidget(self.graphicsView_3)

        self.stackedWidget_2.addWidget(self.technology)
        self.journal = QWidget()
        self.journal.setObjectName(u"journal")
        self.verticalLayout_7 = QVBoxLayout(self.journal)
        self.verticalLayout_7.setObjectName(u"verticalLayout_7")
        self.tabWidget = QTabWidget(self.journal)
        self.tabWidget.setObjectName(u"tabWidget")
        font7 = QFont()
        font7.setFamilies([u"Bauhaus 93"])
        font7.setPointSize(12)
        self.tabWidget.setFont(font7)
        self.tabWidget.setTabPosition(QTabWidget.TabPosition.West)
        self.storyline = QWidget()
        self.storyline.setObjectName(u"storyline")
        self.tabWidget.addTab(self.storyline, "")
        self.encyclopedia = QWidget()
        self.encyclopedia.setObjectName(u"encyclopedia")
        self.tabWidget.addTab(self.encyclopedia, "")
        self.documentation = QWidget()
        self.documentation.setObjectName(u"documentation")
        self.tabWidget.addTab(self.documentation, "")
        self.achievements = QWidget()
        self.achievements.setObjectName(u"achievements")
        self.tabWidget.addTab(self.achievements, "")

        self.verticalLayout_7.addWidget(self.tabWidget)

        self.stackedWidget_2.addWidget(self.journal)
        self.console = QWidget()
        self.console.setObjectName(u"console")
        self.verticalLayout_8 = QVBoxLayout(self.console)
        self.verticalLayout_8.setObjectName(u"verticalLayout_8")
        self.textEdit = QTextEdit(self.console)
        self.textEdit.setObjectName(u"textEdit")

        self.verticalLayout_8.addWidget(self.textEdit)

        self.stackedWidget_2.addWidget(self.console)

        self.horizontalLayout_3.addWidget(self.stackedWidget_2)

        self.frame_3 = QFrame(self.game)
        self.frame_3.setObjectName(u"frame_3")
        self.frame_3.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame_3.setFrameShadow(QFrame.Shadow.Raised)
        self.verticalLayout_3 = QVBoxLayout(self.frame_3)
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.label_9 = QLabel(self.frame_3)
        self.label_9.setObjectName(u"label_9")
        self.label_9.setFont(font6)
        self.label_9.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_3.addWidget(self.label_9)

        self.line_3 = QFrame(self.frame_3)
        self.line_3.setObjectName(u"line_3")
        self.line_3.setFrameShape(QFrame.Shape.HLine)
        self.line_3.setFrameShadow(QFrame.Shadow.Sunken)

        self.verticalLayout_3.addWidget(self.line_3)

        self.listView_2 = QListView(self.frame_3)
        self.listView_2.setObjectName(u"listView_2")

        self.verticalLayout_3.addWidget(self.listView_2)


        self.horizontalLayout_3.addWidget(self.frame_3)

        self.horizontalLayout_3.setStretch(0, 2)
        self.horizontalLayout_3.setStretch(1, 10)
        self.horizontalLayout_3.setStretch(2, 3)
        self.screenManager.addWidget(self.game)
        self.editor = QWidget()
        self.editor.setObjectName(u"editor")
        self.screenManager.addWidget(self.editor)

        self.verticalLayout.addWidget(self.screenManager)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 1920, 33))
        sizePolicy = QSizePolicy(QSizePolicy.Policy.MinimumExpanding, QSizePolicy.Policy.MinimumExpanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.menubar.sizePolicy().hasHeightForWidth())
        self.menubar.setSizePolicy(sizePolicy)
        font8 = QFont()
        font8.setFamilies([u"Bauhaus 93"])
        font8.setPointSize(9)
        font8.setBold(False)
        self.menubar.setFont(font8)
        self.menubar.setLayoutDirection(Qt.LayoutDirection.RightToLeft)
        self.menubar.setAutoFillBackground(False)
        self.menubar.setDefaultUp(False)
        self.menubar.setNativeMenuBar(True)
        self.menuMainMenu = QMenu(self.menubar)
        self.menuMainMenu.setObjectName(u"menuMainMenu")
        palette1 = QPalette()
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.WindowText, brush)
        brush14 = QBrush(QColor(0, 0, 0, 0))
        brush14.setStyle(Qt.BrushStyle.SolidPattern)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Button, brush14)
        brush15 = QBrush(QColor(18, 35, 106, 255))
        brush15.setStyle(Qt.BrushStyle.SolidPattern)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Light, brush15)
        brush16 = QBrush(QColor(15, 29, 88, 255))
        brush16.setStyle(Qt.BrushStyle.SolidPattern)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Midlight, brush16)
        brush17 = QBrush(QColor(6, 12, 35, 255))
        brush17.setStyle(Qt.BrushStyle.SolidPattern)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Dark, brush17)
        brush18 = QBrush(QColor(8, 15, 47, 255))
        brush18.setStyle(Qt.BrushStyle.SolidPattern)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Mid, brush18)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Text, brush)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.BrightText, brush)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.ButtonText, brush)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Base, brush6)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Window, brush14)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Shadow, brush6)
        brush19 = QBrush(QColor(57, 86, 86, 255))
        brush19.setStyle(Qt.BrushStyle.SolidPattern)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Highlight, brush19)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.HighlightedText, brush)
        brush20 = QBrush(QColor(6, 11, 35, 255))
        brush20.setStyle(Qt.BrushStyle.SolidPattern)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.AlternateBase, brush20)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.ToolTipBase, brush9)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.ToolTipText, brush6)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.PlaceholderText, brush10)
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette.ColorGroup.Active, QPalette.ColorRole.Accent, brush6)
#endif
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.WindowText, brush)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Button, brush14)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Light, brush15)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Midlight, brush16)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Dark, brush17)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Mid, brush18)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Text, brush)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.BrightText, brush)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.ButtonText, brush)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Base, brush6)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Window, brush14)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Shadow, brush6)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Highlight, brush19)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.AlternateBase, brush20)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.ToolTipBase, brush9)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.ToolTipText, brush6)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.PlaceholderText, brush10)
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette.ColorGroup.Inactive, QPalette.ColorRole.Accent, brush6)
#endif
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.WindowText, brush17)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Button, brush14)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Light, brush15)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Midlight, brush16)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Dark, brush17)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Mid, brush18)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Text, brush17)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.BrightText, brush)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.ButtonText, brush17)
        brush21 = QBrush(QColor(12, 23, 71, 255))
        brush21.setStyle(Qt.BrushStyle.SolidPattern)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Base, brush21)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Window, brush14)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Shadow, brush6)
        brush22 = QBrush(QColor(57, 86, 86, 100))
        brush22.setStyle(Qt.BrushStyle.SolidPattern)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Highlight, brush22)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.AlternateBase, brush21)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.ToolTipBase, brush9)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.ToolTipText, brush6)
        brush23 = QBrush(QColor(6, 12, 35, 127))
        brush23.setStyle(Qt.BrushStyle.SolidPattern)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.PlaceholderText, brush23)
#endif
        brush24 = QBrush(QColor(8, 16, 50, 255))
        brush24.setStyle(Qt.BrushStyle.SolidPattern)
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Accent, brush24)
#endif
        self.menuMainMenu.setPalette(palette1)
        font9 = QFont()
        font9.setFamilies([u"Bauhaus 93"])
        font9.setPointSize(12)
        font9.setBold(False)
        self.menuMainMenu.setFont(font9)
        MainWindow.setMenuBar(self.menubar)
        self.statusBar = QStatusBar(MainWindow)
        self.statusBar.setObjectName(u"statusBar")
        self.statusBar.setSizeGripEnabled(False)
        MainWindow.setStatusBar(self.statusBar)

        self.menubar.addAction(self.menuMainMenu.menuAction())
        self.menuMainMenu.addAction(self.actionHome)
        self.menuMainMenu.addAction(self.actionLoadGame)
        self.menuMainMenu.addAction(self.actionSaveGame)
        self.menuMainMenu.addSeparator()
        self.menuMainMenu.addAction(self.actionOptions)
        self.menuMainMenu.addAction(self.actionQuit)

        self.retranslateUi(MainWindow)

        self.screenManager.setCurrentIndex(1)
        self.playGame.setDefault(False)
        self.tabWidget.setCurrentIndex(1)

    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.actionHome.setText(QCoreApplication.translate("MainWindow", u"Home", None))
        self.actionLoadGame.setText(QCoreApplication.translate("MainWindow", u"Load Game", None))
        self.actionSaveGame.setText(QCoreApplication.translate("MainWindow", u"Save Game", None))
        self.actionOptions.setText(QCoreApplication.translate("MainWindow", u"Options", None))
        self.actionQuit.setText(QCoreApplication.translate("MainWindow", u"Quit", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"The VALUE", None))
        self.playGame.setText(QCoreApplication.translate("MainWindow", u"Play Game", None))
#if QT_CONFIG(shortcut)
        self.playGame.setShortcut(QCoreApplication.translate("MainWindow", u"Return", None))
#endif // QT_CONFIG(shortcut)
        self.saveName.setText(QCoreApplication.translate("MainWindow", u"Create New Save", None))
        self.saveNumber.setText(QCoreApplication.translate("MainWindow", u"Save 0", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"Character Name", None))
        self.characterName.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_5.setText(QCoreApplication.translate("MainWindow", u"Game Difficulty:", None))
        self.characterDifficulty.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_12.setText(QCoreApplication.translate("MainWindow", u"Last Played:", None))
        self.characterLastPlayed.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_6.setText(QCoreApplication.translate("MainWindow", u"Age:", None))
        self.characterAge.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_7.setText(QCoreApplication.translate("MainWindow", u"Achievements Obtained:", None))
        self.characterAchievements.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_8.setText(QCoreApplication.translate("MainWindow", u"Technologies Unlocked:", None))
        self.characterTechnologies.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_19.setText(QCoreApplication.translate("MainWindow", u"Units:", None))
        self.characterUnits.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_20.setText(QCoreApplication.translate("MainWindow", u"Kills:", None))
        self.characterKills.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_16.setText(QCoreApplication.translate("MainWindow", u"Scrap Metals:", None))
        self.characterScrap.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_17.setText(QCoreApplication.translate("MainWindow", u"Precious Metals:", None))
        self.characterPrecious.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_18.setText(QCoreApplication.translate("MainWindow", u"Plasma:", None))
        self.characterPlasma.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.startGameButton.setText(QCoreApplication.translate("MainWindow", u"Create Save", None))
        self.deleteGameButton.setText(QCoreApplication.translate("MainWindow", u"Delete Save", None))
        self.label_10.setText(QCoreApplication.translate("MainWindow", u"Information", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"Character Name:", None))
        self.gameName.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_11.setText(QCoreApplication.translate("MainWindow", u"Game Difficulty:", None))
        self.label_13.setText(QCoreApplication.translate("MainWindow", u"Age:", None))
        self.label_14.setText(QCoreApplication.translate("MainWindow", u"Scrap Metals:", None))
        self.label_15.setText(QCoreApplication.translate("MainWindow", u"Precious Metals:", None))
        self.gameDifficulty.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.gameAge.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.gameScrap.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.gamePrecious.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_25.setText(QCoreApplication.translate("MainWindow", u"Plasma:", None))
        self.gamePlasma.setText(QCoreApplication.translate("MainWindow", u"TextLabel", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"Navigation", None))
        self.controlButtonA.setText(QCoreApplication.translate("MainWindow", u"Journal", None))
        self.controlButtonB.setText(QCoreApplication.translate("MainWindow", u"Technology Tree", None))
        self.controlButtonC.setText(QCoreApplication.translate("MainWindow", u"Console Output", None))
        self.currentlySelected.setText(QCoreApplication.translate("MainWindow", u"Selected", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.storyline), QCoreApplication.translate("MainWindow", u"Storyline", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.encyclopedia), QCoreApplication.translate("MainWindow", u"Encyclopedia", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.documentation), QCoreApplication.translate("MainWindow", u"Valuescript Reference", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.achievements), QCoreApplication.translate("MainWindow", u"Achivements", None))
        self.label_9.setText(QCoreApplication.translate("MainWindow", u"Units", None))
        self.menuMainMenu.setTitle(QCoreApplication.translate("MainWindow", u"Main Menu", None))
    # retranslateUi

