#include "function.h"

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
	vector<int> a = {1,3,0,0,0};//��Ŀ�趨��ʼ����
	vector<int> b = {2,2,3};
	Solution A;
	A.merge(a, 2, b, 3);
	int x = A.Blue;
	return 0;
}