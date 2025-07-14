import os
from ctypes import CDLL, pointer

pythonpath = str(os.environ.get("PYTHONPATH"))
splitpaths = pythonpath.split(os.pathsep)
searchpaths = [path for path in splitpaths if "vs-2022\\x64\\Debug DLL" in path or "vs-2022\\x64\\Release DLL" in path]

class VSProgramObject(object):
    dep = CDLL(searchpaths[0] + "\\antlr4-runtime.dll", winmode=0)
    script = CDLL(searchpaths[0] + "\\ANTLR4_GENERATION.dll", winmode=0)

    def __init__(self):
        self.obj = self.script.createStorage()
        return

    def add(self, name: str, text: str):
        return self.script.addProgram(self.obj, name, text);

    def remove(self, name: str):
        return self.script.removeProgram(self.obj, name);

    def run(self):
        return self.script.executePrograms(self.obj);