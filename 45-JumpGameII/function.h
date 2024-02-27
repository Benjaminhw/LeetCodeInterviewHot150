#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

0 <= j <= nums[i] 
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。 */

class Solution {
public:
    int jump(vector<int>& nums) {
		int maxJumpLength = 0,realMaxLength=0,minJumpStep=0;//最大跳跃距离
		for (int i = 0; i < nums.size()/*-1是因为能跳到最后一步的都是true*/; ++i)
		{

			if (nums[i] != 0) //记录能跳的最远的距离
			{
				if (nums[i] > maxJumpLength)
				{
					if (maxJumpLength <= 0)
					{

					}
					++minJumpStep;
					
					maxJumpLength = nums[i];
					//j = i;//j慢指针
				}
				if (i + maxJumpLength >= nums.size() - 1)
				{
					return minJumpStep;
				}
			}
			--maxJumpLength;//每移动一格，jumpLength就少 不管是不是0 jumplength都得减少
		}
		return minJumpStep;
    }
};