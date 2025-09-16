# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'settings_dialog.ui'
##
## Created by: Qt User Interface Compiler version 6.9.1
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QAbstractButton, QAbstractItemView, QApplication, QComboBox,
    QDialog, QDialogButtonBox, QFrame, QGridLayout,
    QLabel, QListView, QListWidget, QListWidgetItem,
    QPushButton, QSizePolicy, QSlider, QSpacerItem,
    QSpinBox, QStackedWidget, QVBoxLayout, QWidget)

class Ui_Settings(object):
    def setupUi(self, Settings):
        if not Settings.objectName():
            Settings.setObjectName(u"Settings")
        Settings.setWindowModality(Qt.WindowModality.ApplicationModal)
        Settings.resize(500, 600)
        Settings.setModal(True)
        self.verticalLayout = QVBoxLayout(Settings)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.stackedWidget = QStackedWidget(Settings)
        self.stackedWidget.setObjectName(u"stackedWidget")
        self.page = QWidget()
        self.page.setObjectName(u"page")
        self.gridLayout = QGridLayout(self.page)
        self.gridLayout.setObjectName(u"gridLayout")
        self.audioButton = QPushButton(self.page)
        self.audioButton.setObjectName(u"audioButton")
        sizePolicy = QSizePolicy(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.audioButton.sizePolicy().hasHeightForWidth())
        self.audioButton.setSizePolicy(sizePolicy)
        font = QFont()
        font.setPointSize(18)
        font.setBold(True)
        self.audioButton.setFont(font)

        self.gridLayout.addWidget(self.audioButton, 2, 1, 1, 1)

        self.horizontalSpacer = QSpacerItem(40, 20, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Minimum)

        self.gridLayout.addItem(self.horizontalSpacer, 2, 0, 1, 1)

        self.verticalSpacer_2 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.gridLayout.addItem(self.verticalSpacer_2, 4, 1, 1, 1)

        self.verticalSpacer = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.gridLayout.addItem(self.verticalSpacer, 0, 1, 1, 1)

        self.graphicsButton = QPushButton(self.page)
        self.graphicsButton.setObjectName(u"graphicsButton")
        sizePolicy.setHeightForWidth(self.graphicsButton.sizePolicy().hasHeightForWidth())
        self.graphicsButton.setSizePolicy(sizePolicy)
        self.graphicsButton.setFont(font)

        self.gridLayout.addWidget(self.graphicsButton, 3, 1, 1, 1)

        self.gameplayButton = QPushButton(self.page)
        self.gameplayButton.setObjectName(u"gameplayButton")
        sizePolicy.setHeightForWidth(self.gameplayButton.sizePolicy().hasHeightForWidth())
        self.gameplayButton.setSizePolicy(sizePolicy)
        self.gameplayButton.setFont(font)

        self.gridLayout.addWidget(self.gameplayButton, 1, 1, 1, 1)

        self.horizontalSpacer_2 = QSpacerItem(40, 20, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Minimum)

        self.gridLayout.addItem(self.horizontalSpacer_2, 2, 2, 1, 1)

        self.gridLayout.setRowStretch(0, 3)
        self.gridLayout.setRowStretch(1, 2)
        self.gridLayout.setRowStretch(2, 2)
        self.gridLayout.setRowStretch(3, 2)
        self.gridLayout.setRowStretch(4, 3)
        self.gridLayout.setColumnStretch(0, 1)
        self.gridLayout.setColumnStretch(1, 2)
        self.gridLayout.setColumnStretch(2, 1)
        self.stackedWidget.addWidget(self.page)
        self.page_2 = QWidget()
        self.page_2.setObjectName(u"page_2")
        self.verticalLayout_2 = QVBoxLayout(self.page_2)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.verticalSpacer_3 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.verticalLayout_2.addItem(self.verticalSpacer_3)

        self.label = QLabel(self.page_2)
        self.label.setObjectName(u"label")
        self.label.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_2.addWidget(self.label)

        self.frame = QFrame(self.page_2)
        self.frame.setObjectName(u"frame")
        self.frame.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame.setFrameShadow(QFrame.Shadow.Raised)
        self.gridLayout_2 = QGridLayout(self.frame)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.UnitDataComboBox = QComboBox(self.frame)
        self.UnitDataComboBox.addItem("")
        self.UnitDataComboBox.addItem("")
        self.UnitDataComboBox.addItem("")
        self.UnitDataComboBox.setObjectName(u"UnitDataComboBox")

        self.gridLayout_2.addWidget(self.UnitDataComboBox, 1, 2, 1, 1)

        self.label_2 = QLabel(self.frame)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)

        self.gridLayout_2.addWidget(self.label_2, 0, 0, 1, 1)

        self.DebuggingModeComboBox = QComboBox(self.frame)
        self.DebuggingModeComboBox.addItem("")
        self.DebuggingModeComboBox.addItem("")
        self.DebuggingModeComboBox.addItem("")
        self.DebuggingModeComboBox.setObjectName(u"DebuggingModeComboBox")

        self.gridLayout_2.addWidget(self.DebuggingModeComboBox, 0, 2, 1, 1)

        self.label_3 = QLabel(self.frame)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)

        self.gridLayout_2.addWidget(self.label_3, 1, 0, 1, 1)

        self.label_4 = QLabel(self.frame)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)

        self.gridLayout_2.addWidget(self.label_4, 2, 0, 1, 1)

        self.line_2 = QFrame(self.frame)
        self.line_2.setObjectName(u"line_2")
        self.line_2.setFrameShape(QFrame.Shape.VLine)
        self.line_2.setFrameShadow(QFrame.Shadow.Sunken)

        self.gridLayout_2.addWidget(self.line_2, 0, 1, 3, 1)

        self.FoeDataComboBox = QComboBox(self.frame)
        self.FoeDataComboBox.addItem("")
        self.FoeDataComboBox.addItem("")
        self.FoeDataComboBox.addItem("")
        self.FoeDataComboBox.setObjectName(u"FoeDataComboBox")

        self.gridLayout_2.addWidget(self.FoeDataComboBox, 2, 2, 1, 1)


        self.verticalLayout_2.addWidget(self.frame)

        self.verticalSpacer_4 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.verticalLayout_2.addItem(self.verticalSpacer_4)

        self.pushButton_6 = QPushButton(self.page_2)
        self.pushButton_6.setObjectName(u"pushButton_6")

        self.verticalLayout_2.addWidget(self.pushButton_6)

        self.verticalLayout_2.setStretch(0, 1)
        self.verticalLayout_2.setStretch(2, 1)
        self.verticalLayout_2.setStretch(3, 1)
        self.stackedWidget.addWidget(self.page_2)
        self.page_3 = QWidget()
        self.page_3.setObjectName(u"page_3")
        self.verticalLayout_3 = QVBoxLayout(self.page_3)
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.verticalSpacer_5 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.verticalLayout_3.addItem(self.verticalSpacer_5)

        self.label_5 = QLabel(self.page_3)
        self.label_5.setObjectName(u"label_5")
        self.label_5.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_3.addWidget(self.label_5)

        self.frame_2 = QFrame(self.page_3)
        self.frame_2.setObjectName(u"frame_2")
        self.frame_2.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame_2.setFrameShadow(QFrame.Shadow.Raised)
        self.gridLayout_3 = QGridLayout(self.frame_2)
        self.gridLayout_3.setObjectName(u"gridLayout_3")
        self.EffectsSlider = QSlider(self.frame_2)
        self.EffectsSlider.setObjectName(u"EffectsSlider")
        self.EffectsSlider.setMaximum(100)
        self.EffectsSlider.setValue(50)
        self.EffectsSlider.setOrientation(Qt.Orientation.Horizontal)

        self.gridLayout_3.addWidget(self.EffectsSlider, 1, 2, 1, 1)

        self.MusicSlider = QSlider(self.frame_2)
        self.MusicSlider.setObjectName(u"MusicSlider")
        self.MusicSlider.setMaximum(100)
        self.MusicSlider.setSliderPosition(50)
        self.MusicSlider.setOrientation(Qt.Orientation.Horizontal)

        self.gridLayout_3.addWidget(self.MusicSlider, 0, 2, 1, 1)

        self.label_8 = QLabel(self.frame_2)
        self.label_8.setObjectName(u"label_8")
        self.label_8.setAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)

        self.gridLayout_3.addWidget(self.label_8, 1, 0, 1, 1)

        self.line_3 = QFrame(self.frame_2)
        self.line_3.setObjectName(u"line_3")
        self.line_3.setFrameShape(QFrame.Shape.VLine)
        self.line_3.setFrameShadow(QFrame.Shadow.Sunken)

        self.gridLayout_3.addWidget(self.line_3, 0, 1, 3, 1)

        self.label_7 = QLabel(self.frame_2)
        self.label_7.setObjectName(u"label_7")
        self.label_7.setAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)

        self.gridLayout_3.addWidget(self.label_7, 0, 0, 1, 1)

        self.label_9 = QLabel(self.frame_2)
        self.label_9.setObjectName(u"label_9")
        self.label_9.setAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)

        self.gridLayout_3.addWidget(self.label_9, 2, 0, 1, 1)

        self.BackgroundSlider = QSlider(self.frame_2)
        self.BackgroundSlider.setObjectName(u"BackgroundSlider")
        self.BackgroundSlider.setMaximum(100)
        self.BackgroundSlider.setValue(50)
        self.BackgroundSlider.setOrientation(Qt.Orientation.Horizontal)

        self.gridLayout_3.addWidget(self.BackgroundSlider, 2, 2, 1, 1)

        self.MusicSpinBox = QSpinBox(self.frame_2)
        self.MusicSpinBox.setObjectName(u"MusicSpinBox")
        self.MusicSpinBox.setMaximum(100)
        self.MusicSpinBox.setValue(50)

        self.gridLayout_3.addWidget(self.MusicSpinBox, 0, 3, 1, 1)

        self.EffectsSpinBox = QSpinBox(self.frame_2)
        self.EffectsSpinBox.setObjectName(u"EffectsSpinBox")
        self.EffectsSpinBox.setMaximum(100)
        self.EffectsSpinBox.setValue(50)

        self.gridLayout_3.addWidget(self.EffectsSpinBox, 1, 3, 1, 1)

        self.BackgroundSpinBox = QSpinBox(self.frame_2)
        self.BackgroundSpinBox.setObjectName(u"BackgroundSpinBox")
        self.BackgroundSpinBox.setMaximum(100)
        self.BackgroundSpinBox.setValue(50)

        self.gridLayout_3.addWidget(self.BackgroundSpinBox, 2, 3, 1, 1)


        self.verticalLayout_3.addWidget(self.frame_2)

        self.line = QFrame(self.page_3)
        self.line.setObjectName(u"line")
        self.line.setFrameShape(QFrame.Shape.HLine)
        self.line.setFrameShadow(QFrame.Shadow.Sunken)

        self.verticalLayout_3.addWidget(self.line)

        self.label_6 = QLabel(self.page_3)
        self.label_6.setObjectName(u"label_6")
        self.label_6.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_3.addWidget(self.label_6)

        self.frame_3 = QFrame(self.page_3)
        self.frame_3.setObjectName(u"frame_3")
        self.frame_3.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame_3.setFrameShadow(QFrame.Shadow.Raised)
        self.verticalLayout_5 = QVBoxLayout(self.frame_3)
        self.verticalLayout_5.setObjectName(u"verticalLayout_5")
        self.label_10 = QLabel(self.frame_3)
        self.label_10.setObjectName(u"label_10")
        self.label_10.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_5.addWidget(self.label_10)

        self.GameMusicList = QListWidget(self.frame_3)
        __qlistwidgetitem = QListWidgetItem(self.GameMusicList)
        __qlistwidgetitem.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem1 = QListWidgetItem(self.GameMusicList)
        __qlistwidgetitem1.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem2 = QListWidgetItem(self.GameMusicList)
        __qlistwidgetitem2.setTextAlignment(Qt.AlignCenter);
        self.GameMusicList.setObjectName(u"GameMusicList")
        self.GameMusicList.setLayoutDirection(Qt.LayoutDirection.RightToLeft)
        self.GameMusicList.setFrameShape(QFrame.Shape.Box)
        self.GameMusicList.setEditTriggers(QAbstractItemView.EditTrigger.SelectedClicked)
        self.GameMusicList.setProperty(u"showDropIndicator", True)
        self.GameMusicList.setAlternatingRowColors(True)
        self.GameMusicList.setSelectionMode(QAbstractItemView.SelectionMode.MultiSelection)
        self.GameMusicList.setSelectionBehavior(QAbstractItemView.SelectionBehavior.SelectRows)
        self.GameMusicList.setResizeMode(QListView.ResizeMode.Fixed)
        self.GameMusicList.setViewMode(QListView.ViewMode.ListMode)
        self.GameMusicList.setModelColumn(0)
        self.GameMusicList.setUniformItemSizes(True)
        self.GameMusicList.setSelectionRectVisible(False)

        self.verticalLayout_5.addWidget(self.GameMusicList)

        self.label_11 = QLabel(self.frame_3)
        self.label_11.setObjectName(u"label_11")
        self.label_11.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_5.addWidget(self.label_11)

        self.SoundEffectsList = QListWidget(self.frame_3)
        __qlistwidgetitem3 = QListWidgetItem(self.SoundEffectsList)
        __qlistwidgetitem3.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem4 = QListWidgetItem(self.SoundEffectsList)
        __qlistwidgetitem4.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem5 = QListWidgetItem(self.SoundEffectsList)
        __qlistwidgetitem5.setTextAlignment(Qt.AlignCenter);
        self.SoundEffectsList.setObjectName(u"SoundEffectsList")
        self.SoundEffectsList.setLayoutDirection(Qt.LayoutDirection.RightToLeft)
        self.SoundEffectsList.setFrameShape(QFrame.Shape.Box)
        self.SoundEffectsList.setEditTriggers(QAbstractItemView.EditTrigger.SelectedClicked)
        self.SoundEffectsList.setProperty(u"showDropIndicator", True)
        self.SoundEffectsList.setAlternatingRowColors(True)
        self.SoundEffectsList.setSelectionMode(QAbstractItemView.SelectionMode.MultiSelection)
        self.SoundEffectsList.setSelectionBehavior(QAbstractItemView.SelectionBehavior.SelectRows)
        self.SoundEffectsList.setResizeMode(QListView.ResizeMode.Fixed)
        self.SoundEffectsList.setViewMode(QListView.ViewMode.ListMode)
        self.SoundEffectsList.setModelColumn(0)
        self.SoundEffectsList.setUniformItemSizes(True)
        self.SoundEffectsList.setSelectionRectVisible(False)

        self.verticalLayout_5.addWidget(self.SoundEffectsList)

        self.label_12 = QLabel(self.frame_3)
        self.label_12.setObjectName(u"label_12")
        self.label_12.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_5.addWidget(self.label_12)

        self.AmbientList = QListWidget(self.frame_3)
        __qlistwidgetitem6 = QListWidgetItem(self.AmbientList)
        __qlistwidgetitem6.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem7 = QListWidgetItem(self.AmbientList)
        __qlistwidgetitem7.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem8 = QListWidgetItem(self.AmbientList)
        __qlistwidgetitem8.setTextAlignment(Qt.AlignCenter);
        self.AmbientList.setObjectName(u"AmbientList")
        self.AmbientList.setLayoutDirection(Qt.LayoutDirection.RightToLeft)
        self.AmbientList.setFrameShape(QFrame.Shape.Box)
        self.AmbientList.setEditTriggers(QAbstractItemView.EditTrigger.SelectedClicked)
        self.AmbientList.setProperty(u"showDropIndicator", True)
        self.AmbientList.setAlternatingRowColors(True)
        self.AmbientList.setSelectionMode(QAbstractItemView.SelectionMode.MultiSelection)
        self.AmbientList.setSelectionBehavior(QAbstractItemView.SelectionBehavior.SelectRows)
        self.AmbientList.setResizeMode(QListView.ResizeMode.Fixed)
        self.AmbientList.setViewMode(QListView.ViewMode.ListMode)
        self.AmbientList.setModelColumn(0)
        self.AmbientList.setUniformItemSizes(True)
        self.AmbientList.setSelectionRectVisible(False)

        self.verticalLayout_5.addWidget(self.AmbientList)

        self.verticalLayout_5.setStretch(1, 1)
        self.verticalLayout_5.setStretch(3, 1)
        self.verticalLayout_5.setStretch(5, 1)

        self.verticalLayout_3.addWidget(self.frame_3)

        self.verticalSpacer_6 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.verticalLayout_3.addItem(self.verticalSpacer_6)

        self.pushButton_5 = QPushButton(self.page_3)
        self.pushButton_5.setObjectName(u"pushButton_5")

        self.verticalLayout_3.addWidget(self.pushButton_5)

        self.verticalLayout_3.setStretch(0, 1)
        self.verticalLayout_3.setStretch(2, 1)
        self.verticalLayout_3.setStretch(5, 1)
        self.verticalLayout_3.setStretch(6, 1)
        self.stackedWidget.addWidget(self.page_3)
        self.page_4 = QWidget()
        self.page_4.setObjectName(u"page_4")
        self.verticalLayout_4 = QVBoxLayout(self.page_4)
        self.verticalLayout_4.setObjectName(u"verticalLayout_4")
        self.verticalSpacer_7 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.verticalLayout_4.addItem(self.verticalSpacer_7)

        self.label_13 = QLabel(self.page_4)
        self.label_13.setObjectName(u"label_13")
        self.label_13.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_4.addWidget(self.label_13)

        self.frame_4 = QFrame(self.page_4)
        self.frame_4.setObjectName(u"frame_4")
        self.frame_4.setFrameShape(QFrame.Shape.StyledPanel)
        self.frame_4.setFrameShadow(QFrame.Shadow.Raised)
        self.verticalLayout_6 = QVBoxLayout(self.frame_4)
        self.verticalLayout_6.setObjectName(u"verticalLayout_6")
        self.label_14 = QLabel(self.frame_4)
        self.label_14.setObjectName(u"label_14")
        self.label_14.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_6.addWidget(self.label_14)

        self.InterfaceThemeList = QListWidget(self.frame_4)
        __qlistwidgetitem9 = QListWidgetItem(self.InterfaceThemeList)
        __qlistwidgetitem9.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem10 = QListWidgetItem(self.InterfaceThemeList)
        __qlistwidgetitem10.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem11 = QListWidgetItem(self.InterfaceThemeList)
        __qlistwidgetitem11.setTextAlignment(Qt.AlignCenter);
        self.InterfaceThemeList.setObjectName(u"InterfaceThemeList")
        self.InterfaceThemeList.setAlternatingRowColors(True)

        self.verticalLayout_6.addWidget(self.InterfaceThemeList)

        self.label_15 = QLabel(self.frame_4)
        self.label_15.setObjectName(u"label_15")
        self.label_15.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_6.addWidget(self.label_15)

        self.UnitThemeList = QListWidget(self.frame_4)
        __qlistwidgetitem12 = QListWidgetItem(self.UnitThemeList)
        __qlistwidgetitem12.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem13 = QListWidgetItem(self.UnitThemeList)
        __qlistwidgetitem13.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem14 = QListWidgetItem(self.UnitThemeList)
        __qlistwidgetitem14.setTextAlignment(Qt.AlignCenter);
        self.UnitThemeList.setObjectName(u"UnitThemeList")
        self.UnitThemeList.setAlternatingRowColors(True)

        self.verticalLayout_6.addWidget(self.UnitThemeList)

        self.label_16 = QLabel(self.frame_4)
        self.label_16.setObjectName(u"label_16")
        self.label_16.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.verticalLayout_6.addWidget(self.label_16)

        self.EnvironmentThemeList = QListWidget(self.frame_4)
        __qlistwidgetitem15 = QListWidgetItem(self.EnvironmentThemeList)
        __qlistwidgetitem15.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem16 = QListWidgetItem(self.EnvironmentThemeList)
        __qlistwidgetitem16.setTextAlignment(Qt.AlignCenter);
        __qlistwidgetitem17 = QListWidgetItem(self.EnvironmentThemeList)
        __qlistwidgetitem17.setTextAlignment(Qt.AlignCenter);
        self.EnvironmentThemeList.setObjectName(u"EnvironmentThemeList")
        self.EnvironmentThemeList.setAlternatingRowColors(True)

        self.verticalLayout_6.addWidget(self.EnvironmentThemeList)

        self.verticalLayout_6.setStretch(1, 1)
        self.verticalLayout_6.setStretch(3, 1)
        self.verticalLayout_6.setStretch(5, 1)

        self.verticalLayout_4.addWidget(self.frame_4)

        self.verticalSpacer_8 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)

        self.verticalLayout_4.addItem(self.verticalSpacer_8)

        self.pushButton_4 = QPushButton(self.page_4)
        self.pushButton_4.setObjectName(u"pushButton_4")

        self.verticalLayout_4.addWidget(self.pushButton_4)

        self.verticalLayout_4.setStretch(0, 1)
        self.verticalLayout_4.setStretch(2, 1)
        self.verticalLayout_4.setStretch(3, 1)
        self.stackedWidget.addWidget(self.page_4)

        self.verticalLayout.addWidget(self.stackedWidget)

        self.buttonBox = QDialogButtonBox(Settings)
        self.buttonBox.setObjectName(u"buttonBox")
        self.buttonBox.setStandardButtons(QDialogButtonBox.StandardButton.Apply|QDialogButtonBox.StandardButton.Cancel|QDialogButtonBox.StandardButton.RestoreDefaults|QDialogButtonBox.StandardButton.Save)
        self.buttonBox.setCenterButtons(True)

        self.verticalLayout.addWidget(self.buttonBox)


        self.retranslateUi(Settings)
        self.buttonBox.accepted.connect(Settings.accept)
        self.buttonBox.rejected.connect(Settings.reject)
        self.MusicSlider.valueChanged.connect(self.MusicSpinBox.setValue)
        self.MusicSpinBox.valueChanged.connect(self.MusicSlider.setValue)
        self.EffectsSpinBox.valueChanged.connect(self.EffectsSlider.setValue)
        self.EffectsSlider.valueChanged.connect(self.EffectsSpinBox.setValue)
        self.BackgroundSlider.valueChanged.connect(self.BackgroundSpinBox.setValue)
        self.BackgroundSpinBox.valueChanged.connect(self.BackgroundSlider.setValue)

        self.stackedWidget.setCurrentIndex(0)
        self.GameMusicList.setCurrentRow(0)
        self.SoundEffectsList.setCurrentRow(0)
        self.AmbientList.setCurrentRow(0)
        self.InterfaceThemeList.setCurrentRow(0)
        self.UnitThemeList.setCurrentRow(0)
        self.EnvironmentThemeList.setCurrentRow(0)


        QMetaObject.connectSlotsByName(Settings)
    # setupUi

    def retranslateUi(self, Settings):
        Settings.setWindowTitle(QCoreApplication.translate("Settings", u"Dialog", None))
        self.audioButton.setText(QCoreApplication.translate("Settings", u"Audio Options", None))
        self.graphicsButton.setText(QCoreApplication.translate("Settings", u"Graphical Options", None))
        self.gameplayButton.setText(QCoreApplication.translate("Settings", u"Gameplay Options", None))
        self.label.setText(QCoreApplication.translate("Settings", u"Information Utilities", None))
        self.UnitDataComboBox.setItemText(0, QCoreApplication.translate("Settings", u"None", None))
        self.UnitDataComboBox.setItemText(1, QCoreApplication.translate("Settings", u"Less Information", None))
        self.UnitDataComboBox.setItemText(2, QCoreApplication.translate("Settings", u"More Information", None))

        self.label_2.setText(QCoreApplication.translate("Settings", u"Debugging Mode:", None))
        self.DebuggingModeComboBox.setItemText(0, QCoreApplication.translate("Settings", u"None", None))
        self.DebuggingModeComboBox.setItemText(1, QCoreApplication.translate("Settings", u"Basic", None))
        self.DebuggingModeComboBox.setItemText(2, QCoreApplication.translate("Settings", u"Advanced", None))

        self.label_3.setText(QCoreApplication.translate("Settings", u"Unit Data Displays:", None))
        self.label_4.setText(QCoreApplication.translate("Settings", u"Foe Data Displays:", None))
        self.FoeDataComboBox.setItemText(0, QCoreApplication.translate("Settings", u"None", None))
        self.FoeDataComboBox.setItemText(1, QCoreApplication.translate("Settings", u"Less Information", None))
        self.FoeDataComboBox.setItemText(2, QCoreApplication.translate("Settings", u"More Information", None))

        self.pushButton_6.setText(QCoreApplication.translate("Settings", u"Back", None))
        self.label_5.setText(QCoreApplication.translate("Settings", u"Volume Settings", None))
        self.label_8.setText(QCoreApplication.translate("Settings", u"Effects:", None))
        self.label_7.setText(QCoreApplication.translate("Settings", u"Music:", None))
        self.label_9.setText(QCoreApplication.translate("Settings", u"Background:", None))
        self.label_6.setText(QCoreApplication.translate("Settings", u"Sound Packs", None))
        self.label_10.setText(QCoreApplication.translate("Settings", u"Game Music", None))

        __sortingEnabled = self.GameMusicList.isSortingEnabled()
        self.GameMusicList.setSortingEnabled(False)
        ___qlistwidgetitem = self.GameMusicList.item(0)
        ___qlistwidgetitem.setText(QCoreApplication.translate("Settings", u"Pack Name 1", None));
        ___qlistwidgetitem1 = self.GameMusicList.item(1)
        ___qlistwidgetitem1.setText(QCoreApplication.translate("Settings", u"Pack Name 2", None));
        ___qlistwidgetitem2 = self.GameMusicList.item(2)
        ___qlistwidgetitem2.setText(QCoreApplication.translate("Settings", u"Pack Name 3", None));
        self.GameMusicList.setSortingEnabled(__sortingEnabled)

        self.label_11.setText(QCoreApplication.translate("Settings", u"Sound Effects", None))

        __sortingEnabled1 = self.SoundEffectsList.isSortingEnabled()
        self.SoundEffectsList.setSortingEnabled(False)
        ___qlistwidgetitem3 = self.SoundEffectsList.item(0)
        ___qlistwidgetitem3.setText(QCoreApplication.translate("Settings", u"Pack Name 1", None));
        ___qlistwidgetitem4 = self.SoundEffectsList.item(1)
        ___qlistwidgetitem4.setText(QCoreApplication.translate("Settings", u"Pack Name 2", None));
        ___qlistwidgetitem5 = self.SoundEffectsList.item(2)
        ___qlistwidgetitem5.setText(QCoreApplication.translate("Settings", u"Pack Name 3", None));
        self.SoundEffectsList.setSortingEnabled(__sortingEnabled1)

        self.label_12.setText(QCoreApplication.translate("Settings", u"Ambient Music", None))

        __sortingEnabled2 = self.AmbientList.isSortingEnabled()
        self.AmbientList.setSortingEnabled(False)
        ___qlistwidgetitem6 = self.AmbientList.item(0)
        ___qlistwidgetitem6.setText(QCoreApplication.translate("Settings", u"Pack Name 1", None));
        ___qlistwidgetitem7 = self.AmbientList.item(1)
        ___qlistwidgetitem7.setText(QCoreApplication.translate("Settings", u"Pack Name 2", None));
        ___qlistwidgetitem8 = self.AmbientList.item(2)
        ___qlistwidgetitem8.setText(QCoreApplication.translate("Settings", u"Pack Name 3", None));
        self.AmbientList.setSortingEnabled(__sortingEnabled2)

        self.pushButton_5.setText(QCoreApplication.translate("Settings", u"Back", None))
        self.label_13.setText(QCoreApplication.translate("Settings", u"Themes", None))
        self.label_14.setText(QCoreApplication.translate("Settings", u"Interface Theme", None))

        __sortingEnabled3 = self.InterfaceThemeList.isSortingEnabled()
        self.InterfaceThemeList.setSortingEnabled(False)
        ___qlistwidgetitem9 = self.InterfaceThemeList.item(0)
        ___qlistwidgetitem9.setText(QCoreApplication.translate("Settings", u"Theme Name 1", None));
        ___qlistwidgetitem10 = self.InterfaceThemeList.item(1)
        ___qlistwidgetitem10.setText(QCoreApplication.translate("Settings", u"Theme Name 2", None));
        ___qlistwidgetitem11 = self.InterfaceThemeList.item(2)
        ___qlistwidgetitem11.setText(QCoreApplication.translate("Settings", u"Theme Name 3", None));
        self.InterfaceThemeList.setSortingEnabled(__sortingEnabled3)

        self.label_15.setText(QCoreApplication.translate("Settings", u"Unit Theme", None))

        __sortingEnabled4 = self.UnitThemeList.isSortingEnabled()
        self.UnitThemeList.setSortingEnabled(False)
        ___qlistwidgetitem12 = self.UnitThemeList.item(0)
        ___qlistwidgetitem12.setText(QCoreApplication.translate("Settings", u"Theme Name 1", None));
        ___qlistwidgetitem13 = self.UnitThemeList.item(1)
        ___qlistwidgetitem13.setText(QCoreApplication.translate("Settings", u"Theme Name 2", None));
        ___qlistwidgetitem14 = self.UnitThemeList.item(2)
        ___qlistwidgetitem14.setText(QCoreApplication.translate("Settings", u"Theme Name 3", None));
        self.UnitThemeList.setSortingEnabled(__sortingEnabled4)

        self.label_16.setText(QCoreApplication.translate("Settings", u"Environment Theme", None))

        __sortingEnabled5 = self.EnvironmentThemeList.isSortingEnabled()
        self.EnvironmentThemeList.setSortingEnabled(False)
        ___qlistwidgetitem15 = self.EnvironmentThemeList.item(0)
        ___qlistwidgetitem15.setText(QCoreApplication.translate("Settings", u"Theme Name 1", None));
        ___qlistwidgetitem16 = self.EnvironmentThemeList.item(1)
        ___qlistwidgetitem16.setText(QCoreApplication.translate("Settings", u"Theme Name 2", None));
        ___qlistwidgetitem17 = self.EnvironmentThemeList.item(2)
        ___qlistwidgetitem17.setText(QCoreApplication.translate("Settings", u"Theme Name 3", None));
        self.EnvironmentThemeList.setSortingEnabled(__sortingEnabled5)

        self.pushButton_4.setText(QCoreApplication.translate("Settings", u"Back", None))
    # retranslateUi

