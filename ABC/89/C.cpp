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

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int n;
    cin >> n;
    int n_name[5] = {};
    char prefix[5] = {'M', 'A', 'R', 'C', 'H'};
    REP(i, n)
    {
        string tmp;
        cin >> tmp;
        REP(j, 5)
        {
            if (tmp[0] == prefix[j])
            {
                n_name[j]++;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                ans += n_name[i] * n_name[j] * n_name[k];
            }
        }
    }
    cout << ans << endl;
}