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
    int ans = INF;
    int n;
    cin >> n;
    rep(i, n)
    {
        int tmp;
        int tmp_ans = 0;
        cin >> tmp;
        while ((tmp % 2) == 0)
        {
            tmp_ans++;
            tmp /= 2;
        }
        ans = min(ans, tmp_ans);
    }
    cout << ans << endl;
}