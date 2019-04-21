/*
title:

url:

簡単
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
    bool is_same[N];
    fill(is_same, is_same + N, false);
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        tmp--;
        if (i == tmp)
        {
            is_same[i] = true;
        }
    }

    int ans = 0;
    rep(i, N)
    {
        if (is_same[i])
        {
            ans++;
            if (i + 1 < N && is_same[i + 1])
            {
                is_same[i + 1] = false;
            }
        }
    }

    cout << ans << endl;
}