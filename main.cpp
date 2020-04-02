#include "List.h"
#include "Point.h"
int main()
{
	while(true)
	{
		List  * list = new List();
		for (int i = 0; i < 10; i++)
		{
			Point p(i, i, i);
			list->insert(p, i);
		}
		delete list;
		while (list->getSize() > 0)
		{
			list->pop_front();
		}
	}
}
