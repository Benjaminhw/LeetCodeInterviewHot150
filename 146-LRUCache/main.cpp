#include "function.h"


int main()
{
	LRUCache A(3);
	A.put(1, 1);
	A.put(2, 2);
	A.put(3, 3);
	A.put(4, 4);
	A.get(4);
	A.get(3);
	A.get(2);
	A.get(1);
	return 0;
}