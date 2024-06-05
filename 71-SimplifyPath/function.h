/*
����һ���ַ��� path ����ʾָ��ĳһ�ļ���Ŀ¼�� Unix ��� ����·�� ���� '/' ��ͷ�������㽫��ת��Ϊ���Ӽ��Ĺ淶·����

�� Unix �����ļ�ϵͳ�У�һ���㣨.����ʾ��ǰĿ¼�������⣬������ ��..�� ��ʾ��Ŀ¼�л�����һ����ָ��Ŀ¼�������߶������Ǹ������·������ɲ��֡�������������б�ܣ�����'//'��������Ϊ����б�� '/' �� ���ڴ����⣬�κ�������ʽ�ĵ㣨���磬'...'��������Ϊ�ļ�/Ŀ¼���ơ�

��ע�⣬���ص� �淶·�� ������ѭ������ʽ��

ʼ����б�� '/' ��ͷ��
����Ŀ¼��֮�����ֻ��һ��б�� '/' ��
���һ��Ŀ¼����������ڣ����� �� '/' ��β��
���⣬·���������Ӹ�Ŀ¼��Ŀ���ļ���Ŀ¼��·���ϵ�Ŀ¼���������� '.' �� '..'����
���ؼ򻯺�õ��� �淶·�� ��
*/

#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
	string simplifyPath(string path) {
		stack<string> tempStack;
		string ans;
		if (path.empty())
		{
			return path;
		}
		//else if (path[0] != '/')
		//{
		//	tempStack.push('/');
		//}
		int i = 0;
		while (i < path.size())
		{
			if (path[i] == '/')
			{
				while (path[i] == '/')
				{
					++i;
					if (i >= path.size())
					{
						goto labelA;
					}
				}
			}
			else if (path[i] == '.')
			{
				if (i + 1 < path.size() && path[i + 1] == '.' &&
					(i + 2 >= path.size() || path[i + 2] == '/'))
				{
					i += 2;
					if (!tempStack.empty())
					{
						tempStack.pop();
					}
				}
				else if (i + 1 < path.size() && path[i + 1] == '/')
				{
					i += 2;
				}
				else
				{
					string tempStr;
					while (path[i] != '/')
					{
						tempStr.push_back(path[i]);
						++i;
						if (i >= path.size())
						{
							tempStack.push(tempStr);
							goto labelA;
						}
					}
					tempStack.push(tempStr);
				}
			}
			else
			{
				string tempStr;
				while (path[i] != '/')
				{
					tempStr.push_back(path[i]);
					++i;
					if (i >= path.size())
					{
						tempStack.push(tempStr);
						goto labelA;
					}
				}
				tempStack.push(tempStr);
			}
		}
	labelA:
		if (!tempStack.empty())
		{
			ans = tempStack.top();
			tempStack.pop();
		}
		while (!tempStack.empty())
		{
			ans = tempStack.top() + "/" + ans;
			tempStack.pop();
		}
		ans = "/" + ans;
		return ans;
	}
};