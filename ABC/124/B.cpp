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
    int N;
    cin >> N;
    vector<int> H;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        H.push_back(tmp);
        bool f = true;
        for (int j = 0; j < i; j++)
        {
            if (H[j] > H[i])
            {
                f = false;
                break;
            }
        }
        if (f)
            ans++;
    }
    cout << ans << endl;
}