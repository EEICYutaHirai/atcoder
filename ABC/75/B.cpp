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
    int h, w;
    cin >> h >> w;
    string data[h];
    rep(i, h)
    {
        cin >> data[i];
    }

    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    rep(i, h)
    {
        rep(j, w)
        {
            if (data[i][j] == '.')
            {
                int count = 0;
                rep(k, 8)
                {
                    if (i + dx[k] >= 0 && i + dx[k] < h && j + dy[k] >= 0 && j + dy[k] < w)
                    {
                        if (data[i + dx[k]][j + dy[k]] == '#')
                        {
                            count++;
                        }
                    }
                }
                data[i][j] = count + '0';
            }
        }
    }
    rep(i, h)
    {
        cout << data[i] << endl;
    }
    return 0;
}