"""
Name: game_container.py
Version: 0.0.3-alpha
Description: This file holds the class that wraps around the main game page
Author: Nicolas Martens
"""

from random import randint
import threading
from functools import partial

from PySide6.QtCore import ( # type: ignore
	Slot,
	QPointF,
	QThreadPool,
	QRunnable,
	QTimer,
	)
from PySide6.QtWidgets import ( # type: ignore
	QStackedWidget,
	QWidget,
	QPushButton,
	QStackedLayout,
	QVBoxLayout,
	QTextEdit,
	QGraphicsView,
	QGraphicsScene,
	QGraphicsPixmapItem,
	QGraphicsPolygonItem,
	QGraphicsEllipseItem,
	)
from PySide6.QtGui import ( # type: ignore
	QBrush,
	QPen,
	QPolygonF,
	QColor,
	QGradient,
	QRadialGradient,
	QPixmap,
	)

from widget_helper import (
	loadWidget,
	changeScreen,
	changeMainScreen,
	)
from file_helper import (
	createUnit,
	)
import unit_classes
import global_storage as gs
from valuescript_wrapper import VSProgramObject

class runtime(QRunnable):
	def __init__(self, fn):
		super().__init__()
		self.fn = fn

	@Slot()
	def run(self):
		return self.fn()

class gameScene(QGraphicsScene):
	def __init__(self):
		super().__init__()
		self.timer = QTimer(self)
		self.timer.timeout.connect(self.collisionChecker)
		self.timer.start(400)

	@Slot()
	def collisionChecker(self):
		items = self.items()
		for obj in items:
			if type(obj) == QGraphicsEllipseItem or type(obj) == QGraphicsPolygonItem: continue
			collisions = obj.collidingItems()
			for collide in collisions:
				if type(collide) == QGraphicsEllipseItem: continue
				print("\n-----COLLISION REPORT-----")
				print(obj)
				print("WITH")
				print(collide)
				print("--------------------------\n")

