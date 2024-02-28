#include "function.h"

int main()
{
	Solution A;
	//vector<int> test = { 2,3,1,1,4 };
	//vector<int> test = {1,2 };
	//vector<int> test = { 3,4,3,2,5,4,3 }; 
	vector<int> test = { 5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0 };
	int R = A.jump(test);
	printf("%d", R);
	return 0;
}