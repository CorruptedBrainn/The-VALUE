"""
Author: Nicolas Martens
Name: game_container.py
Description: This file holds the class that wraps around the main game page
"""

from random import randint
import threading
from functools import partial

from PySide6.QtCore import ( # type: ignore
	Slot,
	QPointF,
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
	)
from PySide6.QtGui import ( # type: ignore
	QBrush,
	QPen,
	QPolygonF,
	QColor,
	QGradient,
	QRadialGradient,
	)

from widget_helper import (
	loadWidget,
	changeScreen,
	changeMainScreen,
	)
import global_storage as gs
from valuescript_wrapper import VSProgramObject

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
	
	target_x = 0
	target_y = 0

	def travelTo(self):
		self.gameState.wait()
		while self.gameState.is_set():
			self.varAccess.acquire()
			for export in self.gameVariables:
				if "_x_coordinate" in export:
					loc = self.gameVariables[export]
					self.gameVariables[export] = randint(int(abs(loc - self.target_x)/10), loc)
				elif "_y_coordinate" in export:
					loc = self.gameVariables[export]
					self.gameVariables[export] = randint(int(abs(loc - self.target_y)/10), loc)
				elif "_x_target" in export:
					self.target_x = self.gameVariables[export] + randint(-10, 10)
					self.gameVariables[export] = self.target_x
				elif "_y_target" in export:
					self.target_y = self.gameVariables[export] + randint(-10, 10)
					self.gameVariables[export] = self.target_y
			self.varAccess.release()
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
		# An empty list of rocks for the background
		rocks = []
	
		# Load some data and load the rocks
		data = gs.worldData
		world = QGraphicsScene()

		# Create the gradient
		world.setBackgroundBrush(QColor.fromHsv(0, 0, 255))
		worldBorder = QPen()
		worldBorder.setWidth(1000)
		worldBorderGradient = QRadialGradient(0, 0, 1000)
		worldBorderGradient.setColorAt(0, QColor.fromHsv(0, 0, 0))
		worldBorderGradient.setColorAt(1, QColor.fromHsv(0, 0, 255))
		worldBorderGradient.setSpread(QGradient.Spread.ReflectSpread)
		worldBorder.setBrush(QBrush(worldBorderGradient))
		world.addEllipse(-50540, -50540, 101080, 101080, worldBorder, QBrush(QColor.fromHsv(0, 0, 0)))

		# Displaythe generated rocks
		for rock in data["Rocks"]:
			polygon = QPolygonF()
			for point in rock:
				polygon.append(QPointF(point[0], point[1]))
			rocks.append(world.addPolygon(polygon, brush = QBrush(QColor.fromHsv(0, 0, 100))))

		# Show the scene
		graphicsView:QGraphicsView = self.theExpanse.findChild(QGraphicsView, "graphicsView") # type: ignore
		graphicsView.setScene(world)

		dataThread = threading.Thread(target=self.manageData)
		requestThread = threading.Thread(target=self.manageRequests)
		travelThread = threading.Thread(target=self.travelTo)
		self.threads.append(dataThread)
		self.threads.append(requestThread)
		self.threads.append(travelThread)
		dataThread.start()
		requestThread.start()
		travelThread.start()
		self.gameState.set()
		return

	def stopGame(self):
		self.gameState.clear()
		for thread in self.threads:
			thread.join()
		self.threads.clear()
		return