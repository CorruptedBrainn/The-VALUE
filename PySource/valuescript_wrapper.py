import os
from ctypes import CDLL
from random import sample

pythonpath = str(os.environ.get("PYTHONPATH"))
splitpaths = pythonpath.split(os.pathsep)
searchpaths = [path for path in splitpaths if "x64\\Debug" in path or "x64\\Release" in path]

sampleDijkstra = """
create<array<array<pair<int, int>>>> adj;
create<int> n = 0;
create<array<int>> distances(n, 100000);
create<priority_queue<pair<int, int>>> next;
create<int> current = 0;
distances[current] = 0;
next.push({0, current});
while(!next.empty()) {
    current = next.top().second;
    next.pop();
    for (int i = 0; i < adj[current].size(); i = i + 1) {
        create<pair<int, int>> node = adj[current][i];
        if (distances[current] + node.second < distances[node.first]) {
            distances[node.first] = distances[current] + node.second;
            next.push({distances[node.first * -1, node.first]});
        }
    }
}
"""

class VScompiler(object):
    script = CDLL(searchpaths[0] + '\\valuescript.dll', winmode=0)

    def __init__(self):
        self.obj = self.script.createCompiler()
        # Do add something to test parsing temporarily
        self.script.translate(self.obj, sampleDijkstra)
        return
    
    def compile(self, fileContents:str) -> int:
        help = self.script.compile(self.obj, fileContents)
        # Error stuff
        return help