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
		if (nums.size() == 1)
		{
			return 0;
		}
		//the boundary condition near the tail is relatively important. 
		int maxJumpLength = 0, realMaxJumpLength = 0, minJumpStep = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			//No need to consider zero now
			if (nums[i] > maxJumpLength)
			{
				maxJumpLength = nums[i];
				//j = i;//slower pointer j

			}
			//always calculate the real max jump length
			if (realMaxJumpLength <= 0)
			{
				realMaxJumpLength = maxJumpLength;
				++minJumpStep;
			}
			//here use the real maxjumplength 
			if (i + realMaxJumpLength >= nums.size() - 1)
			{
				//realMaxJumpLength indicates the actual
				//++minJumpStep;
				return minJumpStep;
			}
			--maxJumpLength;//Every step JumpLength will be shorter.
			--realMaxJumpLength;
		}
		return minJumpStep;
	}
};