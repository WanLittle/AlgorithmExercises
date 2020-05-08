#pragma once
#include "../BASE.h"

/*
请实现一个函数用来匹配包含'. '和'*'的正则表达式。*

模式中的字符 '.'表示任意一个字符，而 '\*'表示它前面的字符可以出现任意次（含0次）。

在本题中，匹配是指字符串的所有字符匹配整个模式。

例如，字符串"aaa"与模式"a.a"和"ab\*ac\*a"匹配，但与"aa.a"和"ab\*a"均不匹配。
*/
class S_19_IsMatch : public BASE {
public:
	virtual void main()
    {
    }
    bool isMatch(string s, string p) 
    {
        if (p.empty()) 
            return s.empty();
        if (p[1] == '*') // p后移两位，或者p不动，s后移一位
        {
            return isMatch(s, p.substr(2)) 
                || ( (!s.empty() && (s[0] == p[0] || p[0] == '.')) && isMatch(s.substr(1), p) );
        }
        else // s和p同时后移一位
        {
            return !s.empty() 
                && (s[0] == p[0] || p[0] == '.') 
                && (isMatch(s.substr(1), p.substr(1)));
        }
    }
};