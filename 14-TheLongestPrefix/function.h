/*编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int> theMap; //Use the characteristics of map to accomplish this
        for (auto& x : strs)
        {
            theMap[x] = 1;
        }
        auto x = theMap.begin()->first;
        auto temp = theMap.end();
        --temp;
        auto y = temp->first;
        string ans;
        for (int i = 0; i < x.size() && i < y.size(); ++i)
        {
            if (x[i] == y[i])
            {
                ans.push_back(x[i]);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};