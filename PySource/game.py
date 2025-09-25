"""
Name: game.py
Version: 0.0.4-alpha
Description: Manage my file reading and game data storage
Author: Nicolas Martens
"""

from functools import partial
from datetime import datetime

from PySide6.QtCore import (
	Slot,
	QObject,
	QTimer,
	QPointF,
	)
from PySide6.QtWidgets import (
	QStackedWidget,
	QGraphicsScene,
	QApplication,
	QGraphicsPixmapItem,
	QGraphicsView,
	)
from PySide6.QtGui import (
	QColor,
	QPen,
	QRadialGradient,
	QGradient,
	QBrush,
	QPixmap,
	)

from interface import TVApplication
from data import DataPackage

class GameScene(QGraphicsScene):
	def __init__(self, app:TVApplication):
		super().__init__()
		self.app = app
		self.package = app.package

		self.setBackgroundBrush(QColor.fromHsv(0, 0, 255))
		worldBorder = QPen()
		worldBorder.setWidth(1000)
		worldBorderGradient = QRadialGradient(0, 0, 1000)
		worldBorderGradient.setColorAt(0, QColor.fromHsv(0, 0, 0))
		worldBorderGradient.setColorAt(1, QColor.fromHsv(0, 0, 255))
		worldBorderGradient.setSpread(QGradient.Spread.ReflectSpread)
		worldBorder.setBrush(QBrush(worldBorderGradient))
		self.addEllipse(-50540, -50540, 101080, 101080, worldBorder, QBrush(QColor.fromHsv(0, 0, 0)))

		return

class GameObject:
	def __init__(self, app:TVApplication):
		self.app = app
		self.package = app.package
		self.scene:GameScene = None
		self.view:QGraphicsView = app.interface.graphicsView_2

		self.app.gameLoaded.connect(partial(self.startGame))
		self.app.gamePaused.connect(partial(self.pauseGame))
		self.app.gameStopped.connect(partial(self.stopGame))

		return

	@Slot()
	def startGame(self)->None:
		self.scene = GameScene(self.app)
		self.view.setScene(self.scene)

		return

	@Slot()
	def pauseGame(self)->None:
		pass

	@Slot()
	def stopGame(self)->None:
		pass