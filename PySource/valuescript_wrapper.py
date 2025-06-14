import os
from ctypes import CDLL

pythonpath = str(os.environ.get("PYTHONPATH"))
splitpaths = pythonpath.split(os.pathsep)
searchpaths = [path for path in splitpaths if "x64\\Debug" in path or "x64\\Release" in path]

class VScompiler(object):
    script = CDLL(searchpaths[0] + '\\valuescript.dll', winmode=0)

    def __init__(self):
        self.obj = self.script.createCompiler()
        # TEMP
        help = self.script.compile(self.obj, "re print(HELLO);\nprint(Hello, World!);print(EEPY);int();str();bool();double();")
        if help == -1: self.script.showError(self.obj)
        return
    
    def compile(self, fileContents:str) -> int:
        help = self.script.compile(self.obj, fileContents)
        if help == -1: self.script.showError(self.obj)
        return help