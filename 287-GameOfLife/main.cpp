#include "function.h"


int main()
{
	Solution A;
	vector<vector<int>> x = { 
		{0,1,0},
		{0,0,1},
		{1,1,1},
		{0,0,0} };
	//[[0,0,0],
	// [1,0,1],
	// [0,1,1],
	// [0,1,0]]
	A.gameOfLife(x);
	return 0;
}