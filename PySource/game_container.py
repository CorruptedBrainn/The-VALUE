import copy
from functools import partial

from PySide6.QtCore import ( # type: ignore
	Slot,
	Qt,
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

from widget_helper import loadWidget, changeScreen, changeMainScreen
import global_storage as gs
from valuescript_wrapper import VSProgramObject

class TVGameContainer(QStackedWidget):
	programs = VSProgramObject()

	def __init__(self, parent:QStackedLayout):
		super().__init__()
		page0 = loadWidget("main_game.ui")
		page1 = loadWidget("editor.ui")
		self.addWidget(page0)
		self.addWidget(page1)

		page0Layout:QVBoxLayout = page0.layout()
		mainGameLayout:QStackedWidget = QStackedWidget()
		theExpanse:QWidget = loadWidget("the_expanse.ui")
		theJournal:QWidget = loadWidget("journal.ui")
		theTechTree:QWidget = loadWidget("tech_tree.ui")
		theFleetControl:QWidget = loadWidget("fleet_control.ui")
		mainGameLayout.addWidget(theExpanse)
		mainGameLayout.addWidget(theJournal)
		mainGameLayout.addWidget(theTechTree)
		mainGameLayout.addWidget(theFleetControl)
		page0Layout.addWidget(mainGameLayout)
		page0Layout.setStretch(1, 6)

		ButtonA:QPushButton = page0.findChild(QPushButton, "GenericButton1") # type: ignore
		ButtonB:QPushButton = page0.findChild(QPushButton, "GenericButton2") # type: ignore
		ButtonC:QPushButton = page0.findChild(QPushButton, "GenericButton3") # type: ignore
		buttonList = [ButtonA, ButtonB, ButtonC]
		ButtonA.clicked.connect(partial(changeMainScreen, mainGameLayout, buttonList, 0))
		ButtonB.clicked.connect(partial(changeMainScreen, mainGameLayout, buttonList, 1))
		ButtonC.clicked.connect(partial(changeMainScreen, mainGameLayout, buttonList, 2))

		editorButton:QPushButton = theFleetControl.findChild(QPushButton, "EditorButton") # type: ignore
		editorButton.clicked.connect(partial(changeScreen, parent, 1, 1))

		codeEditor:QTextEdit = page1.findChild(QTextEdit, "codeEditor") # type: ignore
		mainExpanseButton:QPushButton = page1.findChild(QPushButton, "BackButton") # type: ignore
		mainExpanseButton.clicked.connect(partial(self.parseValuescript, codeEditor, parent))

		rocks = []
		
		data = gs.createWorld()
		world = QGraphicsScene()

		world.setBackgroundBrush(QColor.fromHsv(0, 0, 255))
		worldBorder = QPen()
		worldBorder.setWidth(1000)
		worldBorderGradient = QRadialGradient(0, 0, 1000)
		worldBorderGradient.setColorAt(0, QColor.fromHsv(0, 0, 0))
		worldBorderGradient.setColorAt(1, QColor.fromHsv(0, 0, 255))
		worldBorderGradient.setSpread(QGradient.Spread.ReflectSpread)
		worldBorder.setBrush(QBrush(worldBorderGradient))
		world.addEllipse(-50540, -50540, 101080, 101080, worldBorder, QBrush(QColor.fromHsv(0, 0, 0)))

		for rock in data["Rocks"]:
			polygon = QPolygonF()
			for point in rock:
				polygon.append(QPointF(point[0], point[1]))
			rocks.append(world.addPolygon(polygon, brush = QBrush(QColor.fromHsv(0, 0, 100))))

		graphicsView:QGraphicsView = theExpanse.findChild(QGraphicsView, "graphicsView") # type: ignore
		graphicsView.setScene(world)

	@Slot(QTextEdit, QStackedLayout)
	def parseValuescript(self, codeEditor:QTextEdit, parent:QStackedLayout):
		ret = self.programs.add("HI", codeEditor.toPlainText())
		if ret == 0: return changeScreen(parent, 1, 0)
		return