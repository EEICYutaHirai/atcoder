//GAを用いてとく
//今回の問題で重要なのは、どの日にいつ課金するかのみ
//問題点　。。。　良い時と悪い時の大差が激しい。部分的に近傍探索をした方がよさそう

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <random>
#include <fstream>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef pair<int, int> Pii;

#define N_IND 1000
//P_KEEP は0.1くらいで良さそう
//KEEPしたものと同じ数だけ近傍探索もする
//近傍探索の手法→N_SEARCH回数randomに値を変更し、評価値が上がるならそれに遷移
#define P_KEEP 0.3
#define P_SEX 0.5
#define P_META 0.01
#define END_TIME 9500
//もし納期に遅れてるようなら課金してなんとかする。その確率
#define P_AC 0.
#define N_AC 1

system_clock::time_point pStart;

std::mt19937 mt{std::random_device{}()};
random_device seed_gen;
default_random_engine engine(seed_gen());
uniform_int_distribution<int> udist(0, N_IND - 1);
uniform_real_distribution<> rdist(0.0, 1.0);

class Order
{ /** オーダ **/
  public:
    int r;  /** オーダ番号    : Order number */
    int i;  /** 品目番号      : Item number */
    int e;  /** 最早開始時刻  : Earliest start time */
    int d;  /** 納期          : Deadline */
    int q;  /** 製造数量      : Manufacturing quanity */
    int pr; /** 粗利金額      : Gross profit */
    Order(int _r, int _i, int _e, int _d, int _q, int _pr)
    {
        r = _r;
        i = _i;
        e = _e;
        d = _d;
        q = _q;
        pr = _pr;
    }
};
class Bom
{ /** BOM **/
  public:
    int p = 0;         /** 工程数       : Process number */
    vector<int> times; /** 製造スピード : Manufacturing spead */
    vector<int> pTom;  /** 割り当て設備 : Process to Machine */
    Bom(int _P)
    {
        times.resize(_P);
        pTom.resize(_P);
    }
};
class Capacity
{ /** 能力増加 **/
  public:
    int m;  /** 設備番号             : Machine number */
    int d;  /** 日                   : day */
    int ac; /** 能力増加数           : Additional capacity */
    Capacity(int _m, int _d, int _ac)
    {
        m = _m;
        d = _d;
        ac = _ac;
    }
};
class Operation
{ /** 作業 **/
  public:
    int r;  /** オーダ番号         : Order number */
    int p;  /** 工程番号           : Process number */
    int m;  /** 設備番号           : Machine number */
    int t1; /** 製造開始時刻       : Manufacturing start time */
    int t2; /** 製造終了時刻       : Manufacturing end time */
    Operation(int _r, int _p, int _m, int _t1, int _t2)
    {
        r = _r;
        p = _p;
        m = _m;
        t1 = _t1;
        t2 = _t2;
    }
};
int M;  /** 設備数                   : Number of machines */
int I;  /** 品目数                   : Number of items */
int P;  /** 最大工程数               : Max number of processes*/
int R;  /** 注文数                   : Number of orders */
int BL; /** BOM行数                  : Number of BOM lines */
const int DEFAULT_CAPACITY = 8;
const int MAX_CAPACITY = 1000000;
const int SECONDS_A_DAY = 86400;
const int MAX_DAY = 1000;
vector<int> C; /** Cm 設備mの能力増加コスト : Machine cost multiplier */
vector<int> D; /** Dm 設備mの製造時間係数   : Machine manufacturing time multiplier */

vector<Order> orders;
vector<Operation> operations;
vector<Capacity> capacities;
vector<Bom> boms;
vector<vector<int>> mdToAc;
vector<pair<int, vector<vector<int>>>> mdToAcs, nMdToAcs;
vector<vector<Pii>> rpToTime;

double meanProfit = 0.0;

int maxDead;
int maxPr = 0;
vector<int> maxCost;
//各機械にランダムな値を割り当てる時に使うやつ
//vector<uniform_int_distribution<int>> mRandom;
vector<normal_distribution<>> mRandom;
//最大の過金額に対しての制限
const double acLimit = .01;

