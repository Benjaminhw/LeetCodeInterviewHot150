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