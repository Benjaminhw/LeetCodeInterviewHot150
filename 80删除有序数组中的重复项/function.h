#pragma once
#include <vector>
using namespace std;
//感觉这里用erase和双指针都可以

/*给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int p = 1;//初始从第二格开始是因为第一格永远不变（如果有的话）
		int flag = 1; //
		for (int q = 0; q < nums.size() - 1; ++q)
		{
			if (nums[q] == nums[q + 1])
			{
				++flag;
				//需要进行计数，如果重复的次数小于等于2，那么开始进行移动
				if (flag == 2)//==是因为1时在变的时候已经copy过了flag为2的时候就三值相等了，还有一个值是在变的时候组成的
				{
					nums[p] = nums[q + 1];
					++p;
				}
			}
			else //不等的case
			{
				flag = 1;
				nums[p] = nums[q + 1];
				++p;
			}
		}
		nums.resize(p);//最后还++p了一下
		return nums.size();
	}
};

//居然单纯的把间隔改成2就行了
class SolutionTop {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2) {
			return n;
		}
		int slow = 2, fast = 2;
		while (fast < n) {
			if (nums[slow - 2] != nums[fast]) {
				nums[slow] = nums[fast];
				++slow;
			}
			++fast;
		}
		return slow;
	}
};