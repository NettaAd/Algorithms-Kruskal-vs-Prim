#ifndef GRAPH_H
#define GRAPH_H

#include "List.h"

#define NOT_FOUND -1
#define NOT_DEFINED -1

#define WHITE 10
#define GRAY  11
#define BLACK 12

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//						Graph						//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

typedef struct vertice
{
	int name;
	Node* pos;
	List adj;

}Vertice;

class Graph
{
private:
	int size; // number of vertices in graph
	int edges_num;
	vector<Vertice> array;
	vector<int> Color;
	vector<Edge> Edges;
	bool EdgesIsSorted = false;

public:
	Graph();
	~Graph();

	Graph* MakeEmptyGraph(int the_graph_size);

	int getVerticesNum()    { return size;		    }
	int getEdgesNum()       { return edges_num;		}

	void setEdgesIsSorted() { EdgesIsSorted = true; }
	bool getEdgesIsSorted() { return EdgesIsSorted; }

	void setSortedEdgesArray(vector<Edge>& e) { Edges = e;	  }
	vector<Edge>& getEdgesArray()             { return Edges; }

	vector<Vertice> getArray()   { return array; }
	List* GetAdjList(int u)	     { return &array[u - 1].adj; }

	Node* getPos(int u)			 { return array[u - 1].pos; }
	void setPos(int u, Node* it) { array[u - 1].pos = it;   }

	Edge& findEdge(int u, int v);
	Edge* createEdge(int from_ver, int to_ver, int wight);

	int FindEdgeWight(int u, int v);
	void AddEdge(int u, int v, int wight);
	void RemoveEdge(int u, int v);
	void Visit(int ver, int& count);
	void initMark();

	bool IsAdjacent(int u, int v);
	bool isBridge(int u, int v);
	bool IsNotConectedGraph();

	void removeFromList(int u, int v);
	void removeFromVecor(int u, int v);
	void print();

};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//						MST							//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

class MST
{
private:
	vector<Edge> Tree;
	int Tree_Wight;

public:
	MST();
	void Find_MST_Wight();
	bool IsInTree(int u, int v);

	void updateTree(vector<Edge> t) { Tree = t; }
	void AddEdge(int u, int v, int wight) { Tree.push_back({ u,v,wight }); }
	int getWight() { return Tree_Wight; }
	vector<Edge> getTree() { return Tree; }
};


#endif