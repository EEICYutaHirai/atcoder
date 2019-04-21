/*
title:D - Xor Sum 2

url:

方針:
解説の方針にのっとてとく
a + b - (a xor b) = a and b
なので、各ビットの和がすべて１である場合を除いて、(l, r)は条件を満たす
ただし、これはandのところが、数字二つの時のみでしか成り立たないので注意
(数字が３つの時に拡張できない)
また、a=bの時は別
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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int n;
    cin >> n;
    int data[n];
    //(l, r) = sum[r] - sum[l-1]
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    //l=rの時はあらかじめカウントしておく
    int ans = n;
    for (int l = 0; l < n; l++)
    {
        int r = l + 1;
        for (; r < n; r++)
        {
            if ((data[r] & data[r - 1]) != 0)
                break;
        }
        r--;
        for (int i = 0; i <= r - l; i++)
        {
            ans += i;
        }
        l = r;
        cout << "l:" << l << " r:" << r - 1 << endl;
    }

    cout << ans << endl;
}