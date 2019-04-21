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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string ss[n];
    REP(i, n)
    {
        cin >> ss[i];
    }
    bool ans = true;
    for (int i = 1; i < n; i++)
    {
        if (ss[i - 1][ss[i - 1].size() - 1] != ss[i][0])
        {
            ans = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ss[i] == ss[j])
            {
                ans = false;
            }
        }
    }
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}