# The main game container class
class TVGameContainer(QStackedWidget):
	# The object to store my programs in
	programs = VSProgramObject()
	gameState = threading.Event()
	varAccess = threading.Lock()
	threads = list()
	gameVariables = dict()

	# Initialising...
	def __init__(self, parent:QStackedLayout):
		# Get some inherited data and load the two main pages (code editor and expanse)
		super().__init__()
		page0 = loadWidget("main_game.ui")
		page1 = loadWidget("editor.ui")
		self.addWidget(page0)
		self.addWidget(page1)

		self.programs.add("main", gs.defaultScript)

		# Load the child page structure / heirachy
		page0Layout:QVBoxLayout = page0.layout()
		mainGameLayout:QStackedWidget = QStackedWidget()
		self.theExpanse:QWidget = loadWidget("the_expanse.ui")
		theJournal:QWidget = loadWidget("journal.ui")
		theTechTree:QWidget = loadWidget("tech_tree.ui")
		theFleetControl:QWidget = loadWidget("fleet_control.ui")
		mainGameLayout.addWidget(self.theExpanse)
		mainGameLayout.addWidget(theJournal)
		mainGameLayout.addWidget(theTechTree)
		mainGameLayout.addWidget(theFleetControl)
		page0Layout.addWidget(mainGameLayout)
		page0Layout.setStretch(1, 6)
		mainGameLayout.currentChanged.connect(partial(self.changeState))

		# Load the main button navigation settings
		ButtonA:QPushButton = page0.findChild(QPushButton, "GenericButton1") # type: ignore
		ButtonB:QPushButton = page0.findChild(QPushButton, "GenericButton2") # type: ignore
		ButtonC:QPushButton = page0.findChild(QPushButton, "GenericButton3") # type: ignore
		buttonList = [ButtonA, ButtonB, ButtonC]
		ButtonA.clicked.connect(partial(changeMainScreen, mainGameLayout, buttonList, 0))
		ButtonB.clicked.connect(partial(changeMainScreen, mainGameLayout, buttonList, 1))
		ButtonC.clicked.connect(partial(changeMainScreen, mainGameLayout, buttonList, 2))

		# From the fleet panel
		editorButton:QPushButton = theFleetControl.findChild(QPushButton, "EditorButton") # type: ignore
		editorButton.clicked.connect(partial(changeScreen, parent, 1, 1))

		# From the code editor
		codeEditor:QTextEdit = page1.findChild(QTextEdit, "codeEditor") # type: ignore
		mainExpanseButton:QPushButton = page1.findChild(QPushButton, "BackButton") # type: ignore
		mainExpanseButton.clicked.connect(partial(self.parseValuescript, codeEditor, parent))

	# Parse the text into an Abstract Syntax Tree to be executed
	# REWRITE THIS
	@Slot(QTextEdit, QStackedLayout)
	def parseValuescript(self, codeEditor:QTextEdit, parent:QStackedLayout):
		ret = self.programs.add("HI", codeEditor.toPlainText())
		if ret == 0: return changeScreen(parent, 1, 0)
		return

	def changeState(self, page):
		if page == 0:
			self.executeGame()
		else:
			self.stopGame()
		return

	def startState(self, page):
		if page == 1:
			self.executeGame()
		else:
			self.stopGame()
		return

	def eventing(self):
		self.gameState.wait()
		while self.gameState.is_set():
			pass
		return

	def manageData(self):
		self.gameState.wait()
		self.programs.run()
		while self.gameState.is_set():
			exported = self.programs.grab()
			if exported[0] is None: continue
			self.varAccess.acquire()
			self.gameVariables.update({exported[0]: exported[1]})
			self.varAccess.release()
			self.programs.clean()
		self.programs.kill()
		return

	def manageRequests(self):
		self.gameState.wait()
		while self.gameState.is_set():
			request = self.programs.get()
			if request[0] is None: continue
			if self.gameVariables.get(request[0]) is not None:
				self.programs.update(request[0], self.gameVariables.get(request[0]))
			else:
				self.programs.put(request[0], request[1])
		return

	def executeGame(self):
		# Some empty lists for us
		self.rocks = []
		self.units = {}
	
		# Load some data and load the rocks
		data = gs.worldData
		character = gs.saveData
		self.world = gameScene()

		# Create the gradient
		self.world.setBackgroundBrush(QColor.fromHsv(0, 0, 255))
		worldBorder = QPen()
		worldBorder.setWidth(1000)
		worldBorderGradient = QRadialGradient(0, 0, 1000)
		worldBorderGradient.setColorAt(0, QColor.fromHsv(0, 0, 0))
		worldBorderGradient.setColorAt(1, QColor.fromHsv(0, 0, 255))
		worldBorderGradient.setSpread(QGradient.Spread.ReflectSpread)
		worldBorder.setBrush(QBrush(worldBorderGradient))
		self.world.addEllipse(-50540, -50540, 101080, 101080, worldBorder, QBrush(QColor.fromHsv(0, 0, 0)))

		# Display the generated rocks
		for rock in data["Rocks"]:
			polygon = QPolygonF()
			for point in rock:
				polygon.append(QPointF(point[0], point[1]))
			self.rocks.append(self.world.addPolygon(polygon, brush = QBrush(QColor.fromHsv(0, 0, 100))))

		# Show the units
		for unit, info in character["Units"].items():
			pixmap = QPixmap("Images\\" + info["class"])
			if info["class"] == "base_unit": self.units.update({unit: unit_classes.base_unit(
				name=unit,
				pos=QPointF(info["x"], info["y"]),
				orient=info["orient"],
				obj=self.world.addPixmap(pixmap)
				)})
			elif info["class"] == "enemy_unit": self.units.update({unit: unit_classes.enemy_unit(
				name=unit,
				pos=QPointF(info["x"], info["y"]),
				orient=info["orient"],
				obj=self.world.addPixmap(pixmap)
				)})

		# Show the scene
		graphicsView:QGraphicsView = self.theExpanse.findChild(QGraphicsView, "graphicsView") # type: ignore
		graphicsView.setScene(self.world)

		self.threadpool = QThreadPool.globalInstance()
		dataThread = runtime(self.manageData)
		requestThread = runtime(self.manageRequests)
		#eventsThread = runtime(self.eventing)
		self.threads.append(dataThread)
		self.threads.append(requestThread)
		#self.threads.append(eventsThread)
		self.threadpool.start(dataThread)
		self.threadpool.start(requestThread)
		#self.threadpool.start(eventsThread)
		self.gameState.set()
		x = randint(-1000, 1000)
		y = randint(-1000, 1000)
		ori = randint(0, 359)
		name = "ENEMY_" + str(randint(0, 1000))
		createUnit(gs.saveData["Index"], name, "enemy_unit", x, y, ori, False)
		self.units.update({name: unit_classes.enemy_unit(
			name=name,
			pos=QPointF(x, y),
			orient=ori,
			obj=self.world.addPixmap(QPixmap("Images\\enemy_unit"))
			)})
		for data in self.units:
			self.units[data].moveTo(QPointF(x * randint(-2, 2), y * randint(-2, 2)))
		return

	def stopGame(self):
		self.gameState.clear()
		self.threads.clear()
		return