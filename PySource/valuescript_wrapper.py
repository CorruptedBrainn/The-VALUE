"""
Author: Nicolas Martens
Name: valuescript_wrapper.py
Description: This script wraps the Valuescript DLL so I can call functions with ease
"""

import os, ctypes

# Get the directories with some filepath magic
scriptDir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
dllDir = os.path.join(scriptDir, "bin\\vs-2022\\x64\\Release DLL")

# The class that contains functions for me to use
class VSProgramObject(object):
    # Load the DLLs
    dep = ctypes.CDLL(dllDir + "\\antlr4-runtime.dll", winmode=0)
    script = ctypes.CDLL(dllDir + "\\ANTLR4_GENERATION.dll", winmode=0)

    # Initialise
    def __init__(self):
        self.obj = self.script.createStorage()
        return

    # Delete (for memory safety)
    def __del__(self):
        return self.script.deleteStorage(self.obj)

    # Add a new program
    def add(self, name: str, text: str):
        return self.script.addProgram(self.obj, name, text)

    # Delete a program
    def remove(self, name: str):
        return self.script.removeProgram(self.obj, name)

    # Execute the programs in parallel
    def run(self):
        return self.script.executePrograms(self.obj)

    # Call for the programs to all stop running
    def kill(self):
        return self.script.killPrograms(self.obj)