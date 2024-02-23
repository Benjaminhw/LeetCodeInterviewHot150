#include "function.h"

//just A test
enum Solution::test
{
	Red,
	Green,
	Blue
};

int main()
{
	Solution A;
	std::vector<int> a = { 1,2,0,0 };
	std::vector<int> b = { 1,2 };
	A.merge(a, 2, b, 2);
	int x = A.Blue;
	return 0;
}