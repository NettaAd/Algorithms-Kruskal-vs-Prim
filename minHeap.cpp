#include "MinHeap.h"
MinHeap::MinHeap() :size(0) {}

void MinHeap::heapify(vector<Pair> arr, int n, int i)
{
	int largest = i; // Initialize largest as root

	if (Left(i) < n   &&   	arr[Left(i)].min_wight < arr[largest].min_wight)    // If left child is larger than root
		largest = Left(i);

	if (Right(i) < n   &&  	arr[Right(i)].min_wight < arr[largest].min_wight)	// If right child is larger than largest so far
		largest = Right(i);

	if (largest != i) 	// If largest is not root
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest); 		// Recursively heapify the affected sub-tree
	}
}
void MinHeap::buildHeap(vector<Pair> arr, int n)
{
	size = n;

	int startIndex = (n / 2) - 1;

	for (int i = startIndex; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = 1; i <= n; i++)
		array.push_back(arr[i]);

	loc.push_back(nullptr); // no ver 0
	for (int i = 0; i < n; i++)
		loc.push_back(&array[i]);
}
void MinHeap::FixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	if (left < size		&& 	array[left].min_wight < array[node].min_wight)
		min = left;
	else
		min = node;

	if (right < size	&&	array[right].min_wight < array[min].min_wight)
		min = right;

	if (min != node)
	{
		swap(array[node], array[min]);

		int ver1 = array[node].ver;
		loc[ver1] = &array[node];

		int ver2 = array[min].ver;
		loc[ver2] = &array[min];

		FixHeap(min);
	}
}
void MinHeap::FixHeapUP(int ind)
{
	int parent_min = array[Parent(ind)].min_wight;
	int newKey = array[ind].min_wight;

	while (newKey < parent_min)
	{
		if (ind == 0)
			return;

		swap(array[ind], array[Parent(ind)]);

		int ver1 = array[Parent(ind)].ver;
		loc[ver1] = &array[Parent(ind)];

		int ver2 = array[ind].ver;
		loc[ver2] = &array[ind];

		ind = Parent(ind);
		parent_min = array[Parent(ind)].min_wight;
	}
}
void MinHeap::DecreaseKey(int ver, int newKey)
{
	int ind = loc[ver] - &array[0];
	array[ind].min_wight = newKey;

	int parent_min = array[Parent(ind)].min_wight;

	if (newKey < parent_min)
		FixHeapUP(ind);

	else if (array[ind].min_wight > findSmallestWightChild(ind))
		FixHeap(ind);
	
}

Pair MinHeap::DeleteMin()
{
	if (size < 1)
	{
		cout << "heap is empty!" << endl;
		exit(1);
	}

	Pair min = array[0];
	loc[0] = loc[1] = nullptr;

	size--;
	array[0] = array[size];
	loc[size + 1] = &array[0];

	FixHeap(0);

	return min;
}

int MinHeap::findSmallestWightChild(int ind)
{
	if (Left(ind) < 0)
		return Right(ind);

	if (Right(ind) > size)
		return Left(ind);

	int left_wight = array[Left(ind)].min_wight;
	int right_wight = array[Right(ind)].min_wight;

	if (left_wight < right_wight)
		return left_wight;
	else
		return right_wight;
}
bool MinHeap::isEmpty() 
{
	if (size == 0)
		return true;
	return false;
}