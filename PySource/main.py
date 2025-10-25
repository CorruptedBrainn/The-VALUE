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
script = """call_native(1: "Start"); // Start
call_native(1: "help??"); // help??
func absolute_value(var n->int)->int {
	if (n < 0) return n * -1;
	return n;
}

call_native(1: "wtf"); // wtf

class Coordinate {
	static var x_c->int = 0;
	static var y_c->int = 0;

	func x()->int {return x_c;}
	func y()->int {return y_c;}
}

call_native(1: 2 + 3); // 5
if (2 > 3) { // false
	call_native(1: "2 is greater than 3");
}
else { // true
	call_native(1: "2 is not greater than 3"); // 2 is not greater than 3
}
var x->int = 0;
while (x < 10) {
	call_native(1: x); // 0 1 2 3 4 5 6 7 8 9
	x++;
}
var y->array<int> = {1, 2, 1 + 2};
call_native(1: y); // {1,2,3}
call_native(1: {4, 5, 10 - 4}); // {4,5,6}
call_native(1: y + {4, 5, 10 - 4}); // {1,2,3,4,5,6}
call_native(1: y[x % 3]); // 2
for (var i->int = 0; i < 3; i++) {
	call_native(1: y[i]); // 1 2 3
}
y = y + {4, 5, 10 - 4, 7};
call_native(1: y); // {1,2,3,4,5,6,7}
for (var n->int : y) {
	call_native(1: n); // 1 2 3 4 5 6 7
}
var alphabet->list<str> = {"beta", "alpha", "delta", "echo", "charlie", "foxtrot"};
call_native(1: alphabet); // {alpha beta charlie delta echo foxtrot}
call_native(1: "alpha" < "beta"); // 1
call_native(1: "beta" < "charlie"); // 1
call_native(1: "charlie" < "alpha"); // 0
var t->int = absolute_value(x);
call_native(1: t); // 10
call_native(1: absolute_value(-20)); // 20
var my->Coordinate;
var them->Coordinate = {1, 2};
call_native(1: my.x_c); // 0
call_native(1: my.y()); // 0
them.x_c = 20;
my.y_c = them.x();
them.x_c = 18;
call_native(1: my.y_c); // 20
call_native(1: them.x()); // 18
return;"""

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
"""

#n = 1

def temp_print(inp: int)->int:
	#global n
	#print(f"Count: {n} - {inp}")
	#n += 1
	return inp

class SegmentTree:
	def __init__(self, vec:list[list], op = lambda lhs, rhs: temp_print(lhs + rhs)):
		self.vec = vec
		self.N_x = int(len(vec) / 2) - 1
		self.N_y = int(len(vec[0]) / 2) - 1 if self.N_x > 0 else 0
		self.op = op
		return

	@classmethod
	def construct(cls, x:int, y:int, val, op = lambda lhs, rhs: temp_print(lhs + rhs)):
		vec:list[list] = list(list(val for _ in range(y * 2)) for _ in range(x * 2))
		return cls(vec, op)

	def update(self, pos_x:int, pos_y:int, val):
		return self.update_x(0, pos_x, pos_y, 0, self.N_x, val)

	def update_x(self, idx_x:int, pos_x:int, pos_y:int, l:int, r:int, val):
		if l == r: return self.update_y(idx_x, 0, pos_y, 0, self.N_y, val)
		m = int((l + r) / 2)
		if pos_x <= m: return self.op(self.update_y(idx_x, 0, pos_y, 0, self.N_y, val), self.update_x(idx_x + 1, pos_x, pos_y, l, m, val))
		else: return self.op(self.update_y(idx_x, 0, pos_y, 0, self.N_y, val), self.update_x(idx_x + 2 * (m - l + 1), pos_x, pos_y, m + 1, r, val))

	def update_y(self, idx_x:int, idx_y:int, pos_y:int, l:int, r:int, val):
		if l == r:
			self.vec[idx_x][idx_y] = self.op(self.vec[idx_x][idx_y], val)
			return self.vec[idx_x][idx_y]
		m = int((l + r) / 2)
		if pos_y <= m:
			self.vec[idx_x][idx_y] = self.op(self.update_y(idx_x, idx_y + 1, pos_y, l, m, val), self.vec[idx_x][idx_y + 2 * (m - l + 1)])
			return self.vec[idx_x][idx_y]
		else:
			self.vec[idx_x][idx_y] = self.op(self.vec[idx_x][idx_y + 1], self.update_y(idx_x, idx_y + 2 * (m - l + 1), pos_y, m + 1, r, val))
			return self.vec[idx_x][idx_y]

	def query(self, pos_xl:int, pos_yl:int, l:int):
		return self.query_x(0, pos_xl, pos_xl + l - 1, pos_yl, pos_yl + l - 1, 0, self.N_x)

	def query_c(self, pos_xl:int, pos_xr:int, pos_yl:int, pos_yr:int):
		return self.query_x(0, pos_xl, pos_xr, pos_yl, pos_yr, 0, self.N_x)

	def query_x(self, idx_x:int, pos_xl:int, pos_xr:int, pos_yl:int, pos_yr:int, l:int, r:int):
		if pos_xl <= l and r <= pos_xr: return self.query_y(idx_x, 0, pos_yl, pos_yr, 0, self.N_y)
		if r < pos_xl or pos_xr < l: return 0
		m = int((l + r) / 2)
		return self.op(self.query_x(idx_x + 1, pos_xl, pos_xr, pos_yl, pos_yr, l, m), self.query_x(idx_x + 2 * (m - l + 1), pos_xl, pos_xr, pos_yl, pos_yr, m + 1, r))

	def query_y(self, idx_x:int, idx_y:int, pos_yl:int, pos_yr:int, l:int, r:int):
		if pos_yl <= l and r <= pos_yr: return self.vec[idx_x][idx_y]
		if r < pos_yl or pos_yr < l: return 0
		m = int((l + r) / 2)
		return self.op(self.query_y(idx_x, idx_y + 1, pos_yl, pos_yr, l, m), self.query_y(idx_x, idx_y + 2 * (m - l + 1), pos_yl, pos_yr, m + 1, r))

test = """
import __array

