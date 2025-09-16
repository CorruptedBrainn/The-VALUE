"""
Name: main.py
Version: 0.0.3-alpha
Description: Program execution starts and ends here -- this file contains and manages the overall top level application objects
Author: Nicolas Martens
"""

from interface import TVApplication
from data import DataPackage

# Check that this is the startpoint for execution
if __name__ == "__main__":
	package = DataPackage()
	app = TVApplication(package)
	app.start()