#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。 */

//仔细一看，只要没有0肯定能跳到结尾~~！然后一个位置后面跟着的0小于它本身的数也是可以的。

class SolutionA {
public:
	bool canJump(vector<int>& nums) {
		int totalLength = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			int max = 0;
			int tempi = 0;
			for (int j = 1; j <= nums[i] && j + i < nums.size(); ++j)
			{
				if (j + nums[j + i] > max)
				{
					max = j + nums[j + i];//跳出最大的间隔（以便下次选择）
					tempi = i + j;
				}
			}
			totalLength += max;
			if (max <= nums[i] || nums[i] == 0)
			{//跳不动了就停止
				break;
			}
			i = tempi;
		}
		if (totalLength >= nums.size() || nums.size() == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Solution {
public:
	bool canJump(vector<int>& nums) {
		//用双指针算0的个数
		int zeroCount = 0;
		int j = 0;
		int maxJumpLength = 0;//最大跳跃距离
		for (int i = 0; i < nums.size() - 1/*-1是因为能跳到最后一步的都是true*/; ++i)
		{
			--maxJumpLength;//每移动一格，jumpLength就少 不管是不是0 jumplength都得减少
			if (nums[i] != 0) //记录能跳的最远的距离
			{
				zeroCount = 0;
				if (nums[i] > maxJumpLength)
				{
					maxJumpLength = nums[i];
					j = i;//j慢指针
				}
			}
			else
			{
				++zeroCount;
				if (maxJumpLength <= zeroCount)
				{
					return false;
				}
			}
		}
		return true;
	}
};