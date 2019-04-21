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

string nine[9];

bool solve(int nblack)
{
}

int main()
{
    string ans[9];
    rep(i, 9)
    {
        ans[i] = ".........";
    }
    for (int i = 0; i < 9; i++)
    {
        ans[4][i] = '#';
        ans[i][4] = '#';
    }

    rep(i, 9)
    {
        cout << ans[i] << endl;
    }
    return 0;
}