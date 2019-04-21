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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> data;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    vector<int> sum_data;
    vector<int> syakutori;
    syakutori.push_back(0);
    rep(i, N)
    {
        syakutori.push_back(syakutori[i] + data[i]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            sum_data.push_back(syakutori[j + 1] - syakutori[i]);
        }
    }
    sort(sum_data.begin(), sum_data.end(), greater<int>());
    for (int i = 0; i < sum_data.size(); i++)
    {
        sum_data[i] = sum_data[i] & sum_data[0];
    }
    sort(sum_data.begin(), sum_data.end(), greater<int>());
    int ans = sum_data[0];
    for (int i = 1; i < K; i++)
    {
        ans = ans & sum_data[i];
    }
    cout << ans << endl;
}