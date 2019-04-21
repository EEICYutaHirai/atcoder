#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    vector<ll> acc(N + 1);

    cin >> N >> M;
    acc[0] = 0;
    ll tmp;
    map<ll, ll> mp;
    mp[0]++;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        acc[i] = (acc[i - 1] + tmp) % M;
        mp[acc[i]]++;
    }

    ll ans = 0;
    for (auto m : mp)
    {
        ans += m.second * (m.second - 1) / 2;
    }
    cout << ans << endl;
}