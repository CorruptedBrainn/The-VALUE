import math

from PySide6.QtCore import (
	QPointF,
	QTimeLine,
	Signal,
	Slot
	)

from PySide6.QtWidgets import (
	QGraphicsPixmapItem,
	QGraphicsItemAnimation,
	)

def calcDist(start:QPointF, end:QPointF):
	return math.sqrt(pow(end.x() - start.x(), 2) + pow(end.y() - start.y(), 2))

class core_unit():
	def __init__(self,
			  name:str = "N/A",
			  pos:QPointF = QPointF(0.0, 0.0),
			  orient:float = 0.0,
			  hp:float = 100.0,
			  kills:int = 0,
			  dmg:float = 10.0,
			  speed:float = 100.0,
			  atkspd:float = 1.0,
			  sspeed:float = 50.0,
			  fog:float = 1000.0,
			  srange:float = 500.0,
			  obj:QGraphicsPixmapItem = None
			  ):
		obj.setPos(pos)
		obj.setRotation(orient)
		self._name = name
		self._pos = pos
		self._orient = orient
		self._hp = hp
		self._kills = kills
		self._dmg = dmg
		self._speed = speed
		self._atkspd = atkspd
		self._sspeed = sspeed
		self._fog = fog
		self._srange = srange
		self._obj = obj
		self.anim_MOVE = QGraphicsItemAnimation()
		self.anim_ROTATE = QGraphicsItemAnimation()
		self.anim_MOVE.setItem(self._obj)
		self.anim_ROTATE.setItem(self._obj)
		return

	@Slot(QPointF)
	def moveTo(self, loc:QPointF):
		if self.anim_MOVE.timeLine() is not None: self.anim_MOVE.timeLine().stop()
		if self.anim_ROTATE.timeLine() is not None: self.anim_ROTATE.timeLine().stop()
		distance = calcDist(self._pos, loc)
		moveTime = 1000 * distance / self._speed
		moveTimer = QTimeLine(moveTime)
		moveTimer.setFrameRange(0, 100)
		deg = math.atan2(self._pos.x() - loc.x(), self._pos.y() - loc.y()) * 180 / math.pi
		change = self._orient - deg
		rotateTime = 100 * change / self._speed
		rotateTimer = QTimeLine(rotateTime)
		rotateTimer.setFrameRange(0, 100)
		self.anim_MOVE.setTimeLine(moveTimer)
		self.anim_ROTATE.setTimeLine(rotateTimer)
		xStep = abs(loc.x() - self._pos.x()) / 200
		yStep = abs(loc.y() - self._pos.y()) / 200
		rotStep = change / 200
		for i in range(0, 200):
			self.anim_MOVE.setPosAt(i / 200.0, QPointF(self._pos.x() + i * xStep, self._pos.y() + i * yStep))
			self.anim_ROTATE.setRotationAt(i / 200.0, self._orient + i * rotStep)
		moveTimer.start()
		rotateTimer.start()
		self._pos = loc
		self._orient = deg
		return

class base_unit(core_unit):
	def __init__(self,
			  name:str = "N/A",
			  pos:QPointF = QPointF(0.0, 0.0),
			  orient:float = 0.0,
			  obj:QGraphicsPixmapItem = None
			  ):
		super().__init__(
			name=name,
			pos=pos,
			orient=orient,
			obj=obj
			)
		return

class enemy_unit(core_unit):
	def __init__(self,
			  name:str = "N/A",
			  pos:QPointF = QPointF(0.0, 0.0),
			  orient:float = 0.0,
			  obj:QGraphicsPixmapItem = None
			  ):
		super().__init__(
			name=name,
			pos=pos,
			orient=orient,
			hp=50.0,
			kills=0,
			dmg=5.0,
			speed=70.0,
			atkspd=1.0,
			sspeed=50.0,
			fog=1000.0,
			srange=600.0,
			obj=obj
			)
		return