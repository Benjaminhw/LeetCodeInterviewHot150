/*
* ����һ���ַ��� s ��һ���ַ������� words�� words �������ַ��� ������ͬ��

 s �е� �����Ӵ� ��ָһ������  words �������ַ���������˳�����������������Ӵ���

���磬��� words = ["ab","cd","ef"]�� ��ô "abcdef"�� "abefcd"��"cdabef"�� "cdefab"��"efabcd"�� �� "efcdab" ���Ǵ����Ӵ��� "acdbef" ���Ǵ����Ӵ�����Ϊ�������κ� words ���е����ӡ�
�������д����Ӵ��� s �еĿ�ʼ������������� ����˳�� ���ش𰸡�



ʾ�� 1��

���룺s = "barfoothefoobarman", words = ["foo","bar"]
�����[0,9]
���ͣ���Ϊ words.length == 2 ͬʱ words[i].length == 3�����ӵ����ַ����ĳ��ȱ���Ϊ 6��
�Ӵ� "barfoo" ��ʼλ���� 0������ words ���� ["bar","foo"] ˳�����е����ӡ�
�Ӵ� "foobar" ��ʼλ���� 9������ words ���� ["foo","bar"] ˳�����е����ӡ�
���˳���޹ؽ�Ҫ������ [9,0] Ҳ�ǿ��Եġ�
*/
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
	bool isMapEqual(unordered_map<string, int> A, unordered_map<string, int> B)
	{
		for (auto& x : A)
		{
			if (B.find(x.first) == B.end())
			{
				return false;
			}
			else
			{
				if (B[x.first] != x.second)
				{
					return false;
				}
			}
		}
		return true;
	}

	vector<int> findSubstring(string s, vector<string>& words) {

		//slipWindows + hashMap
		vector<int> results;
		unordered_map<string, int> hashMap;
		for (auto& x : words)
		{
			//if it can't found
			if (hashMap.find(x) == hashMap.end())
			{
				hashMap[x] = 1;
			}
			//if it is found.
			else
			{
				++hashMap[x];
			}
		}
		if (words.empty())
		{
			return results;
		}
		int start = 0 /*Where the position starts.*/, width = words[0].size(), length = words.size();
		for (;start < width; ++start)
		{
			unordered_map<string, int> tempHashMap;
			int i = start, j = start; //actual pointer 
			while (j < start + length * width && j < s.size())
			{
				auto y = s.substr(j, width);
				if (tempHashMap.find(y)==tempHashMap.end())
				{
					tempHashMap[y] = 1;

				}
				else
				{
					++tempHashMap[y];
				}
				j += width;
			}
			//������
			if (isMapEqual(hashMap, tempHashMap))
			{
				results.push_back(i);
			}
			i+=width;
			j+=width;
			while (j <= s.size())
			{
				auto y = s.substr(j - width, width);
				if (tempHashMap.find(y) == tempHashMap.end())
				{
					tempHashMap[y] = 1;
				}
				else
				{
					++tempHashMap[y];
				}
				auto z = s.substr(i - width, width);
				{
					--tempHashMap[z];
					if (tempHashMap[z] <= 0)
					{
						tempHashMap.erase(z);
					}
				}
				if (isMapEqual(hashMap, tempHashMap))
				{
					results.push_back(i);
				}
				i += width;
				j += width;
			}
		}
		return results;
	}
};