void readProblem()
{
    /* 問題を読み込み。 : Load the problem. */
    string _s;
    cin >> _s >> M >> I >> P >> R >> BL;
    cin >> _s;
    C.resize(M);
    for (int m = 0; m < M; ++m)
    {
        cin >> C[m];
    }
    cin >> _s;
    D.resize(M);
    for (int m = 0; m < M; ++m)
    {
        cin >> D[m];
    }
    boms.assign(I, Bom(P));
    for (int n = 0; n < BL; ++n)
    {
        int i, p, m, s;
        cin >> _s >> i >> p >> m >> s;
        Bom &bom = boms[i - 1];
        bom.p = max(bom.p, p);
        bom.times[p - 1] = s;
        bom.pTom[p - 1] = m - 1;
    }

    maxDead = 0;

    for (int n = 0; n < R; ++n)
    {
        int r, i, e, d, q, pr;
        cin >> _s >> r >> i >> e >> d >> q >> pr;
        maxDead = max(maxDead, d);
        maxPr += pr;
        orders.push_back(Order(r - 1, i - 1, (e - 1) * SECONDS_A_DAY, (d - 1) * SECONDS_A_DAY, q, pr));
    }
    mdToAc.assign(M, vector<int>(maxDead + 1, 0));
    //mdToAcs.assign(N_IND, pair(0, vector<vector<int>>(M, vector<int>(MAX_DAY + 1, 0))));
    mdToAcs.assign(N_IND, pair<int, vector<vector<int>>>(0, vector<vector<int>>(M, vector<int>(MAX_DAY + 1, 0))));
    nMdToAcs.assign(N_IND, pair<int, vector<vector<int>>>(0, vector<vector<int>>(M, vector<int>(MAX_DAY + 1, 0))));
    rpToTime.assign(R, vector<Pii>(P, Pii(0, 0)));
    maxCost.assign(M, 0);
    return;
}
void writeSolution()
{
    /* 結果を出力。: Output the results. */
    cout << capacities.size() << endl;
    for (Capacity capa : capacities)
    {
        cout << capa.m + 1 << '\t' << capa.d << '\t' << capa.ac << endl;
    }
    cout << operations.size() << endl;
    for (Operation ope : operations)
    {
        cout << ope.r + 1 << '\t' << ope.p + 1 << '\t' << ope.m + 1 << '\t' << ope.t1 << '\t' << ope.t2 << endl;
    }
    return;
}
void forwardAssign()
{
    /* 各設備の前回の製造終了時刻 : Previous manufacturing end time of each machine */
    vector<int> mToPreviousT2(M, 0);

    /* オーダ順に作業をフォワードで割り付ける。: Assign operations forward according to order code. */
    for (int r = 0; r < R; ++r)
    {
        int q = orders[r].q;
        int i = orders[r].i;
        Bom &bom = boms[i];
        int prevT2 = 0; /* 前工程の終了時間。: Ending time of the previous process. */
        for (int p = 0; p < bom.p; ++p)
        {
            int m = bom.pTom[p];
            int t1 = 0;
            if (p == 0)
            {
                t1 = max(mToPreviousT2[m], orders[r].e);
            }
            else
            {
                t1 = max(mToPreviousT2[m], prevT2);
            }
            /* 工程終了時間を計算。(小数第一位以下は切り上げ)。: Acquire the process ending time (round up to the nearest integer). */
            ll _t1 = t1;
            ll needResourceAmount = q * bom.times[p] * D[m];
            ll nDay = (_t1 + SECONDS_A_DAY) / SECONDS_A_DAY;
            ll ac = mdToAc[m][nDay];
            ll resourceAmountADay = (nDay * SECONDS_A_DAY - _t1) * (DEFAULT_CAPACITY + ac);
            while (needResourceAmount > resourceAmountADay)
            {
                needResourceAmount -= resourceAmountADay;
                ++nDay;
                _t1 = (nDay - 1) * SECONDS_A_DAY;
                ac = mdToAc[m][nDay];
                resourceAmountADay = SECONDS_A_DAY * (DEFAULT_CAPACITY + ac);
            }
            ll capa = DEFAULT_CAPACITY + ac;
            /* 下行では int t2 = _t1 + ceil((double)needResourceAmount / capa); を丸め誤差が生じないように計算している。*/
            /* In the next line, using "int t2 = _t1 + ceil((double)needResourceAmount / capa);" would cause small rounding error. */
            int t2 = _t1 + ((needResourceAmount + capa - 1) / capa);

            rpToTime[r][p] = Pii(t1, t2);

            /* 現在の設備状況の更新。: Update machine status. */
            mToPreviousT2[m] = t2;
            prevT2 = t2;
        }
    }
    return;
}
ll evaluation()
{
    ll grossP = 0;
    for (int r = 0; r < R; ++r)
    {
        int p = boms[orders[r].i].p - 1;
        if (rpToTime[r][p].second <= orders[r].d)
            grossP += orders[r].pr;
    }
    double cost = 0;
    for (int m = 0; m < M; ++m)
    {
        for (int d = 1; d <= maxDead; ++d)
        {
            if (mdToAc[m][d] != 0)
                cost += C[m] * pow(mdToAc[m][d], 1.1);
        }
    }
    ll v = ll(grossP - ceil(cost));
    return v;
}

void save()
{
    capacities.clear();
    operations.clear();
    for (int m = 0; m < M; ++m)
    {
        for (int d = 1; d <= maxDead; ++d)
        {
            if (mdToAc[m][d] != 0)
                capacities.push_back(Capacity(m, d, mdToAc[m][d]));
        }
    }
    for (int r = 0; r < R; ++r)
    {
        for (int p = 0; p < boms[orders[r].i].p; ++p)
        {
            operations.push_back(Operation(r, p, boms[orders[r].i].pTom[p], rpToTime[r][p].first, rpToTime[r][p].second));
        }
    }
}
void solve()
{
    /* ordersをオーダ番号でソートする。: Sort orders by order code. */
    sort(orders.begin(), orders.end(), [](const Order &o1, const Order &o2) { return o1.r < o2.r; });

    /* 各設備の1日目~10日目に能力を追加。: Adding capacities of each machine from day 1 to 10. */
    /*
    for (int m = 0; m < M; ++m)
    {
        for (int d = 1; d <= 10; ++d)
        {
            mdToAc[m][d] = 15;
        }
    }
    */
    forwardAssign();
    save();

    return;
}
void run()
{
    solve();
    writeSolution();
}

