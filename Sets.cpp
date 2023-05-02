#include "Sets.h"

DisjointSets::DisjointSets()
{
	Arr.push_back({});
}
void DisjointSets::MakeSets(int x)
{
	Element elem;
	elem.parent = x;
	elem.size = 1;
	Arr.push_back(elem);
}
int DisjointSets::Find(int x) 
{
	// use path compression
	if (Arr[x].parent == x)
		return x;
	
	else
		return ( Arr[x].parent = Find(Arr[x].parent) );
	
}
void DisjointSets::Union(int repX, int repY) 
{
	// use union by size
	if (Arr[repX].size > Arr[repY].size)
	{
		Arr[repY].parent = repX;
		Arr[repX].size += Arr[repY].size;
	}
	else
	{
		Arr[repX].parent = repY;
		Arr[repY].size += Arr[repX].size;
	}
}