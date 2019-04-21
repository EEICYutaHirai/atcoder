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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int h, w;
    cin >> h >> w;
    string data[h];
    for (int i = 0; i < h; i++)
    {
        cin >> data[i];
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (data[i][j] == '#')
            {
                bool has_black = false;
                for (int k = 0; k < 4; k++)
                {
                    if (i + dx[k] >= 0 && i + dx[k] < h && j + dy[k] >= 0 && j + dy[k] < w)
                    {
                        if (data[i + dx[k]][j + dy[k]] == '#')
                        {
                            has_black = true;
                        }
                    }
                }
                if (!has_black)
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}