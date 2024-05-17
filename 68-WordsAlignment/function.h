/*给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

注意:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。*/

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