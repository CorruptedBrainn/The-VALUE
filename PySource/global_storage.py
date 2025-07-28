import copy, random

mainCurrentPage = 0

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

worldData = {
	"Rocks": [
		]
	}

def createWorld()->dict:
	from cpp_wrapper import GamePolygon

	envData = {
	"Rocks": [
		]
	}

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