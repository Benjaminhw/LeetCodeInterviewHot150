/*����һ���������� citations ������ citations[i] ��ʾ�о��ߵĵ� i ƪ���ı����õĴ��������㲢���ظ��о��ߵ� h ָ����
����ά���ٿ��� h ָ���Ķ��壺h ���������ô����� ��һ��������Ա�� h ָ�� ��ָ�����������ٷ����� h ƪ���ģ����� ���� �� h ƪ����
�����ô������ڵ��� h ����� h �ж��ֿ��ܵ�ֵ��h ָ�� �����������Ǹ���*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
	//��������
	struct CmpByKey{
		bool operator()(const int& a, const int& b) const{
			return a > b;
		}
	};
	int hIndex(vector<int>& citations) {
		int H = 0;
		//linear programming problem
		//y=f(x) y>=h x>=h and x is the number of paper which citations is bigger than h
		map<int, int, CmpByKey> theMap;//��map����Ϊ�ײ�ԭ���Ǻ��������������keyֵ
		//���ô���Ϊx�ļ���Map
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
		//��������
		for (auto& x : theMap)
		{
			paperCount += x.second;//paperCount��Ȼ����x.second��Ϊ�����ۼ�
			//citation����>=x������ƪ��>=xƪ,�����������϶����
			//paperCountΪ���ô������ڵ���[x.first]������ƪ��(���ֵδ�ش���x.first)
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
