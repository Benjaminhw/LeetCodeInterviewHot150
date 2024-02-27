#pragma once
#include <iostream>
#include <vector>
/*����һ������ prices �����ĵ� i ��Ԫ�� prices[i] ��ʾһ֧������Ʊ�� i ��ļ۸�

��ֻ��ѡ�� ĳһ�� ������ֻ��Ʊ����ѡ���� δ����ĳһ����ͬ������ �����ù�Ʊ�����һ���㷨�����������ܻ�ȡ���������

��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� 0 */

class Solution {
public:
    //�о��ǿ��Լ򻯵ģ���Ϊ�еĲ��ֿ϶����-�������֦
    int maxProfit(vector<int>& prices) {
        double maxProfit=0;
        vector<int> p;
        for (int i = 0; i < prices.size(); ++i)
        {
            for (int j = i + 1; j < prices.size(); ++j)
            {
                double tempPrice = prices[j] - prices[i];
                if (tempPrice <= 0)
                {
                    break;//ȥ���ݼ����֮��ͨ����
                }
                //����-��ʱ��
                if (tempPrice > maxProfit)
                {
                    maxProfit = tempPrice;
                }
            }
        }
        return maxProfit;
    }
};


class SolutionTop {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price : prices) {

            maxprofit = max(maxprofit, price - minprice);//this is the faster pointer
            minprice = min(price, minprice);//This is the Pointer which is slower
        }
        return maxprofit;
    }
};

class SolutionTopTwoPointer {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minPrice = inf, maxProfit=0;
        int buyDate = -1, sellDate = -1;
        for (int i = 0; i < prices.size(); ++i)
        {
            //��ÿ������ʵ���������£�
            // һ�����������֮ǰ��minPrice��������Ƿ�����ﵽ�¸ߡ�
            // �������������minPrice��ȣ�����˭���͡�

            //�����������Ⱥ�˳��ֻ�����һ��
            //�ù����˼άȥ��⡪����Ϊһ�����������������顣��ֻ��Ҫ��ÿ�����Ҫ��Ҫ��Ҫ��Ҫ�������£�
            //�������Է��ڣ�����Լ�¼���������ֵ���޸�����ʷ�飬�������ʱ���룬�����ʱ������

            if (prices[i] - minPrice > maxProfit) 
            {
                maxProfit = prices[i] - minPrice;
                sellDate = i;
            }

            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
                buyDate = i;
            }
        }
    }
};