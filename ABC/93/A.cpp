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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    string test = "abc";
    bool has_abc[3] = {false, false, false};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (s[i] == test[j])
            {
                has_abc[j] = true;
            }
        }
    }

    if (has_abc[0] && has_abc[1] && has_abc[2])
    {
        cout << "Yes" << endl;
        return 0;
    }
    else
    {
        cout << "No" << endl;
        return 0;
    }
}