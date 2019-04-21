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
#define INF 1000000000000007
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int N;
    cin >> N;
    int A[N];
    int sum = 0;
    rep(i, N)
    {
        cin >> A[i];
        sum += A[i];
    }

    int ans = INF;
    int tmp_sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        tmp_sum += A[i];
        sum -= A[i];
        ans = min(ans, abs(tmp_sum - sum));
    }
    cout << ans << endl;
    return 0;
}