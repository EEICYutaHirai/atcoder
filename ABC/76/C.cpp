/*
title:

url:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <queue>
#include <limits>
#include <string>
#include <utility>
#include <cstring>
#include <map>
#include <cmath>
#include <iterator>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    string s, t;
    cin >> s >> t;
    int index = -1;
    bool exist = false;
    for (int i = 0; i + t.size() - 1 < s.size(); i++)
    {
        bool tmp = true;
        for (int j = 0; j < t.size(); j++)
        {
            if (!(s[i + j] == t[j] || s[i + j] == '?'))
            {
                tmp = false;
                break;
            }
        }
        if (tmp)
        {
            index = i;
        }
    }

    if (index >= 0)
    {
        for (int i = index; i < index + t.size(); i++)
        {
            s[i] = t[i - index];
        }
        rep(i, s.size())
        {
            if (s[i] == '?')
                s[i] = 'a';
        }
    }
    else
    {
        s = "UNRESTORABLE";
    }
    cout << s << endl;
    return 0;
}