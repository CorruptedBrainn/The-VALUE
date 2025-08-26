"""
Name: data.py
Version: 0.0.4-alpha
Description: Manage my file reading and game data storage
Author: Nicolas Martens
"""

import os
import json

class settings:
	...

class save:
	...

class fileManager:
	def __init__(self):
		self.DATAFOLDER = "../Data/"
		self.SETTINGSFILE = self.DATAFOLDER + "Global.tvsf"
		self.SAVEAFOLDER = self.DATAFOLDER + "I/"
		self.SAVEADATA = self.SAVEAFOLDER + "Standard.andf"
		self.SAVEAENV = self.SAVEAFOLDER + "Expanse.tegf"
		self.SAVEAUNITS = self.SAVEAFOLDER + "Units/"
		self.SAVEBFOLDER = self.DATAFOLDER + "II/"
		self.SAVEBDATA = self.SAVEBFOLDER + "Standard.andf"
		self.saveBEnv = self.SAVEBFOLDER + "Expanse.tegf"
		self.saveBUnits = self.SAVEBFOLDER + "Units/"
		self.SAVECFOLDER = self.DATAFOLDER + "III/"
		self.saveCData = self.SAVECFOLDER + "Standard.andf"
		self.saveCEnv = self.SAVECFOLDER + "Expanse.tegf"
		self.saveCUnits = self.SAVECFOLDER + "Units/"

		return

	def setupFileEcosystem(self, application:settings, game:save):
		pass

class settings:
	def __init__(self):
		self.Gameplay = {
			"Information": {
				"Mode": "None",
				"Unit": "None",
				"Foe": "None"
				}
			}
		self.Audio = {
			"Volume": {
				"Master": 50,
				"SFX": 50,
				"Ambiance": 50
				},
			"Sound": {
				"Master": ["Pack Name 1"],
				"SFX": ["Pack Name 1"],
				"Ambiance": ["Pack Name 1"]
				}
			}
		self.Graphic = {
			"Themes": {
				"GUI": "Theme Name 1",
				"Units": "Theme Name 1",
				"Environment": "Theme Name 1"
				}
			}

		return

	def readSettings(self, manager:fileManager):
		with open(manager.SETTINGSFILE, "r") as file:
			text = file.read()
			obj = json.loads(text)

			self.Gameplay = obj["GPSet"]
			self.Audio = obj["AudioSet"]
			self.Graphic = obj["GraSet"]
		return

	def storeSettings(self, manager:fileManager):
		with open(manager.SETTINGSFILE, "w") as file:
			dump = {
			"GPSet": self.Gameplay,
			"AudioSet": self.Audio,
			"GraSet": self.Graphic
			}

			text = json.dumps(dump)
			file.write(text)
		return

class save:
	def __init__(self):
		pass