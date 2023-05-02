#ifndef PRIM_H
#define PRIM_H

#include "Graph.h"
#include "minHeap.h"

void initInT(vector<bool>& inT, int n);
void initMin(vector<Pair>& min, int n);
void initParantArr(vector<int>& parent, int n);
MST Prim_algo(Graph& graph);

#endif