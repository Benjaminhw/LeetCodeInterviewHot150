#pragma once
#include <vector>
using namespace std;
//感觉这里用erase和双指针都可以

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 1;
        for (int q = 0; q < nums.size() - 2; ++q)
        {
            if (nums[q] != nums[q + 2])
            {
                ++p;
                nums[p] = nums[q + 2];
            }
        }
        return nums.size();
    }
};