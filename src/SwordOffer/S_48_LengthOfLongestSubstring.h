#pragma once
#include "../BASE.h"



class S_48_LengthOfLongestSubstring : public BASE {
public:
	virtual void main()
	{
	}
    int lengthOfLongestSubstring(string s) 
    {
        if (s.empty()) return 0;
        int maxLength = 0;
        int currentLength = 0;
        int preIndex = -1;
        unordered_map<char, int> position;
        for (int i = 0; i < s.size(); ++i)
        {
            preIndex = -1;
            if(position.find(s[i] - 'a') != position.end())
                preIndex = position[s[i] - 'a'];
            if (preIndex == -1 || i - preIndex - 1 >= currentLength)
                ++currentLength;
            else
            {
                currentLength = i - preIndex;
            }
            maxLength = std::max(maxLength, currentLength);
            position[s[i] - 'a'] = i;
        }
        return maxLength;
    }
};