#include <iostream>

#include "antlr4-runtime.h"
#include "..\generated\ValuescriptLexer.h"
#include "..\generated\ValuescriptParser.h"
#include "Listener.cpp"

#include <Windows.h>

#pragma execution_character_set("utf-8")

using namespace valuescriptantlrgeneration;
using namespace antlr4;

int main(int argc, const char * argv[]) {

  ANTLRInputStream input("193\na = 5\nb = 6\na + b * 2\n(1 + 2) * 3");
  ValuescriptLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  ValuescriptParser parser(&tokens);
  ValuescriptPreListener preprocess;
  ValuescriptListener listener;

  parser.addParseListener(&preprocess);
  tree::ParseTree* tree = parser.file();
  tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

  return 0;
}

/*
TEST:

@typenames: data
segment_tree {
	size->int = 0;
	tree->array<data> = {};

	update(pos->int, val->data, i->int = 0, l->int = 0, r->int = size - 1)->data {
		if (l == r) return tree[i] += val;
		m->int = (l + r ) / 2;
		if (pos <= m) return tree[i] = update(pos, val, i + 1, l, m) + tree[i + 2 * (m - l + 1)];
		else return tree[i] = tree[i + 1] + update(pos, val, i + 2 * (m - l + 1), m + 1, r);
	}

	query(posl->int, posr->int, i->int = 0, l->int = 0, r->int = size - 1)->data {
		if (posl <= l && r <= posr) return tree[i];
		if (r < posl || posr < l) return NULL;
		m->int = (l + r) / 2;
		return query(posl, posr, i + 1, l, m) + query(posl, posr, i + 2 * (m - l + 1), m + 1, r);
	}
}

static segtree->segment_tree<int>;
print(segtree.query(2, 4));
*/