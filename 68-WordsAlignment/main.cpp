#include "function.h"


int main()
{
	vector<string> words;
	words = { "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do" };
	Solution A;
	A.fullJustify(words, 20);
	return 0;
}