#include "List.h"

void List::DeleteList()
{
	Node* current = head;
	Node* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		delete current;
		current = next;
	}

	head = nullptr;
}

void List::DeleteListHead()
{
	Node* next = head->next;
	delete head;
	head = next;
}
void List::DeleteAfter(Node* curr)
{
	Node* new_next = curr->next->next, * next = curr->next;
	delete next;
	curr->next = new_next;
}
void List::push_front(Edge& e) 
{
	Node* new_head = new Node;
	new_head->e = e;
	new_head->next = head;
	head = new_head;
}