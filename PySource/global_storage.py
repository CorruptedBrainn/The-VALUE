"""
Author: Nicolas Martens
Name: global_storage.py
Description: The file that allows me to manage storage across files efficiently
"""

import copy, random

# The index of the screen we are currently showing
mainCurrentPage = 0

# Default setting values
settingDefault = {
	"GPSet": {
		"InfoUtils": {
			"Mode": "None",
			"UDisplay": "None",
			"FDisplay": "None",
			}
		},
	"AudioSet": {
		"VolSet": {
			"Genval": 50,
			"SFXVal": 50,
			"ABGVal": 50,
			},
		"SoundPacks": {
			"GMusic": ["Pack Name 1"],
			"SFX": ["Pack Name 1"],
			"Amb": ["Pack Name 1"],
			}
		},
	"GraSet": {
		"Themes": {
			"GUI": "Theme Name 1",
			"Uni": "Theme Name 1",
			"Env": "Theme Name 1",
			}
		}
	}
settingData = copy.deepcopy(settingDefault)

# Default save data values
savePlaceholders = {
	"Name": "New Save",
	"Difficulty": -1,
	"Index": 0,
	"Resources": {
		"PL": 0,
		"SM": 0,
		"PM": 0,
		},
	}

saveData = copy.deepcopy(savePlaceholders)

# An empty objet for world data
worldData = {
	"Rocks": [
		]
	}

# For when we want to create a new world
def createWorld()->dict:
	from cpp_wrapper import GamePolygon

	# Identical to worldData
	envData = {
	"Rocks": [
		]
	}

	# Generate each rock focal point and radius, then use C++ to generate it
	count = random.randint(100, 500)
	for rock in range(count):
		x = random.randint(-40000, 40000)
		y = random.randint(-40000, 40000)
		r = random.randint(100, 1000)
		i = min(max(random.gauss(0.75, 0.125), 0), 1)
		s = min(max(random.gauss(0.75, 0.125), 0), 1)
		f = min(max(random.gauss(0.75, 0.125), 0), 1)
		poly = GamePolygon(x, y, r, i, s, f)
		envData["Rocks"].append(poly.polygon)
		poly.delete()
	return envData