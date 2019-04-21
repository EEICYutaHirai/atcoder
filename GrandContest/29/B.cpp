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
    int N;
    cin >> N;
    vector<int> data;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    sort(data.begin(), data.end());
    vector<bool> is_pair(N, false);
    int ans = 0;
    for (int i = 31; i > 0; i--)
    {
        int tpow = (1 << i);
        cout << tpow << endl;
        for (int j = N - 1; j >= 0; j--)
        {
            if (is_pair[j])
            {
                continue;
            }
            auto low = lower_bound(data.begin(), data.end(), tpow - data[j]);
            auto up = upper_bound(data.begin(), data.end(), tpow - data[j]);
            if (up - low > 0)
            {
                if (j == (low - data.begin()))
                {
                    continue;
                }
                is_pair[j] = true;
                is_pair[low - data.begin()] = true;
                ans++;
            }
        }
    }
    cout << ans << endl;
}