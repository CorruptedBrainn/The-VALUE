import copy

mainCurrentPage = 0
buttonA = 1
buttonB = 2
buttonC = 3

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