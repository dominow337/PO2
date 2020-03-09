#pragma once
#include <iostream>
#include <string>
using namespace std;
class List
{
private:
	struct Node()
	{
		string word;
		Node* next;
		Node();
	};
	Node* find(const size_t);
	void pop(const size_t);
	void push(const Point&, const size_t);
public:
	enum Error
	{
		Success,
		Index_Out_Of_Bounds,
		List_Empty
	};
	List();
	~List();
	Node* first;
	pop_back();
	push_back(const Point&);
	find(const Point&, const size_t);
	insert(const Point&, const size_t);
};

