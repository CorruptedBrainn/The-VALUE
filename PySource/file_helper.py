"""
Author: Nicolas Martens
Name: file_helper.py
Description: The scripts that allow me to manage anything file related, such as saving game states
"""

import os
import json
import copy

from PySide6.QtCore import ( # type: ignore
	Slot
	)
from PySide6.QtWidgets import ( # type: ignore
	QDialog
	)

import global_storage as gs

# Get the filepaths as strings for ease
dataFolder = "../Data/"
settingsFile = dataFolder + "Global.tvsf"
saveAFolder = dataFolder + "I/"
saveAData = saveAFolder + "Standard.andf"
saveAEnv = saveAFolder + "Expanse.tegf"
saveAUnits = saveAFolder + "Units/"
saveBFolder = dataFolder + "II/"
saveBData = saveBFolder + "Standard.andf"
saveBEnv = saveBFolder + "Expanse.tegf"
saveBUnits = saveBFolder + "Units/"
saveCFolder = dataFolder + "III/"
saveCData = saveCFolder + "Standard.andf"
saveCEnv = saveCFolder + "Expanse.tegf"
saveCUnits = saveCFolder + "Units/"

# When the scripts are run, just ensure that we have the required folders
def setupWorkspace():
	if (os.path.exists(dataFolder) == False): os.makedirs(dataFolder)

	if (os.path.exists(settingsFile) == False):
		with open(settingsFile, "x") as file:
			text = json.dumps(gs.settingDefault)
			file.write(text)

	if (os.path.exists(saveAFolder) == False): os.makedirs(saveAFolder)

	if (os.path.exists(saveAData) == False):
		with open(saveAData, "x") as file:
			text = json.dumps(gs.savePlaceholders)
			file.write(text)

	if (os.path.exists(saveAEnv) == False):
		with open(saveAEnv, "x") as file:
			text = json.dumps(gs.createWorld)
			file.write(text)

	if (os.path.exists(saveAUnits) == False): os.makedirs(saveAUnits)

	if (os.path.exists(saveBFolder) == False): os.makedirs(saveBFolder)

	if (os.path.exists(saveBData) == False):
		with open(saveBData, "x") as file:
			text = json.dumps(gs.savePlaceholders)
			file.write(text)

	if (os.path.exists(saveBUnits) == False): os.makedirs(saveBUnits)

	if (os.path.exists(saveCFolder) == False): os.makedirs(saveCFolder)

	if (os.path.exists(saveCData) == False):
		with open(saveCData, "x") as file:
			text = json.dumps(gs.savePlaceholders)
			file.write(text)
	if (os.path.exists(saveCUnits) == False): os.makedirs(saveCUnits)

	loadSettings()

# When I want to load data from a save
@Slot(int)
def updateSaveLoad(saveIndex: int):
	storeSave()
	text = dict()
	if (saveIndex == 1):
		with open(saveAData, "r") as file: text = file.read()
	elif (saveIndex == 2):
		with open(saveBData, "r") as file: text = file.read()
	elif (saveIndex == 3):
		with open(saveCData, "r") as file: text = file.read()
	else: return
	gs.saveData = json.loads(text)
	loadWorld()
	return

# When I want to delete some save data
@Slot(int)
def deleteSave(saveIndex:int):
	text = json.dumps(gs.savePlaceholders)
	if (saveIndex == 1):
		with open(saveAData, "w") as file: file.write(text)
	elif (saveIndex == 2):
		with open(saveBData, "w") as file: file.write(text)
	elif (saveIndex == 3):
		with open(saveCData, "w") as file: file.write(text)
	return

# When I want to store some save data
@Slot()
def storeSave():
	saveIndex:int = gs.saveData["Index"]
	text = json.dumps(gs.saveData)
	if (saveIndex == 1):
		with open(saveAData, "w") as file: file.write(text)
	elif (saveIndex == 2):
		with open(saveBData, "w") as file: file.write(text)
	elif (saveIndex == 3):
		with open(saveCData, "w") as file: file.write(text)
	return

# When I want to load the settings data
@Slot()
def loadSettings():
	with open (settingsFile, "r") as file:
		text = file.read()
		gs.settingData = json.loads(text)
	return

# Closing the settings dialog
@Slot(int)
def closeSettings(result:int):
	if result == 1: applySettings()
	loadSettings()
	return

# Reset the settings values
@Slot(QDialog)
def resetSettings(obj:QDialog):
	from widget_helper import showSettings

	gs.settingData = copy.deepcopy(gs.settingDefault)
	showSettings(obj)
	return

# Apply the settings
@Slot()
def applySettings():
	with open(settingsFile, "w") as file:
		text = json.dumps(gs.settingData)
		file.write(text)
	return

# Loading a game
@Slot()
def loadWorld():
	saveIndex:int = gs.saveData["Index"]
	world = dict()
	if (saveIndex == 1):
		with open(saveAEnv, "r") as file: world = file.read()
	elif (saveIndex == 2):
		with open(saveBEnv, "r") as file: world = file.read()
	elif (saveIndex == 3):
		with open(saveCEnv, "r") as file: world = file.read()
	else: return
	gs.worldData = json.loads(world)
	return