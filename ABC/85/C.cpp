/*
title:

url:

再帰で最初解こうと思ったが、実装後に時間がかかりすぎることが分かった。
しかし、その考察から正しいコードを書くことができた。
とにかく書いてみることが大事か
（ただし、結構ぎりぎりだった）
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

int ans[3] = {};
int fans[3] = {};
int mny[3] = {10000, 5000, 1000};
int n, y;

//もし, n=a+b+cなら、1を返し、無理なら0を返す
int solve(int a, int b, int c)
{
    if (n == a + b + c)
    {
        fans[0] = a;
        fans[1] = b;
        fans[2] = c;
        return 1;
    }
    if (a < 0 || b < 0 || c < 0 || a + b + c > n)
    {
        return 0;
    }
    return max({solve(a - 1, b + 2, c), solve(a - 1, b, c + 10), solve(a, b - 1, c + 5)});
}

int main()
{
    cin >> n >> y;
    int sum = 0;
    rep(i, 3)
    {
        ans[i] = y / mny[i];
        sum += ans[i];
        y -= ans[i] * mny[i];
    }

    for (int i = 0; i <= ans[0]; i++)
    {
        for (int j = 0; j <= ans[0] - i; j++)
        {
            for (int k = 0; k <= ans[1] + 2 * i; k++)
            {
                if (n == ans[0] - i - j + ans[1] + 2 * i - k + ans[2] + 10 * j + 5 * k)
                {
                    cout << ans[0] - i - j << " " << ans[1] + 2 * i - k
                         << " " << ans[2] + 10 * j + 5 * k << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}