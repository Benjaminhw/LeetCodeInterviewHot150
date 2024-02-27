#pragma once
#include <iostream>
#include <vector>
/*给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 */

class Solution {
public:
    //感觉是可以简化的，因为有的部分肯定算过-分治与剪枝
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
                    break;//去除递减情况之后通过了
                }
                //暴力-超时了
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
            //对每个数其实做了两件事：
            // 一是拿这个数和之前的minPrice相减，看是否利润达到新高。
            // 二是拿这个数和minPrice相比，看看谁更低。

            //由于售卖的先后顺序，只需遍历一次
            //用股民的思维去理解——作为一个股民，你掌握了行情。你只需要在每天决定要不要买要不要卖两件事，
            //甚至可以反悔，你可以记录并更新最低值，修改岁月史书，在最便宜时买入，在最贵时卖出。

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