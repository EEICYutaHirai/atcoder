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

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int c[3][3];
    REP(i, 3)
    {
        REP(j, 3)
        {
            cin >> c[i][j];
        }
    }

    REP(i, 3)
    {
        REP(j, 3)
        {
            if (!((c[i][j] - c[(i + 1) % 3][j]) == (c[i][(j + 1) % 3] - c[(i + 1) % 3][(j + 1) % 3]) &&
                  (c[i][j] - c[(i + 1) % 3][j]) == (c[i][(j + 2) % 3] - c[(i + 1) % 3][(j + 2) % 3])))
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    REP(i, 3)
    {
        REP(j, 3)
        {
            if (!((c[j][i] - c[j][(i + 1) % 3]) == (c[(j + 1) % 3][i] - c[(j + 1) % 3][(i + 1) % 3]) &&
                  (c[j][i] - c[j][(i + 1) % 3]) == (c[(j + 2) % 3][i] - c[(j + 2) % 3][(i + 1) % 3])))
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}