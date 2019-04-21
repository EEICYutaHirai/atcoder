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

int H, W;
string map_data[10];

//sec秒後のposを指定
string solve(int sec, int pos)
{
    if (pos < 0)
    {
        return "";
    }
    if (pos >= W)
    {
        return "";
    }
    if (sec == H)
    {
        return "";
    }
    if (map_data[H - 1 - sec][pos] == 'x')
    {
        return "";
    }

    string tmp_ans[3];
    tmp_ans[0] = "S" + solve(sec + 1, pos);
    tmp_ans[1] = "R" + solve(sec + 1, pos + 1);
    tmp_ans[2] = "L" + solve(sec + 1, pos - 1);
    rep(i, 3)
    {
        if (tmp_ans[i].size() == H - sec)
        {
            return tmp_ans[i];
        }
    }
    return "";
}

int main()
{
    cin >> H >> W;

    rep(i, H)
    {
        cin >> map_data[i];
    }

    int start = 0;
    rep(i, W)
    {
        if (map_data[H - 1][i] == 's')
        {
            start = i;
            break;
        }
    }
    string ans = solve(0, start);
    if (ans.size() == H)
    {
        rep(i, ans.size() - 1)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    else
    {
        cout << "impossible" << endl;
    }
    return 0;
}