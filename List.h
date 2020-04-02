#pragma once
#include <vector>
#include "Point.h"
using namespace std;
class List
{
private:
	struct Node
	{
		Point point;
		Node* next;
		Node(const Point& p) : point(p.x, p.y, p.z), next(nullptr) {}
	};
	size_t size;
	Node* first;

	Node* find(const size_t);
	void push(const Point&, const size_t);
	void push(const List&, const size_t);
	void pop(const size_t);
	void multiply(List&, const size_t);
	const vector<Point> point;
	vector<Point> p;
public:
	List();
	List(const List&);
	~List();
	List(const vector<Point>&);
	

	enum Error
	{
		SUCCESS,
		LIST_EMPTY,
		OUT_OF_BOUNDS //warunki
	};
	Error pop_front();
	Error pop_back();
	void erase();
	Error push_back(const Point&);
	size_t getSize();
	Error find_point(Point&, const size_t);
	Error insert(const Point&, const size_t);
	Error copy_paste(const List&);
	List operator+(const List&);
	List& operator+=(const List&);
	List& operator=(const List&);
	List operator--(int);

};

