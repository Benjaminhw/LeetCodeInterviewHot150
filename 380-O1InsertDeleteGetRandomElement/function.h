/*实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。*/

//套一层map算求

#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;


class RandomizedSet {
public:
    unordered_map<int,int> target;
    RandomizedSet() {

    }

    bool insert(int val) {
        if (target.find(val) == target.end())
        {
            target[val] = 1;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(int val) {
        return target.erase(val);
    }

    int getRandom() {
        int x = rand() % target.size();
        auto y = target.begin();
        for (int i = 0; i < x; ++i)
        {
            ++y;
        }
        return (*y).first;
    }
};