//優先すべき関係式は何か
//コスパ　
//納期が早いもの優先
//slack 現在時刻

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
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef pair<int, int> Pii;

std::mt19937 mt{std::random_device{}()};
system_clock::time_point pStart;
std::uniform_real_distribution<> uniformDist(0.0, 1.0);

ll evaluation();
ll backwardReduce();
void forwardAssign();

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

int M;      /** 設備数                   : Number of machines */
int I;      /** 品目数                   : Number of items */
int P;      /** 最大工程数               : Max number of processes*/
int R;      /** 注文数                   : Number of orders */
int BL;     /** BOM行数                  : Number of BOM lines */
int MAX_Pr; //Profitの合計値
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
vector<vector<Pii>> rpToTime;

int maxDead;
vector<int> MAX_Cost; //各機械、各日に均等にコストをかけた時の最大のコスト

typedef vector<Pii> VR;
vector<vector<bool>> isImportantDays;
VR importantMd;
VR forwardImportantMd, backwardImportantMd;
int Nimportant;

const int timeLimit = 9500;

inline bool checkTime()
{
    return (duration_cast<std::chrono::milliseconds>(system_clock::now() - pStart).count() < timeLimit);
}

inline bool checkTime(float mul)
{
    return (duration_cast<std::chrono::milliseconds>(system_clock::now() - pStart).count() < timeLimit * mul);
}

inline int getTime()
{
    return duration_cast<std::chrono::milliseconds>(system_clock::now() - pStart).count();
}

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
    MAX_Pr = 0;
    maxDead = 0;
    for (int n = 0; n < R; ++n)
    {
        int r, i, e, d, q, pr;
        cin >> _s >> r >> i >> e >> d >> q >> pr;
        MAX_Pr += pr;
        maxDead = max(maxDead, d);
        orders.push_back(Order(r - 1, i - 1, (e - 1) * SECONDS_A_DAY, (d - 1) * SECONDS_A_DAY, q, pr));
    }

    mdToAc.assign(M, vector<int>(MAX_DAY + 1, 0));
    rpToTime.assign(R, vector<Pii>(P, Pii(0, 0)));
    /* ordersをオーダ番号でソートする。: Sort orders by order code. */
    std::sort(orders.begin(), orders.end(), [](const Order &o1, const Order &o2) { return o1.r < o2.r; });
    for (int m = 0; m < M; ++m)
    {
        MAX_Cost.push_back((log(double(MAX_Pr) / (double)maxDead / (double)M / (double)C[m] * 10.)) / (log(1.1)));
        MAX_Cost[m] = max(MAX_Cost[m], 3);
    }
    //コストで降順に並べ替え
    //std::sort(smallerC.begin(), smallerC.end());
    isImportantDays.assign(M, vector<bool>(maxDead + 1, false));
    for (int r = 0; r < R; ++r)
    {
        int i = orders[r].i;
        Bom &bom = boms[i];
        int eDay = orders[r].e / SECONDS_A_DAY + 1;
        int dDay = orders[r].d / SECONDS_A_DAY + 1;
        for (int p = 0; p < bom.p; ++p)
        {
            int m = bom.pTom[p];
            for (int d = eDay; d <= dDay; ++d)
            {
                isImportantDays[m][d] = true;
            }
        }
    }

    for (int m = 0; m < M; ++m)
    {
        for (int d = 1; d <= maxDead; ++d)
        {
            if (isImportantDays[m][d])
            {
                importantMd.push_back(Pii(m, d));
            }
        }
    }

    Nimportant = importantMd.size();
    sort(importantMd.begin(), importantMd.end());
    forwardImportantMd = importantMd;
    sort(importantMd.begin(), importantMd.end(), greater<Pii>());
    backwardImportantMd = importantMd;
    return;
}

inline int getDay(int t)
{
    return (t + SECONDS_A_DAY) / SECONDS_A_DAY;
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

void inline forwardAssign()
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
            /* 下行では int t2 = _t1 + ceil((float)needResourceAmount / capa); を丸め誤差が生じないように計算している。*/
            /* In the next line, using "int t2 = _t1 + ceil((float)needResourceAmount / capa);" would cause small rounding error. */
            int t2 = _t1 + ((needResourceAmount + capa - 1) / capa);

            rpToTime[r][p] = Pii(t1, t2);

            /* 現在の設備状況の更新。: Update machine status. */
            mToPreviousT2[m] = t2;
            prevT2 = t2;
        }
    }
    return;
}

