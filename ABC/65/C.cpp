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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int N, M;
    cin >> N >> M;
    if (abs(N - M) > 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    for (int i = 1; i <= N; i++)
    {
        ans *= i;
        ans %= INF;
    }
    for (int i = 1; i <= M; i++)
    {
        ans *= i;
        ans %= INF;
    }
    if ((N + M) % 2 == 0)
    {
        cout << (ans * 2) % INF << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}