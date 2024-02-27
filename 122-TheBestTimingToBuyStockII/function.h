#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*����һ���������� prices ������ prices[i] ��ʾĳ֧��Ʊ�� i ��ļ۸�

��ÿһ�죬����Ծ����Ƿ����/����۹�Ʊ�������κ�ʱ�� ��� ֻ�ܳ��� һ�� ��Ʊ����Ҳ�����ȹ���Ȼ���� ͬһ�� ���ۡ�

���� ���ܻ�õ� ��� ���� �� */


//�����е�Ī������ġ��� �ǳ��򵥵�̰�ģ����Ǿ͹������ǾͲ�����

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        for (int j = 0; j+1 < prices.size(); ++j)
        {
            int add = prices[j+1]-prices[j];
            if (add > 0)
            {
                maxProfit += add;
            }
        }
        return maxProfit;
    }
};