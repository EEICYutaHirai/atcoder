/*
title:

url:

エラスとてネスと累積和の問題
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
    int n;
    cin >> n;

    bool is_prime[(int)1e5 + 1];
    fill(is_prime, is_prime + (int)1e5 + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt((int)1e5); i++)
    {
        if (is_prime[i])
        {
            for (int j = i + i; j <= (int)1e5; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    bool is_similar[(int)1e5 + 1];
    fill(is_similar, is_similar + (int)1e5 + 1, false);
    for (int i = 3; i < (int)1e5 + 1; i += 2)
    {
        if (is_prime[i] && is_prime[(i + 1) / 2])
        {
            is_similar[i] = true;
        }
    }

    //[0, index]までの和（indexを含むので注意）
    int cum_sum[(int)1e5 + 1] = {};
    for (int i = 3; i < (int)1e5 + 1; i++)
    {
        cum_sum[i] = cum_sum[i - 1];
        if (is_similar[i])
        {
            cum_sum[i]++;
        }
    }

    int l[n], r[n];
    rep(i, n)
    {
        cin >> l[i] >> r[i];
        if (l[i] <= 2)
        {
            l[i] = 3;
        }
    }

    rep(i, n)
    {
        cout << cum_sum[r[i]] - cum_sum[l[i] - 1] << endl;
    }
}