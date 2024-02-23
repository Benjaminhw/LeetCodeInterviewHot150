#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            int j = 1;    //���ڱȽϵ���ʱ����
            while (i+j<nums.size()&&nums[i + j] == nums[i])    //�����ͬ����һֱ����ȥ
            {
                ++j;
            }
            for (int k = 0; k < j-1; ++k)
            {
                nums.erase(nums.begin() + i);    //���ϵ�ȥɾ�����λ�õ�Ԫ��
            }
        }
        return nums.size();
    }
};

//˫ָ��˼·
//�ܶ�˫ָ����ⶼ�Ǵӵڶ�����ʼ���ǵ�
class SolutionTop {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return n;
        }
        int left = 1;
        for (int right = 0; right < n - 1; ++right) {
            if (nums[right] != nums[right + 1]) {
                nums[left] = nums[right + 1];
                left++;
            }
        }
        return left;
    }
};