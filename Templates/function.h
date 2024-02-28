#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。 */


//这题有点莫名其妙的…… 非常简单的贪心，上涨就购买不上涨就不购买

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