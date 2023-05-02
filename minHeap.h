#ifndef __MINHEAP_H
#define __MINHEAP_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;
#define NOT_IN_HEAP -1

typedef struct pair
{
	int ver;        // the vertice outside of the tree
	int min_wight;  // the min wight to conect v to the tree

}Pair;

class MinHeap
{
private:
	int size;
	vector<Pair> array;
	vector<Pair*> loc;

	static int Parent(int node) { return (node - 1) / 2; }
	static int Left(int node) { return (2 * node) + 1; }
	static int Right(int node) { return (2 * node) + 2; }
	

public:
	MinHeap();

	bool isEmpty();

	void heapify(vector<Pair> arr, int n, int i);
	void buildHeap(vector<Pair> arr, int n);
	
	void FixHeap(int node);
	void FixHeapUP(int node);

	Pair DeleteMin();

	void DecreaseKey(int ver, int newKey);
	int findSmallestWightChild(int ind);

};
#endif



