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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

//あるものの中身だけを知りたい場合には、累積和を使えば走査せずに済む

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    int data[N + 1][N + 1];
    memset(data, 0, sizeof(data));
    REP(i, M)
    {
        int L, R;
        scanf("%d %d", &L, &R);
        data[L][R]++;
    }
    int acc[N + 1][N + 1];
    memset(acc, 0, sizeof(acc));
    //累積和をつくるときのindexに注意。
    //index=0のとき、0とし、index＝1にはじめの要素を対応させる
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            acc[i][j] = acc[i - 1][j] + data[i][j];
        }
    }
    int p[Q], q[Q];
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &p[i], &q[i]);
    }
    for (int i = 0; i < Q; i++)
    {
        int ans = 0;
        for (int j = p[i]; j <= q[i]; j++)
        {
            ans += (acc[q[i]][j] - acc[p[i] - 1][j]);
        }
        cout << ans << endl;
    }
    return 0;
}