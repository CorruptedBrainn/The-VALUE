"""
Header stuff
"""

import os, ctypes

SCRIPTDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DLLDIR = os.path.join(SCRIPTDIR, "bin\\vs-2022\\x64\\Debug DLL")

"""
TODO:
- Create classes for each functionality aspect
"""

class ValuescriptCompiler(object):
	runtime = ctypes.CDLL(DLLDIR + "\\antlr4-runtime.dll", winmode = 0)
	script = ctypes.CDLL(DLLDIR + "\\VALUESCRIPT.dll", winmode = 0)

	class ValuescriptError(ctypes.Structure):
		_fields_ = [
			("message", ctypes.c_wchar_p),
			("lineAt", ctypes.c_int),
			("characterAt", ctypes.c_int)
			]

	script.scriptCheckStageA.argtypes = [ctypes.c_wchar_p]
	script.scriptCheckStageA.restype = ctypes.c_int
	script.scriptCheckStageB.argtypes = []
	script.scriptCheckStageB.restype = ValuescriptError
	script.scriptCheckStageC.argtypes = [ctypes.c_int]
	script.scriptCheckStageC.restype = ctypes.c_int
	# Work with other functions

	class ScriptScanIterable:
		def __init__(self, program:str):
			self.program = program
			self.count = ValuescriptCompiler.script.scriptCheckStageA(self.program)
			return

		def __iter__(self):
			return self

		def __next__(self):
			if ValuescriptCompiler.script.scriptCheckStageC(self.count) > 0:
				self.count -= 1;
				return ValuescriptCompiler.script.scriptCheckStageB()
			else:
				raise StopIteration

		def refresh(self, program:str)->None:
			self.program = program
			self.count = ValuescriptCompiler.script.scriptCheckStageA(self.program)
			return