/*
* ��дһ��������������һ���޷����������Զ����ƴ�����ʽ��������������Ʊ��ʽ�� 
����λ
 �ĸ�����Ҳ����Ϊ������������
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