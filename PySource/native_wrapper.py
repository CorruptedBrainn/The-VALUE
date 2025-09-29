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
	script.errorCheckStageA.argtypes = [ctypes.c_wchar_p]
	script.errorCheckStageA.restype = ctypes.c_int
	script.errorCheckStageB.argtypes = []
	script.errorCheckStageB.restype = ValuescriptError
	script.errorCheckStageC.argtypes = [ctypes.c_int]
	script.errorCheckStageC.restype = ctypes.c_int
	script.compileProcessStageA.argtypes = []
	script.compileProcessStageA.restype = ctypes.c_int
	script.compileProcessStageB.argtypes = [ctypes.c_wchar_p, ctypes.c_wchar_p]
	script.compileProcessStageB.restype = ctypes.c_int
	script.compileProcessStageC.argtypes = []
	script.compileProcessStageC.restype = ctypes.c_int
	script.runtimeStageA.argtypes = []
	script.runtimeStageA.restype = ctypes.c_int
	script.runtimeStageB.argtypes = []
	script.runtimeStageB.restype = ctypes.c_int

	class ScriptScanIterable:
		def __init__(self, program:str):
			self.program = program
			self.count = ValuescriptCompiler.script.scriptCheckStageA(self.program)
			return

		def __iter__(self):
			return self

		def __next__(self):
			if ValuescriptCompiler.script.scriptCheckStageC(self.count) > 0:
				self.count -= 1
				return ValuescriptCompiler.script.scriptCheckStageB()
			else:
				raise StopIteration

		def refresh(self, program:str)->None:
			self.program = program
			self.count = ValuescriptCompiler.script.scriptCheckStageA(self.program)
			return

	class ErrorScanIterable:
		def __init__(self, program:str):
			self.program = program
			self.count = ValuescriptCompiler.script.errorCheckStageA(self.program)
			return

		def __iter__(self):
			return self

		def __next__(self):
			if ValuescriptCompiler.script.errorCheckStageC(self.count) > 0:
				self.count -= 1
				return ValuescriptCompiler.script.scriptCheckStageB()
			else:
				raise StopIteration

		def refresh(self, program:str)->None:
			self.program = program
			self.count = ValuescriptCompiler.script.errorCheckStageA(self.program)
			return

	class ScriptCompilerClass:
		def __init__(self):
			self.count = 0
			self.program = {}
			ValuescriptCompiler.script.compileProcessStageA()
			return

		def addScript(self, program:str, name:str)->None:
			self.count += 1
			self.program.update({name: program})
			ValuescriptCompiler.script.compileProcessStageB(program, name)
			return

		def compile(self)->None:
			ValuescriptCompiler.script.compileProcessStageC()
			return

	class ScriptRuntimeClass:
		def __init__(self):
			ValuescriptCompiler.script.runtimeStageA()
			return
		
		def kill(self):
			ValuescriptCompiler.script.runtimeStageB()
			del self
			return