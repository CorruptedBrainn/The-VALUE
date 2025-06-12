import os
from ctypes import CDLL

pythonpath = str(os.environ.get("PYTHONPATH"))
splitpaths = pythonpath.split(os.pathsep)
searchpaths = [path for path in splitpaths if "x64\\Debug" in path or "x64\\Release" in path]

class VScompiler(object):
    script = CDLL(searchpaths[0] + '\\valuescript.dll', winmode=0)

    def __init__(self):
        self.obj = self.script.createCompiler()
        return
    
    def compile(self, fileContents:str) -> bool:
        help = self.script.compile(self.obj, fileContents)
        return help