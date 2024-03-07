#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == ' ')
            {
                s.erase(i);
            }
            else
            {
                break;
            }
        }
        stringstream tempStream(s);
        s = "";
        int x = 0;
        while (getline(tempStream, s, ' '))
        {
            x = s.size();
        }
        return x;
    }
};