#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

typedef struct _edge
{
	int from_ver;
	int to_ver;
	int wight;

	bool mark;
	_edge* my_copy;

}Edge;

typedef struct node
{
	Edge e;
	node* next = nullptr;

}Node;

class List
{
private:
	Node* head;

public:
	List() { head = nullptr; }

	Node* begin() { return head; }

	void DeleteList();

	void DeleteListHead();
	void DeleteAfter(Node* curr);
	void push_front(Edge& e);

};

#endif // !LIST_H
