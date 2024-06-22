/*
���� ���ۣ�LeetCode��������ʼ IPO ��Ϊ���Ը��ߵļ۸񽫹�Ʊ��������Ͷ�ʹ�˾������ 
ϣ���� IPO ֮ǰ��չһЩ��Ŀ���������ʱ��� ������Դ���ޣ���ֻ���� IPO ֮ǰ������ k ��
��ͬ����Ŀ������ ���� ��������� k ����ͬ��Ŀ��õ�������ʱ��ķ�ʽ��

���� n ����Ŀ������ÿ����Ŀ i ��������һ�������� profits[i] ������������Ŀ��Ҫ��
��С�ʱ� capital[i] ��

���������ʱ�Ϊ w ���������һ����Ŀʱ���㽫��ô����������󽫱���ӵ�������ʱ��С�

�ܶ���֮���Ӹ�����Ŀ��ѡ�� ��� k ����ͬ��Ŀ���б��� ��������ʱ� ��
��������տɻ�õ�����ʱ���

�𰸱�֤�� 32 λ�з���������Χ�ڡ�
*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
		vector<pair<int, int>> pairArray;
		for (int i = 0; i < profits.size(); ++i)
		{
			pairArray.push_back({capital[i],profits[i]});
		}
		sort(pairArray.begin(), pairArray.end());
		//�ܽ��� ��һ�������ȶ�����~
		priority_queue<int, vector<int>, less<int>> priorityQueue;

		int curr = 0;
		for (int i = 0; i < k; ++i)
		{
			//���� ����������Ŀ�ŵ��������� ע�����ﻹû�п�ʼѡҪ���ĸ���Ŀ
			//ע������curr��֤������Ŀֻ��һ��
			while (curr < profits.size() && pairArray[curr].first <= w)
			{
				priorityQueue.push(pairArray[curr].second);
				++curr;
			}
			if (!priorityQueue.empty())
			{
				w += priorityQueue.top();
				priorityQueue.pop();
			}
			else
			{
				break;
			}
		}
		return w;
	}
};