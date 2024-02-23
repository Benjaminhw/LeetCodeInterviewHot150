#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            int j = 1;    //用于比较的临时变量
            while (i+j<nums.size()&&nums[i + j] == nums[i])    //如果相同，就一直找下去
            {
                ++j;
            }
            for (int k = 0; k < j-1; ++k)
            {
                nums.erase(nums.begin() + i);    //不断地去删除这个位置的元素
            }
        }
        return nums.size();
    }
};

//双指针思路
//很多双指针的题都是从第二个开始考虑的
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