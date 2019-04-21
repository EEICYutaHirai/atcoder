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
    int h, w;
    cin >> h >> w;
    int coin[h][w];
    int coin2[h][w];
    REP(i, h)
    {
        REP(j, w)
        {
            cin >> coin[i][j];
            coin2[i][j] = coin[i][j];
        }
    }
    int count = 0;
    REP(i, h - 1)
    {
        REP(j, w)
        {
            if (coin[i][j] % 2 == 1)
            {
                coin[i + 1][j]++;
                count++;
            }
        }
    }
    REP(i, w - 1)
    {
        if (coin[h - 1][i] % 2 == 1)
        {
            coin[h - 1][i + 1]++;
            count++;
        }
    }
    cout << count << endl;
    REP(i, h - 1)
    {
        REP(j, w)
        {
            if (coin2[i][j] % 2 == 1)
            {
                cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << endl;
                coin2[i + 1][j]++;
            }
        }
    }
    REP(i, w - 1)
    {
        if (coin2[h - 1][i] % 2 == 1)
        {
            cout << h << " " << i + 1 << " " << h << " " << i + 2 << endl;
            coin2[h - 1][i + 1]++;
        }
    }
}