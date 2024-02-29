/*在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

//exhaustive search 
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		vector<int> possibleStart;
		int judge = 0, maxLeft = 0, maxFlag = 0;
		//先遍历一遍，把cost做成+-的形式
		for (int i = gas.size() - 1; i >= 0; --i)
		{
			//逆序行驶一周，寻找最富裕的那个点(直觉上来说是？)，从那个点开始正向行驶
			cost[i] = gas[i] - cost[i];//开到下一个站多余出来/还需的油
			judge += cost[i];
			if (judge > maxLeft)
			{
				maxFlag = i;
				maxLeft = judge;
				maxLeft = judge;
			}
		}
		if (judge < 0)
		{
			return -1;
		}
		return maxFlag;
	}
};