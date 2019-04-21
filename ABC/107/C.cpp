#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
#include <limits>
#include <cstdlib>

using namespace std;

int main()
{
    int N, K;
    scanf("%d %d\n", &N, &K);
    int pos[N];
    int neg[N];
    //n_pos ... number of elements
    int n_pos = 0;
    int n_neg = 0;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp < 0)
        {
            neg[n_neg] = tmp;
            n_neg++;
        }
        else
        {
            pos[n_pos] = tmp;
            n_pos++;
        }
    }

    //negを降順にする
    for (int i = 0; i < n_neg / 2; i++)
    {
        swap(neg[i], neg[n_neg - i - 1]);
    }

    long long ans = numeric_limits<long long>::max();

    //iは何回、正のろうそくを回収するか
    //負のろうそくは K-i 回回収することになる。
    for (int i = 0; i <= K; i++)
    {
        if (i <= n_pos && (K - i) <= n_neg)
        {
            int tmp;
            if (i == 0)
            {
                tmp = -neg[K - i - 1];
            }
            else if (i == K)
            {
                tmp = pos[K - 1];
            }
            else
            {
                tmp = pos[i - 1] - neg[K - i - 1] + min(pos[i - 1], -neg[K - i - 1]);
            }
            //ans更新
            if (tmp < ans)
            {
                ans = tmp;
            }
        }
    }
    cout << ans << endl;
}