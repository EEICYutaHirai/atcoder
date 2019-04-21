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
    int a[3];
    cin >> a[0] >> a[1];
    a[2] = a[0] + a[1];
    rep(i, 3)
    {
        if (a[i] % 3 == 0)
        {
            cout << "Possible" << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}