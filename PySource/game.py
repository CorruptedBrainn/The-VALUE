from datetime import datetime
from functools import partial
from random import randint

from PySide6.QtCore import (
	Slot,
	QObject,
	QTimer,
	)
from PySide6.QtWidgets import (
	QStackedWidget,
	)

from game_container import TVGameContainer
import unit_classes as backend
import global_storage as gs
from file_helper import storeSave
from cpp_wrapper import Generator, question

@Slot(QStackedWidget, int)
def toggleGame(container:TVGameContainer, page:int):
	if page == 0: finishGame()
	else: startGame(container)
	return

@Slot(QObject, str, str)
def answered(container:TVGameContainer, correct:str, guess:str):
	if guess == "": guess = container.answerText.text()
	correct = "".join(sorted(correct.split()))
	guess = ",".join(sorted("".join(guess.split()).split(",")))
	gs.saveData["Quiz"]["QAns"] += 1
	if correct == guess:
		gs.saveData["Quiz"]["Q-RA"] += 1
		container.addAmmo()
	else:
		gs.saveData["Quiz"]["Q-WA"] += 1
	gs.saveData["Quiz"]["AccP"] = int(100 * gs.saveData["Quiz"]["Q-RA"] / gs.saveData["Quiz"]["QAns"])
	container.updateData()
	container.refreshQuestion(0)
	for connection in container.buttonConnections:
		QObject.disconnect(connection)
	container.buttonConnections.clear()
	container.timekeeper.start(10000 - 99 * gs.saveData["Quiz"]["AccP"])
	return

@Slot(QObject)
def pushQuestion(container:TVGameContainer):
	q:question = question(Generator.create(gs.saveData["Difficulty"]))
	mode = randint(1, 2)
	if gs.saveData["Difficulty"] == q.type: mode = 1
	elif gs.saveData["Difficulty"] >= q.type + 2: mode = 2
	container.refreshQuestion(mode, q.question, q.optionTL, q.optionTR, q.optionBL, q.optionBR)
	container.buttonConnections.append(container.submitButton.clicked.connect(partial(
		answered, container, q.answer, ""
		)))
	container.buttonConnections.append(container.button_TL.clicked.connect(partial(
		answered, container, q.answer, q.optionTL
		)))
	container.buttonConnections.append(container.button_TR.clicked.connect(partial(
		answered, container, q.answer, q.optionTR
		)))
	container.buttonConnections.append(container.button_BL.clicked.connect(partial(
		answered, container, q.answer, q.optionBL
		)))
	container.buttonConnections.append(container.button_BR.clicked.connect(partial(
		answered, container, q.answer, q.optionBR
		)))
	return

@Slot(QObject)
def progressUpdate(container:TVGameContainer):
	container.progressBar.setValue(100 - 100 * container.timekeeper.remainingTime() / container.timekeeper.interval())
	return

def startGame(container:TVGameContainer):
	container.timekeeper.start(5000 - 49 * gs.saveData["Quiz"]["AccP"])
	container.progress.start()
	return
	# I want a timer that will attempt to fire a question every 10 seonds, and will subtracted by accuracy% * 9.9
	# I think
	# I don't think
	# I don't think well lol
	# I reckon I multithread it-

def finishGame(container:TVGameContainer):
	gs.saveData["Last"] = datetime.now().isoformat(" ", "minute")
	storeSave()
	container.progress.stop()
	container.timekeeper.stop()
	return