"""
Name: main.py
Version: 0.0.3-alpha
Description: Program execution starts and ends here -- this file contains and manages the overall top level application objects
Author: Nicolas Martens
"""

from interface import TVApplication
from data import DataPackage
from game import GameObject

# temp
script = """

"""


from native_wrapper import ValuescriptCompiler
ValuescriptCompiler.RunScriptOnce(script, "temp")
breakpoint()

from time import sleep
compiler = ValuescriptCompiler.ScriptCompilerClass()
compiler.addScript(script, "temp")
runtime = ValuescriptCompiler.ScriptRuntimeClass()
sleep(100)
runtime.kill(compiler)

# Check that this is the startpoint for execution
if __name__ == "__main__":
	package = DataPackage()
	app = TVApplication(package)
	runtime = GameObject(app)
	app.start() # RIP Braincells