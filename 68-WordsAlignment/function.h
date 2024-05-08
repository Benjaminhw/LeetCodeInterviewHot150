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
		for (int i = 0; i < words.size(); ++i)
		{
			int wordCountWithOneBlank = 0;
			int leftBlankCount = 0;
			bool isLastLine = false;
			//outPut in the same line.
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
				//Plus one is because there has to be a blank between words. 
				if (wordCountWithOneBlank + words[i].size() + 1 <= maxWidth)
				{
					wordCountWithOneBlank += words[i].size() + 1;
					lineWords.emplace_back(words[i]);
					++i;
				}

				//if it exceeds, output the result in this line.
				else
				{
					//Calculate the blank that need to be filled in
					if (isLastLine)
					{

					}
					else
					{
						leftBlankCount = maxWidth - wordCountWithOneBlank;
						break;
					}
				}
			}
			//words sequence
			words[i];
		}
	}
};