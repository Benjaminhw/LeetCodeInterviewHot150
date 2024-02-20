#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n */

class Solution {
public:
	enum test;
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
	{
		int flag1 = 0, flag2 = 0;
		auto x = nums1;
		while (!(flag1 >= m && flag2 >= n)) //破烂题的判断写了一万年 这里的逻辑是每次循环加一个，并且上限是他们同时等于对应上限的时候
		{
			if (flag1 == m)
			{
				x[flag1 + flag2] = nums2[flag2];
				++flag2;
			}
			else if (flag2 == n)
			{
				x[flag1 + flag2] = nums1[flag1];
				++flag1;
			}
			else
			{
				if (nums1[flag1] <= nums2[flag2])
				{
					x[flag1 + flag2] = nums1[flag1];
					++flag1;
				}
				else
				{
					x[flag1 + flag2] = nums2[flag2];
					++flag2;
				}
			}
		}
		nums1 = x;
	}
};

//这个思路真的很清晰
class SolutionTop {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> res(m + n);
		int a = 0, b = 0, k = 0;
		while (a < m && b < n) {
			if (nums1[a] <= nums2[b]) {
				res[k++] = nums1[a++];
			}
			else {
				res[k++] = nums2[b++];
			}
		}
		while (a < m) {
			res[k++] = nums1[a++];
		}
		while (b < n) {
			res[k++] = nums2[b++];
		}
		nums1 = res;
	};
};