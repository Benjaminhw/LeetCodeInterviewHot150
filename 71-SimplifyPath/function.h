/*
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。

请注意，返回的 规范路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。
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