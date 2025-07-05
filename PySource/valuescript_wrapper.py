"""import os
from ctypes import CDLL
from random import sample

pythonpath = str(os.environ.get("PYTHONPATH"))
splitpaths = pythonpath.split(os.pathsep)
searchpaths = [path for path in splitpaths if "x64\\Debug" in path or "x64\\Release" in path]

sampleDijkstra = """"""
var<array<array<pair<int, int>>>> adj;
var<int> n = 0;
var<array<int>> distances(n, 100000);
var<priority_queue<pair<int, int>>> next;
var<int> current = 0;
distances[current] = 0;
next.push({0, current});
while(!next.empty()) {
    current = next.top().second;
    next.pop();
    for (int i = 0; i < adj[current].size(); i = i + 1) {
        var<pair<int, int>> node = adj[current][i];
        if (distances[current] + node.second < distances[node.first]) {
            distances[node.first] = distances[current] + node.second;
            next.push({distances[node.first * -1, node.first]});
        }
    }
}
""""""

class VScompiler(object):
    script = CDLL(searchpaths[0] + '\\valuescript.dll', winmode=0)

    # Rewrite it so we go:
    # VScompiler (rename it) -> init, to create the overall management system
    # Make each file tied to a unique object stored within the compiler
    # Can have references to the thingy because why not
    # Then within the overall compiler trigger a run command to manage threads from there

    def __init__(self):
        self.obj = self.script.createProgram()
        # Do add something to test parsing temporarily
        self.script.analyse(self.obj, sampleDijkstra)
        return
    
    def compile(self, fileContents:str) -> int:
        help = self.script.analyse(self.obj, fileContents)
        # Error stuff
        return help"""