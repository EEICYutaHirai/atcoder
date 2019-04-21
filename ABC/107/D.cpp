#include <iostream>
#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

//よくわからん

int main()
{
    int N;
    cin >> N;
    int data[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
    }

    sort(data, data + N);

    int med_arr[N * (N - 1) / 2];
    int index = 0;
    //i は何個で区切るかを表す
    for (int i = 1; i <= N; i++)
    {
        //jはどのindexを最初の要素とするかを表す。
        for (int j = 0; j < N - i; j++)
        {
            med_arr[index] = data[j + (i / 2)];

            index++;
        }
    }

    cout << index << endl;

    sort(med_arr, med_arr + index);
    cout << med_arr[N * (N - 1) / 4] << endl;
}