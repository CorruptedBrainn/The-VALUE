"""
Name: main.py
Version: 0.0.3-alpha
Description: Program execution starts and ends here -- this file contains and manages the overall top level application objects
Author: Nicolas Martens
"""

from interface import TVApplication
from data import DataPackage
from game import GameObject

class node:
	def __init__(self):
		self.LR:int = 0
		self.wLR:int = 0
		self.LwR:int = 0
		self.wLwR:int = 0
		return

	def best(self):
		return max(max(self.LR, self.wLR), max(self.LwR, self.wLwR))

def add(lhs:node, rhs:node)->node:
	ret = node()
	ret.LR = max(max(lhs.LR + rhs.wLR, lhs.LwR + rhs.LR), lhs.LwR + rhs.wLR)
	ret.LwR = max(max(lhs.LR + rhs.wLwR, lhs.LwR + rhs.LwR), lhs.LwR + rhs.wLwR)
	ret.wLR = max(max(lhs.wLR + rhs.wLR, lhs.wLwR + rhs.LR), lhs.wLwR + rhs.wLR)
	ret.wLwR = max(max(lhs.wLR + rhs.wLwR, lhs.wLwR + rhs.LwR), lhs.wLwR + rhs.wLwR)
	return ret;

class SegTree:
	def __init__(self, N):
		self.N:int = N
		self.v:list[node] = list(node() for _ in range(2 * N))
		return

	def update(self, pos:int, val:node)->node:
		return self.update_F(0, pos, 0, self.N - 1, val)

	def update_F(self, i:int, pos:int, l:int, r:int, val:node)->node:
		if l == r:
			self.v[i] = val
			return self.v[i]
		m = int((l + r) / 2)
		if pos <= m:
			self.v[i] = add(self.update_F(i + 1, pos, l, m, val), self.v[i + 2 * (m - l + 1)])
			return self.v[i]
		else:
			self.v[i] = add(self.v[i + 1], self.update_F(i + 2 * (m - l + 1), pos, m + 1, r, val))
			return self.v[i]

	def query(self, ql:int, qr:int)->node:
		return self.query_F(0, ql, qr, 0, self.N - 1)

	def query_F(self, i:int, ql:int, qr:int, l:int, r:int)->node:
		if ql <= l and r <= qr: return self.v[i]
		if r < ql or qr < l: return node()
		m = int((l + r) / 2)
		return add(self.query_F(i + 1, ql, qr, l, m), self.query_F(i + 2 * (m - l + 1), ql, qr, m + 1, r))

# Take 1
print("-- TAKE 1 --")
N = 6
Q = 5
temp = node()
h = SegTree(N)
data = [9, 3, 6, 11, 2, 5]
queries = [
	(3, 5),
	(0, 1),
	(2, 3),
	(0, 100),
	(3, 11)
]
for i in range(len(data)):
	temp.LR = data[i]
	h.update(i, temp)
print(h.query(0, N - 1).best())
for x in queries:
	temp.LR = x[1]
	print(h.update(x[0], temp).best())
print()

# Take 2
print("-- TAKE 2 --")
N = 7
Q = 4
temp = node()
h = SegTree(N)
data = [10, 1, 2, 6, 3, 9, 8]
queries = [
	(5, 1),
	(5, 9),
	(2, 15),
	(2, 2)
]
for i in range(len(data)):
	temp.LR = data[i]
	h.update(i, temp)
print(h.query(0, N - 1).best())
for x in queries:
	temp.LR = x[1]
	print(h.update(x[0], temp).best())
print()

# Take 3
print("-- TAKE 3 --")
N = 1
Q = 2
temp = node()
h = SegTree(N)
data = [5]
queries = [
	(0, 3),
	(0, 10)
]
for i in range(len(data)):
	temp.LR = data[i]
	h.update(i, temp)
print(h.query(0, N - 1).best())
for x in queries:
	temp.LR = x[1]
	print(h.update(x[0], temp).best())
print()

# temp
script = """
call_native(1, 1: "Won't work: class implementation is done statically");
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