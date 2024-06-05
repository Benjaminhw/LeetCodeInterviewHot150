/*
����һ���ַ������� tokens ����ʾһ������ �沨����ʾ�� ��ʾ���������ʽ��

�������ñ��ʽ������һ����ʾ���ʽֵ��������

ע�⣺

��Ч�����Ϊ '+'��'-'��'*' �� '/' ��
ÿ����������������󣩶�������һ������������һ�����ʽ��
��������֮��ĳ������� ����ض� ��
���ʽ�в����������㡣
������һ�������沨����ʾ����ʾ���������ʽ��
�𰸼������м������������ 32 λ ������ʾ��


ʾ�� 1��

���룺tokens = ["2","1","+","3","*"]
�����9
���ͣ�����ʽת��Ϊ��������׺�������ʽΪ��((2 + 1) * 3) = 9
*/
#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> tempStack;
		int ans = tempStack.top();
		for (int i = 0; i < tokens.size(); ++i)
		{
			if (tokens[i] == "*")
			{
				int a = tempStack.top();
				tempStack.pop();
				ans = a * tempStack.top();
				tempStack.pop();
				tempStack.push(ans);
			}
			else if (tokens[i] == "/")
			{
				int a = tempStack.top();
				tempStack.pop();
				ans = tempStack.top() / a;
				tempStack.pop();
				tempStack.push(ans);
			}
			else if (tokens[i] == "+")
			{
				int a = tempStack.top();
				tempStack.pop();
				ans = a + tempStack.top();
				tempStack.pop();
				tempStack.push(ans);
			}
			else if (tokens[i] == "-")
			{
				int a = tempStack.top();
				tempStack.pop();
				ans = tempStack.top() - a;
				tempStack.pop();
				tempStack.push(ans);
			}
			else
			{
				tempStack.push(atoi(tokens[i].c_str()));
			}
		}
		return ans;
	}
};