/*
title:

url:

整数同士の比較はなるべく整数で行おう
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
    int water[2], sugar[2];
    int can_dis, can_in;
    rep(i, 2)
    {
        cin >> water[i];
    }
    rep(i, 2)
    {
        cin >> sugar[i];
    }
    cin >> can_dis >> can_in;

    vector<int> ans(2, 0);
    for (int i = 0; i * water[0] * 100 <= can_in; i++)
    {
        for (int j = 0; i * water[0] * 100 + j * water[1] * 100 <= can_in; j++)
        {
            int max_sugar = min(can_in - (i * water[0] * 100 + j * water[1] * 100), (i * water[0] + j * water[1]) * can_dis);
            for (int k = 0; k * sugar[0] <= max_sugar; k++)
            {
                for (int l = 0; k * sugar[0] + l * sugar[1] <= max_sugar; l++)
                {
                    int tmp_all = i * water[0] * 100 + j * water[1] * 100 + k * sugar[0] + l * sugar[1];
                    int tmp_sugar = k * sugar[0] + l * sugar[1];
                    if (tmp_all * ans[1] <= tmp_sugar * ans[0])
                    {
                        ans[0] = (int)tmp_all;
                        ans[1] = (int)tmp_sugar;
                    }
                }
            }
        }
    }
    cout << ans[0] << " " << ans[1] << endl;
}