inline ll evaluation()
{
    ll grossP = 0;
    for (int r = 0; r < R; ++r)
    {
        int p = boms[orders[r].i].p - 1;
        if (rpToTime[r][p].second <= orders[r].d)
            grossP += orders[r].pr;
    }
    double cost = 0;
    int m, d;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = importantMd[i].first;
        d = importantMd[i].second;
        if (mdToAc[m][d] != 0)
            cost += C[m] * pow(mdToAc[m][d], 1.1);
    }
    ll v = ll(grossP - ceil(cost));
    return v;
}

inline double conEvaluation()
{
    double grossP = 0;
    for (int r = 0; r < R; ++r)
    {
        int p = boms[orders[r].i].p - 1;
        if (rpToTime[r][p].second <= orders[r].d)
            grossP += orders[r].pr;
        else
            grossP -= (double)(rpToTime[r][p].second - orders[r].d) * orders[r].pr / SECONDS_A_DAY /10.;
        //grossP -= (double)orders[r].pr * exp((double)(-rpToTime[r][p].second + orders[r].d) * 10. / SECONDS_A_DAY);
    }
    double cost = 0;
    int m, d;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = importantMd[i].first;
        d = importantMd[i].second;
        if (mdToAc[m][d] != 0)
            cost += C[m] * pow(mdToAc[m][d], 1.1);
    }
    return (grossP - cost);
}

void save()
{
    capacities.clear();
    operations.clear();
    int m, d;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = importantMd[i].first;
        d = importantMd[i].second;
        if (mdToAc[m][d] != 0)
            capacities.push_back(Capacity(m, d, mdToAc[m][d]));
    }

    for (int r = 0; r < R; ++r)
    {
        for (int p = 0; p < boms[orders[r].i].p; ++p)
        {
            operations.push_back(Operation(r, p, boms[orders[r].i].pTom[p], rpToTime[r][p].first, rpToTime[r][p].second));
        }
    }
}

inline void setCostCl(float cl)
{
    int m, d;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = importantMd[i].first;
        d = importantMd[i].second;
        mdToAc[m][d] = MAX_Cost[m] * cl;
    }
}

inline ll accurateBackwardReduce()
{
    ll tmpEvaluation = evaluation();
    int d, m, prevAc;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = backwardImportantMd[i].first;
        d = backwardImportantMd[i].second;
        if (mdToAc[m][d] == 0)
        {
            continue;
        }
        //mdToAc[m][d]--;
        //割り算の方が高速かつ効率的
        prevAc = mdToAc[m][d];
        --mdToAc[m][d];
        forwardAssign();
        ll tmptmpEvaluation = evaluation();
        //cout << tmptmpEvaluation << endl;
        if (tmpEvaluation < tmptmpEvaluation)
        {
            tmpEvaluation = tmptmpEvaluation;
            //もう一度ループ
            i--;
        }
        else
        {
            //元に戻す
            mdToAc[m][d] = prevAc;
        }
    }

    forwardAssign();
    return evaluation();
}

//コストの高いMachineから順に、後ろの日からコストを引いていく
//もし前側から割り付けていくとしたら、前の方の日付から,コストの低い方から順に割り当てていく.なので、それと逆のことをすれば良い
//M * maxDead / 10 ms くらいの時間がかかる
//practice05 の場合、約60msくらい
//コストが増えるほど、減らすのが大変になる
inline ll backwardReduce()
{
    double tmpEvaluation = evaluation();
    int d, m, prevAc;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = backwardImportantMd[i].first;
        d = backwardImportantMd[i].second;
        if (mdToAc[m][d] == 0)
        {
            continue;
        }
        prevAc = mdToAc[m][d];
        mdToAc[m][d] /= 3.;
        forwardAssign();
        ll tmptmpEvaluation = evaluation();
        //cout << tmptmpEvaluation << endl;
        if (tmpEvaluation < tmptmpEvaluation)
        {
            tmpEvaluation = tmptmpEvaluation;
            i--;
        }
        else
        {
            mdToAc[m][d] = prevAc;
        }
    }

    forwardAssign();
    return evaluation();
}

double cRandomForwardReduce();

