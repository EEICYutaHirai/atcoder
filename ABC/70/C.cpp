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

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

signed main()
{
    int N;
    cin >> N;
    int data[N];
    rep(i, N)
    {
        cin >> data[i];
    }

    int ans = data[0];
    rep(i, N - 1)
    {
        if (data[i + 1] % ans == 0)
        {
            ans = data[i + 1];
        }
        else if (ans % data[i + 1] == 0)
        {
            continue;
        }
        else
        {
            int tmp = gcd(ans, data[i + 1]);
            data[i + 1] /= tmp;
            ans *= data[i + 1];
        }
    }
    cout << ans << endl;
}