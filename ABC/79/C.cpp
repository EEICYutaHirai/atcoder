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

int cal(int n, int ans, int data)
{
    if (n)
    {
        ans += data;
    }
    else
    {
        ans -= data;
    }
    return ans;
}

void pans(int i, int j, int k, int *data)
{
    cout << data[0];
    int op[4] = {0, i, j, k};
    for (int x = 1; x < 4; x++)
    {
        if (op[x])
        {
            cout << "+";
        }
        else
        {
            cout << "-";
        }
        cout << data[x];
    }
    cout << "=7";
    cout << endl;
}

int main()
{
    string s;
    int data[4];
    cin >> s;
    rep(i, 4)
    {
        data[i] = (int)(s[i] - '0');
    }

    rep(i, 2)
    {
        rep(j, 2)
        {
            rep(k, 2)
            {
                int ans = data[0];
                ans = cal(i, ans, data[1]);
                ans = cal(j, ans, data[2]);
                ans = cal(k, ans, data[3]);
                if (ans == 7)
                {
                    pans(i, j, k, data);
                    return 0;
                }
            }
        }
    }
}