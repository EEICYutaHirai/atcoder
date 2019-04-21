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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int x[5], y[5];
    cin >> x[1] >> y[1] >> x[2] >> y[2];
    int dx = x[2] - x[1];
    int dy = y[2] - y[1];

    int dx23 = -dy;
    int dy23 = dx;
    x[3] = x[2] + dx23;
    y[3] = y[2] + dy23;

    int dx34 = -dy23;
    int dy34 = dx23;
    x[4] = x[3] + dx34;
    y[4] = y[3] + dy34;

    cout << x[3] << " " << y[3] << " " << x[4] << " " << y[4] << endl;
}