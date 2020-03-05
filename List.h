#pragma once
#include <iostream>
using namespace std;
class List
{
private:
	struct Node();
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

