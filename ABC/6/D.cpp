/*
昇順に並んでいないもののかずの最大値＝答えになっている。
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

typedef pair<int, int> Pii;
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

vector<int> get_gcd(int n)
{
    vector<int> res;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                res.push_back(i);
            }
            else
            {
                res.push_back(i);
                res.push_back(n / i);
            }
        }
    }
    return res;
}

class UnionFind
{
  private:
    vector<int> id;
    vector<int> sz;

    int get_id(int x)
    {
        while (x != id[x])
        {
            x = id[x] = id[id[x]];
        }
        return x;
    }

  public:
    UnionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            id.push_back(i);
            sz.push_back(1);
        }
    }

    bool connected(int x, int y)
    {
        return get_id(x) == get_id(y);
    }

    void connect(int x, int y)
    {
        int xid = get_id(x);
        int yid = get_id(y);
        if (sz[xid] < sz[yid])
        {
            id[xid] = yid;
            sz[yid] += sz[xid];
        }
        else
        {
            id[yid] = xid;
            sz[xid] += sz[yid];
        }
    }

    int get_size(int x)
    {
        return sz[get_id(x)];
    }
};

template <class T>
std::vector<std::vector<T>> Imos2D(const std::vector<std::vector<T>> &a)
{
    int h = a.size(), w = a[0].size();
    std::vector<std::vector<T>> s(h + 1, std::vector<T>(w + 1, 0));
    rep(i, h) rep(j, w) s[i + 1][j + 1] = a[i][j];
    rep(i, h + 1) rep(j, w) s[i][j + 1] += s[i][j];
    rep(i, h) rep(j, w + 1) s[i + 1][j] += s[i][j];
    return s;
}

template <class T>
int sum(const std::vector<std::vector<T>> &s, int i, int j, int h, int w)
{
    return s[i + h][j + w] - s[i][j + w] + s[i][j] - s[i + h][j];
}

vector<int> vData;
int N;

//index以降でlastよりも大きいかつ昇順に並んでいるものの最大値
//solve(0, vData[0]) で呼び出す
int solve(int index, int last)
{
    if (index == N - 1)
        return 1;
    if (last < vData[index + 1])
    {
        return max(solve(index + 1, vData[index + 1]) + 1, solve(index + 1, last));
    }
    else
    {
        return solve(index + 1, last);
    }
}

//n<=16
/*
signed main()
{
    int N;
    cin >> N;
    vector<int> data;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    if (N >= 20)
    {
        cout << 0 << endl;
    }
    int ans = N;
    for (int i = 0; i < (1 << N); i++)
    {
        int last = INF;
        int tmp_ans = N;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                if (last == INF)
                {
                    last = data[j];
                    tmp_ans--;
                }
                else if (last < data[j])
                {
                    last = data[j];
                    tmp_ans--;
                }
                else
                {
                    break;
                }
            }
        }
        ans = min(ans, tmp_ans);
    }
    cout << ans << endl;
}
*/

//n <= 1000

signed main()
{
    int N;
    cin >> N;
    vector<int> data(N);
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        data[i] = tmp;
    }

    //index iまでの最大のソートされた列の長さ
    vector<int> max_length(N, 1);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (data[j] < data[i] && max_length[j] + 1 > max_length[i])
            {
                max_length[i] = max_length[j] + 1;
            }
        }
    }

    cout << N - *max_element(max_length.begin(), max_length.end()) << endl;
}
