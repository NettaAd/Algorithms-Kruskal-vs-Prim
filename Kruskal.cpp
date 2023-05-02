#include "Kruskal.h"


// ~~~~~~~~~~~ kruskal 1 ~~~~~~~~~~~~~~~~ //

int partition(vector<Edge>& arr, int start, int end)
{
	int pivot = arr[start].wight;

	int count = 0;
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i].wight <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex)
	{
		while (arr[i].wight <= pivot)
			i++;

		while (arr[j].wight > pivot)
			j--;

		if (i < pivotIndex && j > pivotIndex)
			swap(arr[i++], arr[j--]);
	}

	return pivotIndex;
}
void QuickSort(vector<Edge>& arr, int start, int end)
{
	if (start >= end)
		return;

	int p = partition(arr, start, end); 	// partitioning the array

	QuickSort(arr, start, p - 1); 	// Sorting the left part
	QuickSort(arr, p + 1, end); 	// Sorting the right part
}
MST Kruskal(Graph& graph) //139
{
	MST Res;
	DisjointSets S;
	vector<Edge> Edges_arr, F = {}; // קבוצה מבטיחה
	int m, n;

	m = graph.getEdgesNum();
	n = graph.getVerticesNum();
	Edges_arr = graph.getEdgesArray();

	if (!graph.getEdgesIsSorted())
	{
		QuickSort(Edges_arr, 0, m - 1);
		graph.setSortedEdgesArray(Edges_arr);
		graph.setEdgesIsSorted();
	}

	for (int i = 1; i <= n; i++)
		S.MakeSets(i);

	for (int i = 0; i < m; i++)
	{
		int u_parent = S.Find(Edges_arr[i].to_ver);
		int v_parent = S.Find(Edges_arr[i].from_ver);

		if (u_parent != v_parent)
		{
			F.push_back(Edges_arr[i]);
			S.Union(u_parent, v_parent);
		}
	}

	Res.updateTree(F);
	Res.Find_MST_Wight();

	return Res;
}

// ~~~~~~~~~~~ kruskal 2 ~~~~~~~~~~~~~~~~ //

void Kruskal2(Graph& G, MST& kruskal_tree, string& k2, int u, int v)
{
	if (!G.IsAdjacent(u, v))
		k2 = "Invalid input";
	else
	{
		if (kruskal_tree.IsInTree(u, v)) // u--v in the tree
		{
			if (!G.isBridge(u, v))
			{
				MST Kruskal2 = Kruskal(G);
				k2 = to_string(Kruskal2.getWight());
			}
			else
				k2 = "No MST";
		}
		else
			k2 = to_string(kruskal_tree.getWight());
	}

}