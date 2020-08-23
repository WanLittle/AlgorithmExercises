#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const float EPSINON = 0.00001f;
inline float feuqal(float n1, float n2) { return std::abs(n1 - n2) > EPSINON; }


int main2(void)
{
    string s = "\045";
    cout << s << endl;
    cout << sizeof("123\04567") << endl;
    return 0;
}