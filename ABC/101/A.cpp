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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> p_i;

int main()
{
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
            res++;
        if (s[i] == '-')
            res--;
    }
    cout << res << endl;
}