#ifndef SETS_H
#define SETS_H
#include <iostream>
#include <vector>
using namespace std;

typedef struct elem
{
	int parent;
	int size;
}Element;

class DisjointSets
{
private:
	vector<Element> Arr;

public:
	DisjointSets();

	void MakeSets(int x);
	int Find(int x);
	void Union(int repX, int repY);
};
#endif
