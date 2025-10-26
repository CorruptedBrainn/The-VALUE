"""
Name: main.py
Version: 0.0.3-alpha
Description: Program execution starts and ends here -- this file contains and manages the overall top level application objects
Author: Nicolas Martens
"""

from interface import TVApplication
from data import DataPackage
from game import GameObject

class BIT:
	def __init__(self, N, M):
		self.N = N
		self.M = M
		self.tree = list(list(0 for _ in range(N)) for _ in range(M))
		return

	def band(self, i):
		return i & (i + 1)

	def bor(self, i):
		return i | (i + 1)

	def update(self, x, y, val):
		i = y
		while i < self.M:
			j = x
			while j < self.N:
				self.tree[i][j] += val
				j = self.bor(j)
			i = self.bor(i)
		return

	def query_2D(self, lx, rx, ly, ry):
		lx -= 1
		ly -= 1
		ret = self.query_1D(rx, ry)
		ret += self.query_1D(lx, ly)
		ret -= self.query_1D(lx, ry)
		ret -= self.query_1D(rx, ly)
		return ret

	def query_1D(self, x, y):
		ret = 0
		i = y
		while i >= 0:
			j = x
			while j >= 0:
				ret += self.tree[i][j]
				j = self.band(j) - 1
			i = self.band(i) - 1
		return ret

bruteforce = [
	(1, 2),
	(1, 3),
	(1, 4),
	(1, 5),
	(1, 6),
	(1, 7),
	(1, 8),
	(1, 9),
	(1, 10),
	(2, 1),
	(2, 2),
	(2, 3),
	(2, 4),
	(2, 5),
	(3, 1),
	(3, 2),
	(3, 3),
	(4, 1),
	(4, 2),
	(5, 1),
	(5, 2),
	(6, 1),
	(7, 1),
	(8, 1),
	(9, 1),
	(10, 1)
]

M_A = 6
N_A = 5
M_B = 10
N_B = 10
box_A = BIT(N_A, M_A)
box_B = BIT(N_B, M_B)
data_A = [
	[1, 4, 3, 6, 4],
	[9, 1, 8, 2, 1],
	[4, 6, 2, 3, 1],
	[1, 9, 3, 4, 2],
	[1, 8, 4, 8, 4],
	[3, 4, 1, 3, 1]
]
data_B = [
	[1, 9, 2, 6, 5, 9, 1, 6, 5, 8],
	[1, 9, 2, 5, 3, 9, 5, 7, 1, 5],
	[1, 9, 5, 6, 1, 1, 4, 1, 6, 1],
	[9, 5, 3, 8, 4, 2, 6, 4, 2, 4],
	[6, 2, 7, 4, 6, 3, 2, 4, 8, 3],
	[4, 7, 2, 4, 7, 8, 5, 8, 4, 7],
	[6, 2, 7, 4, 6, 2, 7, 4, 2, 8],
	[2, 7, 6, 4, 6, 2, 6, 2, 7, 4],
	[6, 3, 6, 2, 7, 4, 7, 2, 2, 6],
	[1, 4, 3, 1, 5, 4, 3, 1, 5, 4]
]
for y in range(M_A):
	for x in range(N_A):
		box_A.update(x, y, data_A[y][x])
for y in range(M_B):
	for x in range(N_B):
		box_B.update(x, y, data_B[y][x])
ret_A = 0
ret_B = 0
for p in bruteforce:
	for x in range(N_A + 1 - p[1]):
		for y in range(M_A + 1 - p[0]):
			if box_A.query_2D(x, x + p[1] - 1, y, y + p[0] - 1) == 10:
				ret_A += 1
	for x in range(N_B + 1 - p[1]):
		for y in range(M_B + 1 - p[0]):
			if box_B.query_2D(x, x + p[1] - 1, y, y + p[0] - 1) == 10:
				ret_B += 1
print(ret_A)
print(ret_B)

