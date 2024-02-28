/*给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，并且 至少 有 h 篇论文
被引用次数大于等于 h 。如果 h 有多种可能的值，h 指数 是其中最大的那个。*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
	//倒序排列
	struct CmpByKey{
		bool operator()(const int& a, const int& b) const{
			return a > b;
		}
	};
	int hIndex(vector<int>& citations) {
		int H = 0;
		//linear programming problem
		//y=f(x) y>=h x>=h and x is the number of paper which citations is bigger than h
		map<int, int, CmpByKey> theMap;//用map是因为底层原理是红黑树，按序排列key值
		//引用次数为x的计数Map
		for (auto& x : citations)
		{
			if (theMap.find(x) != theMap.end())
			{
				++theMap[x];
			}
			else
			{
				theMap[x] = 1;
			}
		}
		//
		//sort(theMap.begin(), theMap.end());
		int paperCount=0;
		//倒序排序
		for (auto& x : theMap)
		{
			paperCount += x.second;//paperCount必然大于x.second因为是其累加
			//citation次数>=x的论文篇数>=x篇,这里是铁符合定义的
			//paperCount为引用次数大于等于[x.first]的文章篇数(这个值未必大于x.first)
			if (paperCount >= x.first)
			{
				H = max(H,x.first);
				break;
			}
			else
			{
				H = paperCount;
			}
		}
		return H;
	}
};
