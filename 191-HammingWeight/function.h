/*
* 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中 
设置位
 的个数（也被称为汉明重量）。
*/

#pragma once
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


class Solution {
public:
    //calculate the number of '1' in n.
    int hammingWeight(int n) {
        bitset<32> binarySet(n);
        return binarySet.count();
    }
};