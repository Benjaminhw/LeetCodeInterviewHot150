#pragma once
#include <vector>
#include <iostream>

/*����һ���������� nums���������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����*/

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp = nums;
        for (int i=0;i<temp.size();++i)
        {
            nums[(i + k) % nums.size()] = temp[i];
        }
    }
};

//reverse��ɱ