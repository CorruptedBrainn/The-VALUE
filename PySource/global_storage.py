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
	"Units": {
		}
	}

# The default unit script -- Fibonacci for now
defaultScript = """
import base_unit
static var main->base_unit;
static var timer->int = 0;
if (timer % 5000 == 0) {
	main.go_to(0, 0);
}
if (timer % 1000 == 0) {
	console_out("-----LOCATION-----\n\tX: ");
	console_out(main.x_coordinate);
	console_out("\n\tY: ");
	console_out(main.y_coordinate);
	console_out("\n------TARGET------\n\tX: ");
	console_out(main.x_target);
	console_out("\n\tY: ");
	console_out(main.y_target);
	console_out("\n------------------\n\n");
}
if (timer % 500 == 0) {
	main.update();
}
timer++;
"""

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