inline double cBackwardReduce()
{
    double tmpEvaluation = conEvaluation();
    int d, m, prevAc;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = backwardImportantMd[i].first;
        d = backwardImportantMd[i].second;
        if (mdToAc[m][d] == 0)
        {
            continue;
        }
        prevAc = mdToAc[m][d];
        mdToAc[m][d] /= 3.;
        forwardAssign();
        ll tmptmpEvaluation = conEvaluation();
        //cout << tmptmpEvaluation << endl;
        if (tmpEvaluation < tmptmpEvaluation)
        {
            tmpEvaluation = tmptmpEvaluation;
            i--;
        }
        else
        {
            mdToAc[m][d] = prevAc;
        }
    }

    forwardAssign();
    return tmpEvaluation;
}

inline ll forwardReduce()
{
    ll tmpEvaluation = evaluation();
    int prevAc, m, d;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = forwardImportantMd[i].first;
        d = forwardImportantMd[i].second;
        if (mdToAc[m][d] == 0)
        {
            continue;
        }
        //mdToAc[m][d]--;
        //割り算の方が高速かつ効率的
        prevAc = mdToAc[m][d];
        mdToAc[m][d] /= 3.;
        forwardAssign();
        ll tmptmpEvaluation = evaluation();
        //cout << tmptmpEvaluation << endl;
        if (tmpEvaluation < tmptmpEvaluation)
        {
            tmpEvaluation = tmptmpEvaluation;
            i--;
        }
        else
        {
            //元に戻す
            mdToAc[m][d] = prevAc;
        }
    }

    forwardAssign();
    return evaluation();
}

inline double cForwardReduce()
{
    //return cRandomForwardReduce();
    double tmpEvaluation = conEvaluation();
    int prevAc, m, d;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = forwardImportantMd[i].first;
        d = forwardImportantMd[i].second;
        if (mdToAc[m][d] == 0)
        {
            continue;
        }
        //mdToAc[m][d]--;
        //割り算の方が高速かつ効率的
        prevAc = mdToAc[m][d];
        mdToAc[m][d] /= 3.;
        forwardAssign();
        double tmptmpEvaluation = conEvaluation();
        //cout << tmptmpEvaluation << endl;
        if (tmpEvaluation < tmptmpEvaluation)
        {
            tmpEvaluation = tmptmpEvaluation;
            i--;
        }
        else
        {
            //元に戻す
            mdToAc[m][d] = prevAc;
        }
    }

    forwardAssign();
    return tmpEvaluation;
}

inline ll randomForwardReduce()
{
    ll tmpEvaluation = evaluation();
    shuffle(importantMd.begin(), importantMd.end(), mt);
    int d, m, prevAc;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = importantMd[i].first;
        d = importantMd[i].second;
        if (mdToAc[m][d] == 0)
        {
            continue;
        }
        //mdToAc[m][d]--;
        //割り算の方が高速かつ効率的
        prevAc = mdToAc[m][d];
        mdToAc[m][d] /= 3.;
        forwardAssign();
        ll tmptmpEvaluation = evaluation();
        //cout << tmptmpEvaluation << endl;
        if (tmpEvaluation < tmptmpEvaluation)
        {
            tmpEvaluation = tmptmpEvaluation;
            i--;
        }
        else
        {
            //元に戻す
            mdToAc[m][d] = prevAc;
        }
    }

    forwardAssign();
    return evaluation();
}

inline double cRandomForwardReduce()
{
    double tmpEvaluation = conEvaluation();
    shuffle(importantMd.begin(), importantMd.end(), mt);
    int d, m, prevAc;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = importantMd[i].first;
        d = importantMd[i].second;
        if (mdToAc[m][d] == 0)
        {
            continue;
        }
        //mdToAc[m][d]--;
        //割り算の方が高速かつ効率的
        prevAc = mdToAc[m][d];
        mdToAc[m][d] /= 3.;
        forwardAssign();
        double tmptmpEvaluation = conEvaluation();
        //cout << tmptmpEvaluation << endl;
        if (tmpEvaluation < tmptmpEvaluation)
        {
            tmpEvaluation = tmptmpEvaluation;
            i--;
        }
        else
        {
            //元に戻す
            mdToAc[m][d] = prevAc;
        }
    }

    forwardAssign();
    return tmpEvaluation;
}

