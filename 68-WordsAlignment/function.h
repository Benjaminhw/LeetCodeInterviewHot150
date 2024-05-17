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
		vector<string> answers;
		for (int i = 0; i < words.size(); ++i)
		{
			int wordCountWithOneBlank = 0;
			int leftBlankCount = 0;
			int wordCount = 0;
			bool isLastLine = false;
			//outPut in the same line.
			//
			vector<string> lineWords;
			while (wordCountWithOneBlank <= maxWidth && i <= words.size())
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
				if (i < words.size() && (wordCountWithOneBlank + words[i].size() + 1 <= maxWidth || wordCountWithOneBlank == 0))
				{
					if (wordCountWithOneBlank == 0)
					{
						wordCountWithOneBlank += words[i].size();
					}
					else
					{
						wordCountWithOneBlank += words[i].size() + 1;
					}
					wordCount += words[i].size();
					lineWords.emplace_back(words[i]);
					++i;
				}
				//if it exceeds, output the result in this line.
				else
				{
					string answer;
					//Calculate the blank that need to be filled in
					if (isLastLine)
					{

						int tempCount = 0;
						for (auto& y : lineWords)
						{
							//cout << y;
							answer += y;
							tempCount += y.size();
							if (y != lineWords.back())
							{
								//if not the last word 
								//cout << " ";
								answer += " ";
								++tempCount;
							}
						}
						for (int j = 0; j < maxWidth - tempCount; ++j)
						{
							answer += " ";
						}
						answers.emplace_back(answer);
						break;
					}
					else
					{
						leftBlankCount = maxWidth - wordCount;
						//actually we have to have it minus 1
						int splitBlank = leftBlankCount;
						int splitBlankLeft = 0;
						if (lineWords.size() != 1)
						{
							splitBlank = leftBlankCount / (lineWords.size() - 1);
							splitBlankLeft = leftBlankCount % (lineWords.size() - 1);
						}
						for (auto& y : lineWords)
						{
							//cout << y;
							answer += y;
							//cout << " ";
							if (&y == &lineWords.back() && lineWords.size() != 1)
							{
								break;
							}
							for (int k = 0; k < splitBlank; ++k)
							{
								//cout << " ";
								answer += " ";
							}
							if (splitBlankLeft > 0)
							{
								//cout << " ";
								answer += " ";
								--splitBlankLeft;
							}
						}
						answers.emplace_back(answer);
						lineWords.clear();
						wordCountWithOneBlank = 0;
						wordCount = 0;
						//cout << endl;
					}
				}
			}
			//words sequence
			//words[i];
		}
		return answers;
	}
};

////All clear!