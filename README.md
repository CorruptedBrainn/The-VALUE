# The VALUE

Project description

# Achievement Standard

## Accessing Source Code

I did not write all of the code in this project. Some of it was generated through the usage of programs and dependencies. The files I created manually are:

* Valuescript C++ Files (ANTLR4\_GENERATION Folder):

  * main.cpp
  * ValuescriptRuntime.cpp

* Various C++ Files (Cpp Functions Folder):

  * Environment.cpp
  * Environment.h

* Python Files (PySource Folder):

  * cpp\_wrapper.py
  * dialog\_container.py
  * file\_helper.py
  * game\_container.py
  * home\_container.py
  * main.py
  * valuescript\_wrapper.py
  * widget\_helper.py

* Valuescript Code (ValuescriptImports Folder):

  * N/A

* Grammar Specification:

  * ValuescriptLexer.g4
  * ValuescriptParser.g4

The following code was not written by me, but was generated through work I did using external tools:

* Valuescript Class Template Files (generated Folder):

  * ValuescriptLexer.cpp
  * ValuescriptLexer.h
  * ValuescriptParser.cpp
  * ValuescriptParser.h
  * ValuescriptParserBaseVisitor.cpp
  * ValuescriptParserBaseVisitor.h
  * ValuescriptParserVisitor.cpp
  * ValuescriptParserVisitor.h

* Interface Files (PySource/Widgets Folder):

  * editor.ui
  * fleet\_control.ui
  * home\_page.ui
  * journal.ui
  * main\_game.ui
  * save\_page.ui
  * save\_slot\_widget.ui
  * settings\_dialog.ui
  * tech\_tree.ui
  * the\_expanse.ui
  * unit\_widget\_small.ui

The code in the folder named ANTLR4\_RUNTIME is a dependancy called ANTLR4. I did not write any of the code in here, and none of it is mine.

## Files

There are multiple files in the project as a whole.

* **Source Code can be found in .py .cpp and .h files.**

  * main.cpp is the startpoint for anything Valuescript related.
  * ValuescriptRuntime.cpp contains the C++ counterparts / commands / executions for Valuescript. It defines behaviour for the language.
  * Environment.cpp contains functions to help generate the game environment.
  * Environment.h contains the function signatures to export these to the DLLs.
  * cpp\_wrapper.py contains the class that calls the general helper C++ functions from the DLLs.
  * dialog\_container.py contains the classes that have any popups or dialogs in the app.
  * file\_helper.py manages saving to the file system.
  * game\_container.py contains the class where the main game state is.
  * global\_storage.py has global variables so I can communicate across scripts.
  * home\_container.py has the class that shows and manages the main / startup page.
  * main.py is where application execution begins and ends.
  * valuescript\_wrapper.py contains the class that allows me to call the Valuescript C++ functions from DLLs.
  * widget\_helper.py manages switching widgets easily with functions, allowing me to avoid repeated code.

# Running the Project

## Installation

If you don't have the source code, download it from the GitHub repository. You should have these files in the project folder:

* C++ DLL Libraries (bin/vs-2022/x64/Release DLL Folder):

  * ANTLR4\_GENERATION.dll
  * ANTLR4\_GENERATION.exp
  * ANTLR4\_GENERATION.lib
  * ANTLR4\_GENERATION.pdb
  * antlr4-runtime.dll
  * antlr4-runtime.exp
  * antlr4-runtime.lib
  * antlr4-runtime.pdb
  * Cpp Functions.dll
  * Cpp Functions.exp
  * Cpp Functions.lib
  * Cpp Functions.pdb

* Python Source Code (PySource Folder):

  * cpp\_wrapper.py
  * dialog\_container.py
  * file\_helper.py
  * game\_container.py
  * home\_container.py
  * main.py
  * valuescript\_wrapper.py
  * widget\_helper.py

* Interface Files (PySource/Widgets Folder):

  * editor.ui
  * fleet\_control.ui
  * home\_page.ui
  * journal.ui
  * main\_game.ui
  * save\_page.ui
  * save\_slot\_widget.ui
  * settings\_dialog.ui
  * tech\_tree.ui
  * the\_expanse.ui
  * unit\_widget\_small.ui

* Valuescript Code (ValuescriptImports Folder):

  * N/A

* Grammar Specification (Optional):

  * ValuescriptLexer.g4
  * ValuescriptParser.g4

## Dependancies

Additionally, the project has a few dependancies that must be installed using pip. Some of these are included in the source code (namely, ANTLR4), but others should be installed with the system. Ensure you have these dependancies installed with pip:

* antlr4-tools

  * > pip install antlr4-tools

  * Version 0.2.2 or later
  * Optional

* PySide6

  * > pip install pyside6

  * Version 6.9.1
  * Required for GUI

## Execution

The startpoint for execution is the file **main.py** found in the folder **PySource**. You can run this using whatever interactive Python program you need.

# Project Plan

## Todo

* Graphics

  * The final graphics for the game are unfinished.

* Playability

  * The full game functionality has yet to be implemented.
  * Unit, Tech Tree, Environment are all works in progress.
  * Music has not even been looked at.

* Storyline

  * I have yet to create a "storyline" for the game.

* Open Test

  * I want to open a test release, but that is not feasible yet.

## In Progress

* Valuescript

  * I need to implement arrays / lists / data structures in Valuescript.
  * I need to implement classes and other various functions.
  * I need a way to elegantly deal with Valuescript errors.
  * I have no method to output all data types to the Valuescript Console.
  * I have no method to merge the console with IDLE.

* Testing

  * I have yet to do a full scale system test. Various tests have been done.

* Documentation

  * I have yet to write a Valuescript Reference.
  * I am in the process of commenting the code.

* Data Storage

  * I need to revisit my storage system and improve it.

## Done

* Interface

  * Basic interfacing and navigation works.
  * Settings work.

* Valuescript

  * Basic variables and functions in Valuescript work.

* Environment

  * The environment has some generation.
