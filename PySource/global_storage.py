import copy, random, math, functools

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

def orientation(pointA, pointB, pointC):
	dotProduct =	(pointA[0] * (pointB[1] - pointC[1])) + \
					(pointB[0] * (pointC[1] - pointA[1])) + \
					(pointC[0] * (pointA[1] - pointB[1]))
	if dotProduct < 0:
		return -1
	elif dotProduct > 0:
		return 1
	return 0

def linearDistance(pointA, pointB):
    return (pointA[0] - pointB[0])**2 + (pointA[1] - pointB[1])**2

def createWorld()->dict:
	envData = {
	"Rocks": [
		]
	}

	count = random.randint(10, 50)
	for rock in range(count):
		envData["Rocks"].append([]) # TEMP
	return envData