class SegmentTree {
	static var vec->array<array<int>> = {{}};
	static var N_x->int = 0;
	static var N_y->int = 0;
	//static var n->int = 1;

	func op(var lhs->int, var rhs->int)->int {
		//call_native(1: n);
		//call_native(1: lhs + rhs);
		//call_native(1: "----------");
		//n++;
		return lhs + rhs;
	}

	func init(var arr->array<array<int>>)->void {
		vec = arr;
		N_x = arr.size() / 2 - 1;
		if (!arr.empty()) N_y = arr[0].size() / 2 - 1;
		return;
	}

	func construct(var x->int, var y->int, var val->int)->void {
		N_x = x - 1;
		N_y = y - 1;
		vec.clear();
		for (var i->int = 0; i < x * 2; i++) {
			vec.append({});
			for (var j->int = 0; j < y * 2; j++) {
				vec[i].append(val);
			}
		}
		return;
	}

	func update(var pos_x->int, var pos_y->int, var val->int)->int {
		return update_x(0, pos_x, pos_y, 0, N_x, val);
	}

	func update_x(var idx_x->int, var pos_x->int, var pos_y->int, var l->int, var r->int, var val->int)->int {
		if (l == r) return update_y(idx_x, 0, pos_y, 0, N_y, val);
		var m->int = (l + r) / 2;
		if (pos_x <= m) return op(update_y(idx_x, 0, pos_y, 0, N_y, val), update_x(idx_x + 1, pos_x, pos_y, l, m, val));
		else return op(update_y(idx_x, 0, pos_y, 0, N_y, val), update_x(idx_x + 2 * (m - l + 1), pos_x, pos_y, m + 1, r, val));
	}

	func update_y(var idx_x->int, var idx_y->int, var pos_y->int, var l->int, var r->int, var val->int)->int {
		if (l == r) return vec[idx_x][idx_y] = op(vec[idx_x][idx_y], val);
		var m->int = (l + r) / 2;
		if (pos_y <= m) return vec[idx_x][idx_y] = op(update_y(idx_x, idx_y + 1, pos_y, l, m, val), vec[idx_x][idx_y + 2 * (m - l + 1)]);
		else return vec[idx_x][idx_y] = op(vec[idx_x][idx_y + 1], update_y(idx_x, idx_y + 2 * (m - l + 1), pos_y, m + 1, r, val));
	}

	func query(var pos_xl->int, var pos_yl->int, var l->int)->int {
		return query_x(0, pos_xl, pos_xl + l - 1, pos_yl, pos_yl + l - 1, 0, N_x);
	}

	func query_c(var pos_xl->int, var pos_xr->int, var pos_yl->int, var pos_yr->int)->int {
		return query_x(0, pos_xl, pos_xr, pos_yl, pos_yr, 0, N_x);
	}

	func query_x(var idx_x->int, var pos_xl->int, var pos_xr->int, var pos_yl->int, var pos_yr->int, var l->int, var r->int)->int {
		if (pos_xl <= l && r <= pos_xr) return query_y(idx_x, 0, pos_yl, pos_yr, 0, N_y);
		if (r < pos_xl || pos_xr < l) return 0;
		var m->int = (l + r) / 2;
		return op(query_x(idx_x + 1, pos_xl, pos_xr, pos_yl, pos_yr, l, m), query_x(idx_x + 2 * (m - l + 1), pos_xl, pos_xr, pos_yl, pos_yr, m + 1, r));
	}

	func query_y(var idx_x->int, var idx_y->int, var pos_yl->int, var pos_yr->int, var l->int, var r->int)->int {
		if (pos_yl <= l && r <= pos_yr) return vec[idx_x][idx_y];
		if (r < pos_yl || pos_yr < l) return 0;
		var m->int = (l + r) / 2;
		return op(query_y(idx_x, idx_y + 1, pos_yl, pos_yr, l, m), query_y(idx_x, idx_y + 2 * (m - l + 1), pos_yl, pos_yr, m + 1, r));
	}
}

var segTree->SegmentTree;
segTree.construct(10, 10, 0);
var score->int = 0;
segTree.update(0, 0, 1);
segTree.update(1, 1, 1);
segTree.update(0, 1, 1);
score += segTree.query(0, 1, 1);
segTree.update(1, 1, -1);
score += segTree.query(0, 0, 2);
segTree.update(5, 3, 2);
segTree.update(8, 6, 4);
segTree.update(2, 1, 1);
score += segTree.query(5, 5, 4);
segTree.update(8, 6, -2);
score += segTree.query(2, 1, 6);
call_native(1: score);
return;"""

# TESTING STUFF
segTree = SegmentTree.construct(10, 10, 0)
score = 0
segTree.update(0, 0, 1)
segTree.update(1, 1, 1)
segTree.update(0, 1, 1)
score += segTree.query(0, 1, 1)
segTree.update(1, 1, -1)
score += segTree.query(0, 0, 2)
segTree.update(5, 3, 2)
segTree.update(8, 6, 4)
segTree.update(2, 1, 1)
score += segTree.query(5, 5, 4)
segTree.update(8, 6, -2)
score += segTree.query(2, 1, 6)
print(score)

from native_wrapper import ValuescriptCompiler
ValuescriptCompiler.RunScriptOnce(test, "temp")
breakpoint()