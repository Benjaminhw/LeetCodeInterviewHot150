/*ʵ��RandomizedSet �ࣺ

RandomizedSet() ��ʼ�� RandomizedSet ����
bool insert(int val) ��Ԫ�� val ������ʱ���򼯺��в����������� true �����򣬷��� false ��
bool remove(int val) ��Ԫ�� val ����ʱ���Ӽ������Ƴ���������� true �����򣬷��� false ��
int getRandom() ����������м����е�һ�����������֤���ô˷���ʱ���������ٴ���һ��Ԫ�أ���ÿ��Ԫ��Ӧ���� ��ͬ�ĸ��� �����ء�
�����ʵ��������к�����������ÿ�������� ƽ�� ʱ�临�Ӷ�Ϊ O(1) ��*/

//��һ��map����

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