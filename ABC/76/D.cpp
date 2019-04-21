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
    int n;
    cin >> n;
    vector<int> t, v;
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        t.push_back(tmp);
    }
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    v.push_back(0);

    //time,speed
    vector<pint> data;
    int now_speed = 0;
    double ans = 0.0;
    rep(i, n)
    {
        int next_speed;
        int start_dec = max(0, t[i] - max(0, v[i] - v[i + 1])); //0
        int achieve_max_speed = v[i] - now_speed;               //5
        if (start_dec < achieve_max_speed)
        {
            next_speed = now_speed + start_dec;
            ans += 0.5 * (double)((double)now_speed + (double)next_speed) * (double)start_dec;
            now_speed = next_speed;
            next_speed = v[i + 1];
            ans += 0.5 * (double)((double)now_speed + (double)next_speed) * (double)max(0, now_speed - v[i + 1]);
            now_speed = next_speed;
        }
        else
        {
            next_speed = v[i];
            ans += 0.5 * (double)((double)now_speed + (double)next_speed) * (double)(v[i] - now_speed); //0.5*(0+30)*30=450
            now_speed = v[i];
            next_speed = v[i];
            ans += 0.5 * (double)((double)now_speed + (double)next_speed) * (double)(start_dec - achieve_max_speed); //0.5*(30+30)*40=1200
            next_speed = v[i + 1];
            ans += 0.5 * (double)((double)now_speed + (double)next_speed) * (double)(max(0, v[i] - v[i + 1])); //0.5*(30+0)
            now_speed = min(v[i], v[i + 1]);
        }
        cout << ans << endl;
    }
    cout << ans << endl;
}