import os
from ctypes import CDLL

pythonpath = str(os.environ.get("PYTHONPATH"))
splitpaths = pythonpath.split(os.pathsep)
searchpaths = [path for path in splitpaths if "x64\\Debug" in path or "x64\\Release" in path]

sampleCodeA = """int temp;
bool notTemp = false;
static const double pi = 3.14;
  array <int  >
  name = {
  2,3 , 9
  ,6};
 print;
"""

sampleCodeB = """print("Hi");
print("He said \"Bye!\"");
"""

sampleInitialiseBasic = """int x;
int y = 10;
int z = 20;
x = 5;
z = 30;
"""

class VScompiler(object):
    script = CDLL(searchpaths[0] + '\\valuescript.dll', winmode=0)

    def __init__(self):
        self.obj = self.script.createCompiler()
        # TEMP
        help = self.script.compile(self.obj, sampleInitialiseBasic)
        if help == -1: self.script.showError(self.obj)
        return
    
    def compile(self, fileContents:str) -> int:
        help = self.script.compile(self.obj, fileContents)
        if help == -1: self.script.showError(self.obj)
        return help