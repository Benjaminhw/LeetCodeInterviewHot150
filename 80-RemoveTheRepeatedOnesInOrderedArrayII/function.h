#pragma once
#include <vector>
using namespace std;
//�о�������erase��˫ָ�붼����

/*����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ�ó��ִ����������ε�Ԫ��ֻ�������� ������ɾ����������³��ȡ�

��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int p = 1;//��ʼ�ӵڶ���ʼ����Ϊ��һ����Զ���䣨����еĻ���
		int flag = 1; //
		for (int q = 0; q < nums.size() - 1; ++q)
		{
			if (nums[q] == nums[q + 1])
			{
				++flag;
				//��Ҫ���м���������ظ��Ĵ���С�ڵ���2����ô��ʼ�����ƶ�
				if (flag == 2)//==����Ϊ1ʱ�ڱ��ʱ���Ѿ�copy����flagΪ2��ʱ�����ֵ����ˣ�����һ��ֵ���ڱ��ʱ����ɵ�
				{
					nums[p] = nums[q + 1];
					++p;
				}
			}
			else //���ȵ�case
			{
				flag = 1;
				nums[p] = nums[q + 1];
				++p;
			}
		}
		nums.resize(p);//���++p��һ��
		return nums.size();
	}
};

//��Ȼ�����İѼ���ĳ�2������
class SolutionTop {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2) {
			return n;
		}
		int slow = 2, fast = 2;
		while (fast < n) {
			if (nums[slow - 2] != nums[fast]) {
				nums[slow] = nums[fast];
				++slow;
			}
			++fast;
		}
		return slow;
	}
};