# temp
script = """
import __pair
import __array
import __list

class BIT {
	static var tree->array<array<int>> = {{}};
	static var N->int = 0;
	static var M->int = 0;

	func construct(var n->int, var m->int)->void {
		N = n;
		M = m;
		tree.clear();
		for (var y->int = 0; y < M; y++) {
			tree.append({});
			for (var x->int = 0; x < N; x++) {
				tree[y].append(0);
			}
		}
		return;
	}

	func band(var i->int)->int {
		return i & (i + 1);
	}

	func bor(var i->int)->int {
		return i | (i + 1);
	}

	func update(var x->int, var y->int, var val->int)->void {
		for (var i->int = y; i < M; i = bor(i)) {
			for (var j->int = x; j < N; j = bor(j)) {
				tree[i][j] += val;
			}
		}
	}

	func query_2D(var lx->int, var rx->int, var ly->int, var ry->int)->int {
		lx--;
		ly--;
		var ret->int = query_1D(rx, ry);
		ret += query_1D(lx, ly);
		ret -= query_1D(lx, ry);
		ret -= query_1D(rx, ly);
		return ret;
	}

	func query_1D(var x->int, var y->int)->int {
		var ret->int = 0;
		for (var i->int = y; i >= 0; i = band(i) - 1) {
			for (var j->int = x; j >= 0; j = band(j) - 1) {
				ret += tree[i][j];
			}
		}
		return ret;
	}
}

var bruteforce->list<pair<int, int>> = {
	{1, 2},
	{1, 3},
	{1, 4},
	{1, 5},
	{1, 6},
	{1, 7},
	{1, 8},
	{1, 9},
	{1, 10},
	{2, 1},
	{2, 2},
	{2, 3},
	{2, 4},
	{2, 5},
	{3, 1},
	{3, 2},
	{3, 3},
	{4, 1},
	{4, 2},
	{5, 1},
	{5, 2},
	{6, 1},
	{7, 1},
	{8, 1},
	{9, 1},
	{10, 1}
};

var M_A->int = 6;
var N_A->int = 5;
var M_B->int = 10;
var N_B->int = 10;
var box_A->BIT;
box_A.construct(N_A, M_A);
var data_A->array<array<int>> = {
	{1, 4, 3, 6, 4},
	{9, 1, 8, 2, 1},
	{4, 6, 2, 3, 1},
	{1, 9, 3, 4, 2},
	{1, 8, 4, 8, 4},
	{3, 4, 1, 3, 1}
};
for (var y->int = 0; y < M_A; y++) {
	for (var x->int = 0; x < N_A; x++) {
		box_A.update(x, y, data_A[y][x]);
	}
}
var ret_A->int = 0;
for (var p->pair<int, int> : bruteforce) {
	for (var x->int = 0; x + p.second() - 1 < N_A; x++) {
		for (var y->int = 0; y + p.first() - 1 < M_A; y++) {
			if (box_A.query_2D(x, x + p.second() - 1, y, y + p.first() - 1) == 10) {
				ret_A += 1;
			}
		}
	}
}
var box_B->BIT;
box_B.construct(N_B, M_B);
var data_B->array<array<int>> = {
	{1, 9, 2, 6, 5, 9, 1, 6, 5, 8},
	{1, 9, 2, 5, 3, 9, 5, 7, 1, 5},
	{1, 9, 5, 6, 1, 1, 4, 1, 6, 1},
	{9, 5, 3, 8, 4, 2, 6, 4, 2, 4},
	{6, 2, 7, 4, 6, 3, 2, 4, 8, 3},
	{4, 7, 2, 4, 7, 8, 5, 8, 4, 7},
	{6, 2, 7, 4, 6, 2, 7, 4, 2, 8},
	{2, 7, 6, 4, 6, 2, 6, 2, 7, 4},
	{6, 3, 6, 2, 7, 4, 7, 2, 2, 6},
	{1, 4, 3, 1, 5, 4, 3, 1, 5, 4}
};
for (var y->int = 0; y < M_B; y++) {
	for (var x->int = 0; x < N_B; x++) {
		box_B.update(x, y, data_B[y][x]);
	}
}
var ret_B->int = 0;
for (var p->pair<int, int> : bruteforce) {
	for (var x->int = 0; x + p.second() - 1 < N_B; x++) {
		for (var y->int = 0; y + p.first() - 1 < M_B; y++) {
			if (box_B.query_2D(x, x + p.second() - 1, y, y + p.first() - 1) == 10) {
				ret_B += 1;
			}
		}
	}
}
call_native(1, 1: ret_A);
call_native(1, 1: ret_B);
return;
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