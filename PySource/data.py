"""
Name: data.py
Version: 0.0.4-alpha
Description: Manage my file reading and game data storage
Author: Nicolas Martens
"""

import os
import json
import roman

class FileManager:
	DATAFOLDER = "../Data/"
	SETTINGSFILE = "Global.tvsf"
	DATAFILE = "Standard.andf"
	ENVFILE = "Expanse.tegf"
	UNITSFOLDER = "Units/"

	def __init__(self):
		if (os.path.exists(FileManager.DATAFOLDER) == False): os.makedirs(FileManager.DATAFOLDER)
		return

	def readSettings(self)->dict[str, dict]:
		with open(FileManager.DATAFOLDER + FileManager.SETTINGSFILE, "r") as file:
			text = file.read()
			obj:dict[str, dict] = json.loads(text)
		return obj

	def writeSettings(self, obj:dict[str, dict])->None:
		with open(FileManager.DATAFOLDER + FileManager.SETTINGSFILE, "w") as file:
			text:str = json.dumps(obj)
			file.write(text)
		return

	def verifySettings(self, obj:dict[str, dict])->None:
		if (os.path.exists(FileManager.DATAFOLDER + FileManager.SETTINGSFILE) == False):
			self.writeSettings(obj)
		return

	def readSave(self, index:int)->dict[str, dict]:
		path:str = roman.toRoman(index) + "/"
		with open(FileManager.DATAFOLDER + path + FileManager.DATAFILE, "r") as file:
			text = file.read()
			obj:dict[str, dict] = json.loads(text)
		return obj

	def writeSave(self, index:int, obj:dict[str, dict])->None:
		path:str = roman.toRoman(index) + "/"
		with open(FileManager.DATAFOLDER + path + FileManager.DATAFILE, "w") as file:
			text:str = json.dumps(obj)
			file.write(text)
		return

	def verifySaves(self, obj:dict[str, dict])->None:
		"""
		TODO:
		- Prevent crashing by adding dumb files
		- Add logic for deleting files & folders with unconventional names
		- Add logic for deleting stuff that doesn't have required subfiles
		- Add logic for renaming files so we always have continuous save numbers
		"""
		with os.scandir(FileManager.DATAFOLDER) as it:
			for entry in it:
				if entry.is_dir():
					index = roman.fromRoman(entry.name)
					if (os.path.exists(entry.path + "/" + FileManager.DATAFILE) == False):
						self.writeSave(index, obj)
		return

	def getSavesList(self)->list[str]:
		ret:list[str] = []
		with os.scandir(FileManager.DATAFOLDER) as it:
			for entry in it:
				if entry.is_dir():
					ret.append(entry.name)
		return ret

class GameSettings:
	def __init__(self, manager:FileManager):
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

		self.manager = manager
		self.manager.verifySettings(self.toExport())
		return

	def toExport(self)->dict[str, dict]:
		return {
			"GPSet": self.Gameplay,
			"AudioSet": self.Audio,
			"GraSet": self.Graphic
			}

	def toImport(self, obj:dict[str, dict])->None:
		self.Gameplay = obj["GPSet"]
		self.Audio = obj["AudioSet"]
		self.Graphic = obj["GraSet"]
		return

	def readSettings(self)->None:
		self.toImport(self.manager.readSettings())
		return

	def storeSettings(self)->None:
		self.manager.writeSettings(self.toExport())
		return

	def resetSettings(self)->None:
		default = GameSettings(self.manager)
		default.storeSettings()
		self.readSettings()
		return

class GameData:
	def __init__(self, manager:FileManager):
		self.Data = {
			"Name": "None",
			"Index": 0,
			"Difficulty": -1,
			"Last": "N/A",
			"Kills": 0
			}
		self.Progress = {
			"Age": -1,
			"Achivements": 0,
			"Technologies": 0
			}
		self.Resources = {
			"Scrap": 0,
			"Precious": 0,
			"Plasma": 0
			}
		self.Units = {}
		self.Foes = {}
		"""NEED SOMETHING FOR ENVIRONMENT"""

		self.manager = manager
		self.manager.verifySaves(self.toExport())
		return

	def toExport(self)->dict[str, dict]:
		return {
			"Data": self.Data,
			"Prog": self.Progress,
			"Cons": self.Resources
			# ADD ENVIRONMENT STUFF
			}

	def toImport(self, obj:dict[str, dict])->None:
		self.Data = obj["Data"]
		self.Progress = obj["Prog"]
		self.Resources = obj["Cons"]
		# ADD ENVIRONMENT STUFF
		return

	def readSave(self, index:int)->None:
		self.toImport(self.manager.readSave(index))
		return

	def storeSave(self)->None:
		if self.Data["Index"] == 0: return
		self.manager.writeSave(self.Data["Index"], self.toExport())
		return

	def deleteSave(self)->None:
		pass

	def createSave(self)->None:
		pass

class DataPackage:
	def __init__(self):
		self.manager = FileManager()
		self.settings = GameSettings(self.manager)
		self.data = GameData(self.manager)
		return