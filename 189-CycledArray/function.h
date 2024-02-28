#pragma once
#include <vector>
#include <iostream>

/*给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。*/

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

//reverse秒杀
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
