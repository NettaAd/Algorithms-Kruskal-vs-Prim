#include "Prim.h"

#define NO_PARENT -1


void initInT(vector<bool>& inT, int n)
{
	inT.push_back(false);

	for (int i = 0; i < n; i++)
		inT.push_back(false);
}
void initMin(vector<Pair>& min, int n)
{
	min.push_back({ 0 ,INT32_MAX });

	for (int i = 1; i <= n; i++)
		min.push_back({ i ,INT32_MAX });


	min[1].min_wight = 0; // arbitrary initial vertex
}
void initParantArr(vector<int>& parent, int n)
{
	for (int i = 0; i <= n; i++)
		parent.push_back(NOT_IN_HEAP);
}

MST Prim_algo(Graph& graph)
{	
	MST Res;
	int n, m;

	MinHeap Q;
	vector<bool> inT;
	vector<int> parent;
	vector<Pair> min;

	m = graph.getEdgesNum();
	n = graph.getVerticesNum();

	initInT(inT, n);
	initMin(min, n);
	initParantArr(parent, n);

	Q.buildHeap(min, n);
	
	while (!Q.isEmpty())
	{
		Pair u = Q.DeleteMin();

		inT[u.ver] = true;

		List* Adj_u = graph.GetAdjList(u.ver);

		for (Node* curr = Adj_u->begin(); curr != nullptr; curr = curr->next)
		{
			int v = curr->e.to_ver;
			bool inTree = inT[v];
			
			if (!inTree && graph.FindEdgeWight(u.ver, v) < min[v].min_wight)
			{
				min[v].min_wight = graph.FindEdgeWight(u.ver, v);
				parent[v] = u.ver;
				Q.DecreaseKey(v, min[v].min_wight);	
			}
		}
	}

	for (int i = 1; i <= n; i++)
		Res.AddEdge(i, parent[i], min[i].min_wight);

	Res.Find_MST_Wight();

	return Res;
}