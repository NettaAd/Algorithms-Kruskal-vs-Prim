#include "Graph.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//						Graph						//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

Graph::Graph() : size(0), edges_num(0) {}
Graph::~Graph() 
{
	for (int i = 0; i < size; i++)
		array[i].adj.DeleteList();
}

Graph* Graph::MakeEmptyGraph(int n)
{
	size = n;

	for (int i = 1; i <= size; i++)
		array.push_back({ i });
	
	return this;
}
int Graph::FindEdgeWight(int u, int v)
{
	for (int i = 0; i < edges_num; i++)
	{
		if (Edges[i].from_ver == u && Edges[i].to_ver == v)
			return Edges[i].wight;

		if (Edges[i].from_ver == v && Edges[i].to_ver == u)
			return Edges[i].wight;
	}
	return NOT_FOUND;
}
Edge& Graph::findEdge(int u, int v)
{  
	// we can serch the edge from u to v or the edge from v to u
	List* adj = GetAdjList(u);
	for (Node* curr = adj->begin(); curr != nullptr; curr = curr->next)
		if (curr->e.to_ver == v)
			return curr->e;
}
Edge* Graph::createEdge(int from_ver, int to_ver, int wight)
{
	Edge* e = new Edge;

	e->from_ver = from_ver;
	e->to_ver = to_ver;
	e->wight = wight;

	e->mark = false;
	e->my_copy = nullptr;

	return e;
}

void Graph::AddEdge(int u, int v, int wight)
{
	Edges.push_back({ u, v, wight });
	edges_num++;

	Edge* u_v = createEdge(u, v, wight);
	Edge* v_u = createEdge(v, u, wight);

	array[u - 1].adj.push_front(*u_v);
	array[u - 1].pos = array[u - 1].adj.begin();

	array[v - 1].adj.push_front(*v_u);
	array[v - 1].pos = array[v - 1].adj.begin();

	array[v - 1].adj.begin()->e.my_copy = &array[u - 1].adj.begin()->e;
	array[u - 1].adj.begin()->e.my_copy = &array[v - 1].adj.begin()->e;

	delete v_u;
	delete u_v;
}

void Graph::removeFromList(int u, int v)
{
	List* adj = GetAdjList(u);

	if (adj->begin()->e.to_ver == v)
	{
		adj->DeleteListHead();
	}
	else
	{
		for (Node* curr = adj->begin(); curr != nullptr; curr = curr->next)
		{
			if (curr->next->e.to_ver == v)
			{
				adj->DeleteAfter(curr);
				break;
			}
		}
	}

}
void Graph::removeFromVecor(int u, int v)
{
	vector<Edge>::iterator i;
	for (i = Edges.begin(); i != Edges.end(); i++)
	{
		if ((i->from_ver == u && i->to_ver == v) || (i->from_ver == v && i->to_ver == u))
		{
			Edges.erase(i);
			break;
		}
	}
}

void Graph::RemoveEdge(int u, int v)
{
	edges_num--;
	removeFromList(u, v);
	removeFromList(v, u);
	removeFromVecor(u, v);
}
void Graph::Visit(int u, int& count)
{
	Color[u] = GRAY;
	count++;

	for (Node* curr = getPos(u); curr != nullptr; curr = curr->next)
	{
		if (!curr->e.mark)
		{
			curr->e.mark = curr->e.my_copy->mark = true;
			int v = curr->e.to_ver;

			if (Color[v] == WHITE)
				Visit(v, count);	
		}
	}
	
	Color[u] = BLACK;
}
void Graph::initMark()
{
	for (int i = 1; i <= size; i++)
	{
		List* adj = GetAdjList(i);
		for (Node* curr = adj->begin(); curr != nullptr; curr = curr->next)
			curr->e.mark = curr->e.my_copy->mark = false;
	}
}
void Graph::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i].name << "n.list:" << endl;
		List* adj = GetAdjList(array[i].name);
		for (Node* curr = adj->begin(); curr != nullptr; curr = curr->next)
		{
			cout << curr->e.from_ver << "," << curr->e.to_ver;
			cout << "  my copy: " << curr->e.my_copy->from_ver << "," << curr->e.my_copy->to_ver << endl;
		}
	}
}
bool Graph::IsAdjacent(int u, int v)
{
	List* adj = GetAdjList(u);

	for (Node* curr = adj->begin(); curr != nullptr; curr = curr->next)
		if (curr->e.to_ver == v)
			return true;

	return false;
}
bool Graph::IsNotConectedGraph()
{
	//init
	Color.clear();
	Color.push_back(NOT_DEFINED); // NO VER 0
	for (int i = 1; i <= size; i++)
		Color.push_back(WHITE);

	for (int i = 0; i < size; i++)
		array[i].pos = array[i].adj.begin();

//	print();

	int count = 0;
	Visit(1, count);

	if (count == size)
		return false;
	else
		return true;
}
bool Graph::isBridge(int u, int v)
{
	initMark();
	RemoveEdge(u, v);
	return IsNotConectedGraph();
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//						MST							//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

MST::MST() : Tree_Wight(0) {}

void MST::Find_MST_Wight()
{
	Tree_Wight = 0;
	for (unsigned int i = 0; i < Tree.size(); i++)
		Tree_Wight += Tree[i].wight;
}
bool MST::IsInTree(int u, int v)
{
	for (int i = 0; i < (int)Tree.size(); i++)
	{
		if (Tree[i].from_ver == v && Tree[i].to_ver == u)
			return true;
		else if (Tree[i].from_ver == u && Tree[i].to_ver == v)
			return true;
	}
	return false;
}

