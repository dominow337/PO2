#include "List.h"

int main()
{
	for (int j = 0; j < 1000; j)
	{
		for (Point& i = 0; i < 1000; i++)
		{
			List::insert(i);
		}
		for(Point& i = 0; i < 1000; i++)
		{
			List::pop_front(i);
		}
	}
}