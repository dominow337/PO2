#include "List.h"
List::Node * List::find(const size_t idx)
{
	Node * node = first;

	for (size_t i = 0; i < idx; i++)
	{
		node = node->next; 
	}

	return node;
}
void List::push(const Point & point, const size_t idx)
{
	if (idx == 0)
	{
		Node * tail = first;
		first = new Node(point);
		first->next = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next;
		prev->next = new Node(point);
		prev->next->next = tail;
	}
	size++;
}

void List::push(const List & list, const size_t idx)
{
	List copy(list);
	Node * it = copy.first;
	if (idx == 0)
	{
		Node * tail = first;
		Node * last = nullptr;
		if (it)
		{
			first = new Node(it->point);
			last = first;
			it = it->next;
		}
		while (it)
		{
			last->next = new Node(it->point);
			last = last->next;
			it = it->next;
		}
		last->next = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next;
		while (it)
		{
			prev->next = new Node(it->point);
			prev = prev->next;
			it = it->next;
		}
		prev->next = tail;
	}
	size += list.size;
}

void List::pop(const size_t idx)
{
	if (idx == 0)
	{
		Node * tail = first->next;
		delete first;
		first = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next->next;
		delete prev->next;
		prev->next = tail;
	}
	size--;
}

void List::multiply(List& list, const size_t x)
{
	List copy(*this);
	erase();
	for (size_t i = 0; i < x; i++)
	{
		push(copy, size);
	}
}

List::List() : size(0), first(nullptr){}

List::List(const List & list) : size(list.size), first(nullptr)
{
	Node * it = list.first;
	Node * last = first;
	if (it)
	{
		first = new Node(it->point);
		last = first;
		it = it->next;
	}
	while (it)
	{
		last->next = new Node(it->point);
		last = last->next;
		it = it->next;
	}
}

//destruktor
List::~List()
{
	erase();
}

List::List(const vector<Point>&points) : size(0), first(nullptr)
{
	/*for (auto it = points.begin(); it != points.end(); ++it)
	{
		push_back(*it);
	}*/

	for(size_t i = points.size()-1; i >= 0; i++)
	{
		push(points[i], 0);
	}
}

void List::erase()
{
	while (size > 0)
	{
		pop_front();
	}
}

List::Error List::pop_front()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(0);
	}

	return error;
}

List::Error List::pop_back()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(size - 1);
	}

	return error;
}

List::Error List::push_back(const Point& point)
{
	List::Error error = List::Error::SUCCESS;

		//Node* el = first;
		//while (el->next)
		//{
		//	el = el->next;
		//}
		//el->next = new Node(point);
		//size++;
	push(point, size);
	return error;
}

size_t List::getSize()
{
	return size;
}



List::Error List::insert(const Point& x, const size_t idx)
{
	if (getSize() >= idx)
	{
		push(x, idx);
		return SUCCESS;
	}
	else
	{
		return OUT_OF_BOUNDS;
	}
}

List::Error List::copy_paste(const List& list)
{
	List::Error error = SUCCESS;
	//const size_t x = list.size; //nie ma koniecnzoœci ¿eby to przechowaæ w zmienne,
	//List A;
	//A.first = list.first;

	List copy(list);
	this->erase();

	List::Node* y = copy.first;
	List::Node* last = nullptr;

	if (y)
	{
		this->first = new Node(y->point);
		last = first;
		y = y->next;
		while (y)
		{
			//if(y)
			//{
				last->next = new Node(y->point);
				last = last->next;
			//}
				y = y->next;
		}
	}
	else
	{
		error = List::Error::LIST_EMPTY;
	}
	return error;
}

List::Error List::find_point(Point& x, const size_t idx)
{
	if (getSize() >= idx)
	{
		List::Node *y = find(idx);
		x = y->point;
		return SUCCESS;
	}
	else
	{
		return OUT_OF_BOUNDS;
	}
}

List List::operator+(const List& list)
{
	List copy(*this);
	copy.push(list, copy.size);
	return copy;
}

List& List::operator+=(const List& list)
{
	push(list, size);
	return *this;
}

List & List::operator=(const List & list)
{
	List copy(list);
	erase();
	push(copy, 0);
	return *this;
}

List List::operator--(int)
{
	List copy(*this);
	pop_back();
	return copy;
}

List List::operator*(const size_t x)
{
	List copy(*this);
	multiply(copy, x);
	return copy;
}
//list[3] = Point()
Point& List::operator[](const size_t idx)
{
	return find(idx)->point;
}

List List::operator++(int)
{
	List copy(*this);
	erase();
	return copy;
}

ostream& operator<<(ostream& outputStream, const List& list)
{
	List::Node* y = list.first;
	for (size_t i = 0; i < list.size; i++)
	{
		outputStream << i << ". ";
		outputStream << y->point.x << " ";
		outputStream << y->point.y << " ";
		outputStream << y->point.z << endl;
		y = y->next;
	}
	return outputStream;
}
