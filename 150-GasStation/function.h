/*��һ����·���� n ������վ�����е� i ������վ������ gas[i] ����

����һ�������������޵ĵ��������ӵ� i ������վ������ i+1 ������վ��Ҫ�������� cost[i] ����������е�һ������վ��������ʼʱ����Ϊ�ա�

���������������� gas �� cost ���������԰�˳���ƻ�·��ʻһ�ܣ��򷵻س���ʱ����վ�ı�ţ����򷵻� -1 ��������ڽ⣬�� ��֤ ���� Ψһ �ġ�*/

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
		//�ȱ���һ�飬��cost����+-����ʽ
		for (int i = gas.size() - 1; i >= 0; --i)
		{
			//������ʻһ�ܣ�Ѱ���ԣ���Ǹ���(ֱ������˵�ǣ�)�����Ǹ��㿪ʼ������ʻ
			cost[i] = gas[i] - cost[i];//������һ��վ�������/�������
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