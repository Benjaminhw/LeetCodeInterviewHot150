/*����һ���������� words ��һ������ maxWidth �������Ű浥�ʣ�ʹ���Ϊÿ��ǡ���� maxWidth ���ַ������������˶�����ı���

��Ӧ��ʹ�� ��̰���㷨�� �����ø����ĵ��ʣ�Ҳ����˵�������ܶ����ÿ���з��õ��ʡ���Ҫʱ���ÿո� ' ' ��䣬ʹ��ÿ��ǡ���� maxWidth ���ַ���

Ҫ�󾡿��ܾ��ȷ��䵥�ʼ�Ŀո����������ĳһ�е��ʼ�Ŀո��ܾ��ȷ��䣬�������õĿո���Ҫ�����Ҳ�Ŀո�����

�ı������һ��ӦΪ����룬�ҵ���֮�䲻�������Ŀո�

ע��:

������ָ�ɷǿո��ַ���ɵ��ַ����С�
ÿ�����ʵĳ��ȴ��� 0��С�ڵ��� maxWidth��
���뵥������ words ���ٰ���һ�����ʡ�*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		//It seems that it's not very complex.
		for (int i = 0; i < words.size(); ++i)
		{
			int wordCountWithOneBlank = 0;
			int leftBlankCount = 0;
			bool isLastLine = false;
			//outPut in the same line.
			//
			vector<string> lineWords;
			while (wordCountWithOneBlank <= maxWidth)
			{
				//If it's already the last line.
				if (i >= words.size())
				{
					//set the flag to true.
					isLastLine = true;
				}

				//If its length doesn't exceed the width.
				//Making it plus one is because there has to be a blank between words. 
				//Would last word makes some difference ?? --or the very first word 
				//If it's the first word
				if (wordCountWithOneBlank + words[i].size() + 1 <= maxWidth || wordCountWithOneBlank == 0)
				{
					if (wordCountWithOneBlank == 0)
					{
						wordCountWithOneBlank += words[i].size();
					}
					else
					{
						wordCountWithOneBlank += words[i].size() + 1;
					}
					lineWords.emplace_back(words[i]);
					++i;
				}
				//if it exceeds, output the result in this line.
				else
				{
					//Calculate the blank that need to be filled in
					if (isLastLine)
					{
						for (auto& y : lineWords)
						{
							cout << y;
							if (y != lineWords.back())
							{
								//if not the last word 
								cout << " ";
							}
						}
					}
					else
					{
						leftBlankCount = maxWidth - wordCountWithOneBlank;
						int splitBlank = leftBlankCount / lineWords.size();
						int splitBlankLeft = leftBlankCount % (lineWords.size());
						for (auto& y : lineWords)
						{
							cout << y;
							cout << " ";
							for (int k = 0; k < splitBlank; ++k)
							{
								cout << " ";
							}
							if (splitBlankLeft > 0)
							{
								cout << " ";
								--splitBlankLeft;
							}
						}
						break;
					}
				}
			}
			//words sequence
			//words[i];
		}
	}
};