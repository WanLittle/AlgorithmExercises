#pragma once
#include "../BASE.h"

/*
��ʵ��һ����������ƥ�����'. '��'*'��������ʽ��*

ģʽ�е��ַ� '.'��ʾ����һ���ַ����� '\*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ���

�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��

���磬�ַ���"aaa"��ģʽ"a.a"��"ab\*ac\*a"ƥ�䣬����"aa.a"��"ab\*a"����ƥ�䡣
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
        if (p[1] == '*') // p������λ������p������s����һλ
        {
            return isMatch(s, p.substr(2)) 
                || ( (!s.empty() && (s[0] == p[0] || p[0] == '.')) && isMatch(s.substr(1), p) );
        }
        else // s��pͬʱ����һλ
        {
            return !s.empty() 
                && (s[0] == p[0] || p[0] == '.') 
                && (isMatch(s.substr(1), p.substr(1)));
        }
    }
};