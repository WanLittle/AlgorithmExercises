/*
OJ在线编程常见输入输出练习场
https://ac.nowcoder.com/acm/contest/5649#question
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int testA()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << a + b << endl;
    }
    return 0;
}

int testB()
{
    int n;
    int a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}

int testC()
{
    int a, b;
    while (cin >> a >> b)
    {
        int result = a + b;
        if (!result)
            break;
        cout << result << endl;
    }
    return 0;
}

int testD()
{
    int n;
    while (cin >> n)
    {
        if (!n) break;
        int result = 0;
        while (n--)
        {
            int num;
            cin >> num;
            result += num;
        }
        cout << result << endl;
    }
    return 0;
}

int testE()
{
    int group;
    cin >> group;
    while (group--)
    {
        int n;
        while (cin >> n)
        {
            int result = 0;
            while (n--)
            {
                int num;
                cin >> num;
                result += num;
            }
            cout << result << endl;
        }
    }
}

int testF()
{
    int n;
    while (cin >> n)
    {
        if (!n) break;
        int result = 0;
        while (n--)
        {
            int num;
            cin >> num;
            result += num;
        }
        cout << result << endl;
    }
    return 0;
}

int testG()
{
    int num;
    int sum = 0;
    while (cin >> num)
    {
        sum += num;
        while (cin.get() != '\n')
        {
            cin >> num;
            sum += num;
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}

int testH()
{
    vector<string> strarr;
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        cin.get();
        strarr.push_back(str);
    }
    sort(strarr.begin(), strarr.end(), [](string a, string b) {return a < b;});
    for (int i = 0; i < strarr.size(); ++i)
    {
        cout << strarr[i];
        if (i != strarr.size() - 1)
            cout << " ";
    }
    return 0;
}

int testI()
{
    vector<string> strarr;
    string str;
    while (cin >> str)
    {
        strarr.push_back(str);
        while (cin.get() != '\n')
        {
            cin >> str;
            strarr.push_back(str);
        }
        sort(strarr.begin(), strarr.end(), [](string a, string b) {return a < b; });
        for (int i = 0; i < strarr.size(); ++i)
        {
            cout << strarr[i];
            if (i != strarr.size() - 1)
                cout << " ";
        }
        cout << endl;
        strarr.clear();
    }
    return 0;
}

int testJ()
{
    string str;
    string line;
    vector<string> strarr;
    int pos;
    while (getline(cin, line)) 
    {
        while ((pos = line.find(',')) != string::npos) 
        {
            str = line.substr(0, pos);
            line = line.substr(pos + 1);
            strarr.push_back(str);
        }
        strarr.push_back(line);
        sort(strarr.begin(), strarr.end());
        for (int idx = 0; idx < strarr.size() - 1; ++idx) 
        {
            cout << strarr[idx] << ',';
        }
        cout << strarr.back() << endl;
        strarr.clear();
    }
    return 0;
}

int testK()
{
    long a, b;
    while (cin >> a >> b)
    {
        cout << a + b << endl;
    }
    return 0;
}
