#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "Graph.h"
#include "Sets.h"

// ~~~~~~~~~~~ kruskal 1 ~~~~~~~~~~~~~~~~ //

int partition(vector<Edge>& arr, int start, int end);
void QuickSort(vector<Edge>&  arr, int start, int end);
MST Kruskal(Graph& graph);

// ~~~~~~~~~~~ kruskal 2 ~~~~~~~~~~~~~~~~ //

void Kruskal2(Graph& G, MST& kruskal_tree, string& k2, int u, int v);

#endif