void initGAForAc()
{
    for (int x = 0; x < N_IND; x++)
    {
        for (int m = 0; m < M; ++m)
        {
            for (int d = 1; d <= maxDead; ++d)
            {
                //mdToAcs[x].second[m][d] = (int)abs(dist(engine));
                mdToAcs[x].second[m][d] = abs(mRandom[m](mt));
            }
        }
    }
}

//使われてないのに課金している日の課金を取り消し
void clean()
{
    vector<vector<bool>> is_open(M, vector<bool>(maxDead + 1, true));
    for (Operation ope : operations)
    {
        int day1 = (ope.t1 + SECONDS_A_DAY) / SECONDS_A_DAY;
        int day2 = (ope.t2 + SECONDS_A_DAY) / SECONDS_A_DAY;
        for (int x = day1; x <= day2; x++)
        {
            is_open[ope.m][x] = false;
        }
    }

    for (int x = 0; x < M; x++)
    {
        for (int y = 0; y < maxDead + 1; y++)
        {
            if (is_open[x][y])
            {
                mdToAc[x][y] = 0;
            }
        }
    }
    save();
}

void runGAForAc()
{
    initGAForAc();
    while (duration_cast<std::chrono::milliseconds>(system_clock::now() - pStart).count() < END_TIME)
    {
        for (int x = 0; x < N_IND; x++)
        {
            mdToAc = mdToAcs[x].second;
            solve();
            clean();
            mdToAcs[x].first = evaluation();
        }
        //評価値の高い順にソート
        sort(mdToAcs.begin(), mdToAcs.end(), greater<pair<int, vector<vector<int>>>>());

        int n_keep = N_IND * P_KEEP;
        int n_sex = N_IND * P_SEX;
        int n_meta = N_IND - n_keep - n_sex;

        for (int x = 0; x < n_keep; x++)
        {
            nMdToAcs[x] = mdToAcs[x];
        }

        //交叉
        for (int x = 0; x < n_sex; x++)
        {
            //int g1 = udist(engine);
            int g1 = udist(engine) % n_keep;
            int g2 = udist(engine) % n_keep;
            for (int m = 0; m < M; ++m)
            {
                for (int d = 1; d <= maxDead; ++d)
                {
                    if (udist(mt) % 2 == 0)
                        nMdToAcs[n_keep + x].second[m][d] = mdToAcs[g1].second[m][d];
                    else
                        nMdToAcs[n_keep + x].second[m][d] = mdToAcs[g2].second[m][d];
                }
            }
        }

        for (int x = 0; x < n_meta; x++)
        {
            for (int m = 0; m < M; ++m)
            {
                for (int d = 1; d <= maxDead; ++d)
                {
                    if (rdist(engine) < P_META)
                        nMdToAcs[n_keep + n_sex + x].second[m][d] = abs(mRandom[m](mt));
                    else
                        nMdToAcs[n_keep + n_sex + x].second[m][d] = mdToAcs[0].second[m][d];
                }
            }
        }

        /*
        for (int x = 0; x < n_meta; x++)
        {
            int g1 = udist(mt);
            mdToAc = mdToAcs[g1].second;
            delayMD.clear();
            solve();

            for (int y = 0; y < delayMD.size(); y++)
            {
                if (rdist(mt) < P_AC)
                {
                    mdToAcs[g1].second[delayMD[y].first][delayMD[y].second] += N_AC;
                }
            }
            nMdToAcs[n_keep + n_sex + x] = mdToAcs[g1];
            clean();
        }
        mdToAcs = nMdToAcs;
        */
    }
    for (int x = 0; x < N_IND; x++)
    {
        mdToAc = mdToAcs[x].second;
        solve();
        mdToAcs[x].first = evaluation();
    }
    sort(mdToAcs.begin(), mdToAcs.end(), greater<pair<int, vector<vector<int>>>>());
    mdToAc = mdToAcs[0].second;
    solve();
    clean();
    writeSolution();
}

int main()
{
    pStart = chrono::system_clock::now();

    readProblem();
    meanProfit = 0.0;

    //全ての機械にそれぞれの日に均等に課金すると考えた場合の最大値を設定しておく
    //もしかしたら多めに設定しておいた方がいいのかもしれない（現在はギリギリ）
    //ランダムネスは一様分布ではなく、正規分布の方がいい
    for (int m = 0; m < M; m++)
    {
        maxCost[m] = pow((double)maxPr, 1 / 1.1) * acLimit / (double)M / (double)C[m];
        mRandom.push_back(normal_distribution<>(0, (double)maxCost[m]));
    }

    runGAForAc();
    //cout << (int)abs((dist(engine) * 5) + 5) << endl;
    //cout << udist(mt) << endl;
    return 0;
}
