#pragma once
#include <iostream>
#include <vector>

/*����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣

Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�*/


using namespace std;

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int maxsize = nums.size();
        for (int i=0;i<maxsize;++i)
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin()+i);
                --i;
                --maxsize;
            }
        }
        return nums.size();
    }
};