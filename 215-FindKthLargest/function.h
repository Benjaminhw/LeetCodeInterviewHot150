/*
������������ nums ������ k���뷵�������е� k ������Ԫ�ء�

��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�

�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//������������ O(n)?������
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};