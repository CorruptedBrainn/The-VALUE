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
call_native(1: 2 + 3);
if (2 > 3) {
	call_native(1: "2 is greater than 3");
}
else {
	call_native(1: "2 is not greater than 3");
}
var x->int = 0;
while (x < 10) {
	call_native(1: x);
	x++;
}
var y->array<int> = {1, 2, 1 + 2};
call_native(1: y);
call_native(1: {4, 5, 10 - 4});
call_native(1: y + {4, 5, 10 - 4});
call_native(1: y[x % 3]);
"""

from native_wrapper import ValuescriptCompiler
compiler = ValuescriptCompiler.ScriptCompilerClass()
compiler.addScript(script, "temp")
breakpoint()

# Check that this is the startpoint for execution
if __name__ == "__main__":
	package = DataPackage()
	app = TVApplication(package)
	game = GameObject(app)
	app.start() # RIP Braincells