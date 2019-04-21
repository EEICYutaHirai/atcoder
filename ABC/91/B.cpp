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
    int n, m;
    cin >> n;
    string s[n];
    bool bs[n];
    REP(i, n)
    {
        string tmp;
        cin >> tmp;
        s[i] = tmp;
        bs[i] = false;
    }

    cin >> m;
    string t[m];
    bool bt[m];
    REP(i, m)
    {
        string tmp;
        cin >> tmp;
        t[i] = tmp;
        bt[i] = false;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int tmpans = 0;
        if (bs[i])
            continue;
        for (int j = i; j < n; j++)
        {
            if (s[i] == s[j])
            {
                tmpans++;
                bs[j] = true;
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (s[i] == t[j])
            {
                tmpans--;
                bt[j] = true;
            }
        }
        ans = max(ans, tmpans);
    }

    for (int i = 0; i < m; i++)
    {
        int tmpans = 0;
        if (bt[i])
            continue;
        for (int j = i; j < m; j++)
        {
            if (t[i] == t[j])
            {
                tmpans--;
                bt[j] = true;
            }
        }
        ans = max(ans, tmpans);
    }
    cout << ans << endl;
}