inline ll forwardAdd()
{
    shuffle(importantMd.begin(), importantMd.end(), mt);
    ll tmpEvaluation = evaluation();
    int d, m, prevAc;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = importantMd[i].first;
        d = importantMd[i].second;
        prevAc = mdToAc[m][d];
        mdToAc[m][d] += MAX_Cost[m] * uniformDist(mt);
        forwardAssign();
        ll tmptmpEvaluation = evaluation();
        //cout << tmptmpEvaluation << endl;
        if (tmpEvaluation < tmptmpEvaluation)
        {
            tmpEvaluation = tmptmpEvaluation;
            i--;
        }
        else
        {
            //元に戻す
            mdToAc[m][d] = prevAc;
        }
    }

    forwardAssign();
    return evaluation();
}

inline double cForwardAdd()
{
    shuffle(importantMd.begin(), importantMd.end(), mt);
    double tmpEvaluation = conEvaluation();
    int d, m, prevAc;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = importantMd[i].first;
        d = importantMd[i].second;
        prevAc = mdToAc[m][d];
        mdToAc[m][d] += MAX_Cost[m] * uniformDist(mt) *0.5;
        forwardAssign();
        double tmptmpEvaluation = conEvaluation();
        //cout << tmptmpEvaluation << endl;
        if (tmpEvaluation < tmptmpEvaluation)
        {
            tmpEvaluation = tmptmpEvaluation;
            i--;
        }
        else
        {
            //元に戻す
            mdToAc[m][d] = prevAc;
        }
    }

    forwardAssign();
    return tmpEvaluation;
}

inline double ccForwardAdd()
{
    shuffle(importantMd.begin(), importantMd.end(), mt);
    double tmpEvaluation = conEvaluation();
    int d, m, prevAc;
    for (int i = 0; i < Nimportant; ++i)
    {
        m = importantMd[i].first;
        d = importantMd[i].second;
        prevAc = mdToAc[m][d];
        mdToAc[m][d] += MAX_Cost[m];
        forwardAssign();
        double tmptmpEvaluation = conEvaluation();
        //cout << tmptmpEvaluation << endl;
        if (tmpEvaluation < tmptmpEvaluation)
        {
            tmpEvaluation = tmptmpEvaluation;
            i--;
        }
        else
        {
            //元に戻す
            mdToAc[m][d] = prevAc;
        }
    }

    forwardAssign();
    return tmpEvaluation;
}

ll best;
vector<vector<int>> bestMd;

void changeBest()
{
    ll tmp = evaluation();
    if (best < tmp)
    {
        best = evaluation();
        bestMd = mdToAc;
    }
    return;
}

inline ll forwardAddDuration()
{
    shuffle(importantMd.begin(), importantMd.end(), mt);
    int d, m;
    double start = uniformDist(mt);
    double end = uniformDist(mt);
    if (start > end)
    {
        double tmp = end;
        end = start;
        start = tmp;
    }
    for (int i = start * Nimportant; i < Nimportant * end; ++i)
    {
        m = forwardImportantMd[i].first;
        d = forwardImportantMd[i].second;
        if (mdToAc[m][d] == 0)
        {
            m = importantMd[i].first;
            d = importantMd[i].second;
            continue;
        }
        mdToAc[m][d] += MAX_Cost[m] * uniformDist(mt);
    }

    forwardAssign();
    return evaluation();
}

