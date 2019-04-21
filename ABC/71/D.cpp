/*
title:

url:

中学受験にありそう
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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int N;
    cin >> N;
    string s[2];
    cin >> s[0] >> s[1];

    int ans = 3;
    if (N == 1)
    {
        cout << ans << endl;
        return 0;
    }
    bool pre_tate = true;
    int now_index = 1;
    if (s[0][0] == s[0][1])
    {
        ans *= 2;
        pre_tate = false;
        now_index = 2;
    }
    while (now_index < N)
    {
        if (s[0][now_index] == s[0][now_index + 1])
        {
            if (pre_tate)
            {
                ans *= 2;
            }
            else
            {
                ans *= 3;
            }
            now_index += 2;
            ans %= INF;
            pre_tate = false;
        }
        else
        {
            if (pre_tate)
            {
                ans *= 2;
            }
            now_index++;
            ans %= INF;
            pre_tate = true;
        }
    }
    cout << ans << endl;
}