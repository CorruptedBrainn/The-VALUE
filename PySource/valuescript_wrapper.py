import os, ctypes

scriptDir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
dllDir = os.path.join(scriptDir, "bin\\vs-2022\\x64\\Release DLL")

class VSProgramObject(object):
    dep = ctypes.CDLL(dllDir + "\\antlr4-runtime.dll", winmode=0)
    script = ctypes.CDLL(dllDir + "\\ANTLR4_GENERATION.dll", winmode=0)

    def __init__(self):
        self.obj = self.script.createStorage()
        return

    def __del__(self):
        return self.script.deleteStorage(self.obj)

    def add(self, name: str, text: str):
        return self.script.addProgram(self.obj, name, text)

    def remove(self, name: str):
        return self.script.removeProgram(self.obj, name)

    def run(self):
        return self.script.executePrograms(self.obj)
