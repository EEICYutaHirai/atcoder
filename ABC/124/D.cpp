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

#define int ll

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

int max(int a, int b)
{
    if (a < b)
    {
        return b;
    }
    return a;
}

signed main()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    //偶数ー＞0の累積わ
    //奇数ー＞1の累積わ
    //2*k -> k番目までのセクションの和
    //2 * k + 1 同様

    vector<int> cum_sum_zero;
    vector<int> cum_sum_one;
    cum_sum_zero.push_back(0);
    cum_sum_one.push_back(0);
    int i = 0;
    while (i < S.size())
    {
        int tmp = 0;
        while (tmp + i < S.size() && S[i] == S[i + tmp])
        {
            tmp++;
        }
        if (S[i] == '1')
        {
            cum_sum_one.push_back(tmp + cum_sum_one[cum_sum_one.size() - 1]);
        }
        else
        {
            cum_sum_zero.push_back(tmp + cum_sum_zero[cum_sum_zero.size() - 1]);
        }
        i += tmp;
    }

    int ans = 0;
    for (int i = 0; i < cum_sum_zero.size(); i++)
    {
        int tmp_ans = 0;
        tmp_ans = cum_sum_zero[min(i + K, cum_sum_zero.size() - 1)] - cum_sum_zero[i];
        if (S[0] == '0')
        {
            tmp_ans += cum_sum_one[min(i + K + 1, cum_sum_one.size() - 1)] - cum_sum_one[max(0, i)];
        }
        else
        {
            tmp_ans += cum_sum_one[min(i + K, cum_sum_one.size() - 1)] - cum_sum_one[max(0, i - 1)];
        }
        cout << tmp_ans << endl;
        ans = max(ans, tmp_ans);
    }

    cout << ans << endl;
}