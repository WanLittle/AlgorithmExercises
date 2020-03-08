#pragma once
#include "../BASE.h"

class V_kuohao_match : public BASE {
public:
    virtual void main()
    {
        cout << kuohaomatch("((){}") << endl; // 0
        cout << kuohaomatch("((){})") << endl; // 1
    }
    bool kuohaomatch(const std::string &str)
    {
        std::stack<char> st;
        for (char i : str)
        {
            switch (i)
            {
            case '(':st.push(i); break;
            case '[':st.push(i); break;
            case '{':st.push(i); break;
            case ')':
                if (st.top() != '(')
                    return false;
                else
                    st.pop(); 
                    break;
            case ']':
                if (st.top() != '[')
                    return false;
                else
                    st.pop(); break;
            case '}':
                if (st.top() != '{')
                    return false;
                else
                    st.pop(); break;
            default:
                assert(false);
                break;
            }
        }
        return st.empty();
    }
};