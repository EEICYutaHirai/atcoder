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
    string a[2];
    rep(i, 2)
    {
        cin >> a[i];
    }

    rep(i, 2)
    {
        if (!(a[i][0] == a[(i + 1) % 2][2] && a[i][1] == a[(i + 1) % 2][1] &&
              a[i][2] == a[(i + 1) % 2][0]))
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}