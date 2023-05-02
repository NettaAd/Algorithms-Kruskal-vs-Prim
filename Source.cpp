#include "Prim.h"
#include "Kruskal.h"
#include "Input_and_Output.h"

int main(int argc, char** argv)
{
	int u, v;
	Graph G;
	string k2, k1, p;

	getInput(G, argv, u, v);

	MST kruskal_tree = Kruskal(G);  
	k1 = to_string(kruskal_tree.getWight());

	MST prim_tree = Prim_algo(G);	
	p = to_string(prim_tree.getWight());

	Kruskal2(G, kruskal_tree, k2, u, v);

	wightsOutputMessage(argv[2], k1, p, k2);

	return 0;
}