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

#define int ll

//get vector of prime numbers which is lower than or equal n
vector<int> get_primes(int n)
{
    vector<bool> is_prime(n + 1, true);
    vector<int> res;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            res.push_back(i);
            for (int j = 2 * i; j < is_prime.size(); j = j + i)
            {
                is_prime[j] = false;
            }
        }
    }
    return res;
}

vector<pair<int, int>> factorize(int n)
{
    vector<pair<int, int>> res;
    for (int i = 2; i * i <= n; i++)
    {
        int tmp = 0;
        while (n % i == 0)
        {
            tmp++;
            n /= i;
        }
        res.push_back(make_pair(i, tmp));
    }
    if (n != 1)
    {
        res.push_back(make_pair(n, 1));
    }
    return res;
}

int mpow(int x, int n)
{
    int res = 1;
    while (n != 0)
    {
        if (n & 1)
            res = res * x % INF;
        x = x * x % INF;
        n = n >> 1;
    }
    return res;
}

//mod frac
vector<int> mfrac;
void set_mfrac(int n)
{
    if (mfrac.size() == 0)
    {
        mfrac.push_back(1);
    }
    for (int i = mfrac.size(); i <= n; i++)
    {
        mfrac.push_back((i * mfrac[i - 1]) % INF);
    }
}

//get nCm mod INF
int mcomb(int n, int m)
{
    if (mfrac.size() <= n)
    {
        set_mfrac(n);
    }
    int res = mfrac[n];
    res = res * mpow(mfrac[m], INF - 2) % INF;
    res = res * mpow(mfrac[n - m], INF - 2) % INF;
    return res;
}

signed main()
{
    int N;
    cin >> N;
    vector<int> odd(100000 + 1, 0);
    vector<int> even(100000 + 1, 0);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (i % 2 == 0)
        {
            even[tmp]++;
        }
        else
        {
            odd[tmp]++;
        }
    }

    int odd_index = 0;
    int even_index = 0;
    int odd_max = 0, even_max = 0;
    for (int i = 0; i < 100001; i++)
    {
        if (odd[i] > odd_max)
        {
            odd_index = i;
            odd_max = odd[i];
        }
        if (even[i] > even_max)
        {
            even_index = i;
            even_max = even[i];
        }
    }
    if (odd_index != even_index)
    {
        cout << N - odd[odd_index] - even[even_index] << endl;
    }
    else
    {
        odd[odd_index] = 0;
        even[even_index] = 0;

        int odd_index2 = 0;
        int even_index2 = 0;
        int odd_max2 = 0, even_max2 = 0;
        for (int i = 0; i < 100001; i++)
        {
            if (odd[i] > odd_max2)
            {
                odd_index2 = i;
                odd_max2 = odd[i];
            }
            if (even[i] > even_max2)
            {
                even_index2 = i;
                even_max2 = even[i];
            }
        }

        cout << min(N - odd_max - even_max2, N - odd_max2 - even_max) << endl;
    }
    return 0;
}