unsigned int randxor()
{
    static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned int t;
    t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int main()
{
    pStart = system_clock::now();

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    readProblem();

    vector<pair<double, vector<vector<int>>>> rpToTimes;
    int population = 15;
    uniform_int_distribution<> crossover(0, 1);

    forwardAssign();
    best = evaluation();
    bestMd = mdToAc;
    int nSubLoop = 1;

    while (checkTime(0.2))
    {
        for (int k = 0; k < population; ++k)
        {
            setCostCl(uniformDist(mt));
            forwardAssign();
            if (crossover(mt))
            {
                //cBackwardReduce();
                //cBackwardReduce();
                for (int i = 0; i < 3; ++i)
                {
                    cRandomForwardReduce();
                    cForwardAdd();
                }
            }
            else
            {

                //cForwardReduce();
                //cForwardReduce();
                for (int i = 0; i < 3; ++i)
                {
                    cRandomForwardReduce();
                    cForwardAdd();
                }
            }

            rpToTimes.push_back(pair<ll, vector<vector<int>>>(cRandomForwardReduce(), mdToAc));
            changeBest();
        }
        sort(rpToTimes.begin(), rpToTimes.end(), greater<pair<double, vector<vector<int>>>>());
        rpToTimes.erase(rpToTimes.begin() + population, rpToTimes.end());
    }
    std::sort(rpToTimes.begin(), rpToTimes.end(), greater<pair<double, vector<vector<int>>>>());
    int nSurvive = max((int)(population * 0.4), 2); //N*pSurvive
    int nMate = population * 0.2;                   //N*pMate

    vector<int> vShuffle(population), vShuffleElete(nSurvive);
    for (int i = 0; i < population; ++i)
    {
        vShuffle[i] = i;
    }
    for (int i = 0; i < nSurvive; ++i)
    {
        vShuffleElete[i] = i;
    }

    int currentTime = getTime();
    int nloop = 10;
    while (currentTime < timeLimit)
    {
        if (currentTime > 8000)
        {
            nloop = 1;
        }

        
            for (int i = 0; i < nSurvive; ++i)
            {
                mdToAc = rpToTimes[i].second;
                forwardAssign();
                  for (int t = 0; t < nSubLoop; ++t)
            {
                cForwardAdd();
                rpToTimes[i].first = cRandomForwardReduce();
            }
                
                changeBest();

                rpToTimes[i].second = mdToAc;
            }
 
        //mutation
        //double dpm = rpToTimes[0].first > MAX_Pr / 5. ? 0.2 : .5;

        float pMutationPosition = 0.3 * currentTime / timeLimit * (MAX_Pr / best);
        //float pMutationPosition = 0.3;
        int nMutationPosition = min(max((int)(Nimportant * pMutationPosition), 5), population);
        for (int i = nSurvive + nMate; i < population; ++i)
        {
            shuffle(vShuffle.begin(), vShuffle.end(), mt);
            rpToTimes[i] = rpToTimes[vShuffle[i]];
            int m, d;
            shuffle(importantMd.begin(), importantMd.end(), mt);
            for (int j = 0; j < nMutationPosition; j++)
            {
                m = importantMd[j].first;
                d = importantMd[j].second;
                rpToTimes[i].second[m][d] += max(MAX_Cost[m] * uniformDist(mt), 5.);
            }
            mdToAc = rpToTimes[i].second;
            forwardAssign();
            /*
            if (crossover(mt))
            {
                //backwardReduce();
                //cBackwardReduce();
                
            }
            else
            {
                for (int t = 0; t < nSubLoop; ++t)
                {
                    cForwardAdd();
                    cRandomForwardReduce();
                }
                //forwardReduce();
                //cForwardReduce();
            }
            */
            for (int t = 0; t < nSubLoop; ++t)
            {
                cForwardAdd();
                rpToTimes[i].first = cRandomForwardReduce();
            }

            rpToTimes[i].second = mdToAc;
        }

        //mate

        for (int i = nSurvive; i < nSurvive + nMate; ++i)
        {
            shuffle(vShuffle.begin(), vShuffle.end(), mt);
            int x = 0;
            int y = 1;

            int m, d;
            for (int j = 0; j < Nimportant; ++j)
            {
                m = importantMd[j].first;
                d = importantMd[j].second;
                if (randxor() % 2)
                {
                    rpToTimes[i].second[m][d] = rpToTimes[x].second[m][d];
                }
                else
                {
                    rpToTimes[i].second[m][d] = rpToTimes[y].second[m][d];
                }
            }

            mdToAc = rpToTimes[i].second;
            forwardAssign();
            /*
            if (crossover(mt))
            {
                //backwardReduce();
                cBackwardReduce();
            }
            else
            {
                //forwardReduce();
                cForwardReduce();
            }*/
            for (int t = 0; t < nSubLoop; ++t)
            {
                cForwardAdd();
                rpToTimes[i].first = cRandomForwardReduce();
            }
            rpToTimes[i].second = mdToAc;
        }
        sort(rpToTimes.begin(), rpToTimes.end(), greater<pair<double, vector<vector<int>>>>());

        currentTime = getTime();
        //cout << rpToTimes[0].first << endl;
    }
    mdToAc = bestMd;
    forwardAssign();
    accurateBackwardReduce();
    save();
    //cout << MAX_Pr << endl;
    //cout << evaluation() << endl;
    writeSolution();
    return 0;
}