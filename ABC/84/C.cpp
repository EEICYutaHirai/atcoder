/*
title:

url:

決してきれいな解き方ではないが、計算量的にはこれでok
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
    int c[n], s[n], f[n];
    rep(i, n - 1)
    {
        cin >> c[i] >> s[i] >> f[i];
    }

    int ans[n] = {};
    //ans[i]はi駅からN駅に行くとき到着する時間
    rep(i, n - 1)
    {
        int time = 0;
        for (int j = i; j < n - 1; j++)
        {
            if (!(time >= s[j] && (time % f[j]) == 0))
            {
                time += (f[j] - (time % f[j]));
                if (time < s[j])
                    time = s[j];
            }
            time += c[j];
        }
        ans[i] = time;
    }

    rep(i, n)
    {
        cout << ans[i] << endl;
    }
}