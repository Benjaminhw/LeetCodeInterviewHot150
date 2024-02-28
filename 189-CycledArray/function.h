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
class SolutionTop {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);  //reverse the whole array
        reverse(nums, 0, k - 1);            //reverse the former [0,k] elements
        reverse(nums, k, nums.size() - 1);  //reverse the [k+1,n] elements
    }
};
