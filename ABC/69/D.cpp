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
    int H, W, N;
    cin >> H >> W >> N;
    int color[N];
    rep(i, N)
    {
        cin >> color[i];
    }

    int ans[H][W];
    int index = 0;
    rep(i, H)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < W; j++)
            {
                if (color[index] == 0)
                {
                    index++;
                }
                ans[i][j] = index + 1;
                color[index]--;
            }
        }
        else
        {
            for (int j = W - 1; j >= 0; j--)
            {
                if (color[index] == 0)
                {
                    index++;
                }
                ans[i][j] = index + 1;
                color[index]--;
            }
        }
    }

    rep(i, H)
    {
        rep(j, W)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}