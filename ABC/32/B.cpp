#include <iostream>
#include <vector>

using namespace std;

#define swap(a, b) (a += b, b = a - b, a -= b)

class UnionFind
{
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}

    bool union_set(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (y < x)
                swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool find_set()
    {
        return root(x) == root(y);
    }

    int root(int x)
    {
        return data[x] < 0 ? x : root(data[x]);
    }

    int size(int x)
    {
        return -data[root(x)];
    }
};

bool is_paradox(UnionFind union_find)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(root(3*i+j) == root(3*i+((j+1)%3)){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n_anim, n_info;
    cin >> n_anim >> n_info;

    int ans = 0;
    UnionFind union_find(3 * N);

    for (int i = 0; i < n_info; i++)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if (!(1 <= x && x <= 100 && y <= 1 && y <= 100))
        {
            ans++;
        }
        else if (type == 2 && x == y)
        {
            ans++;
        }
        else
        {
            UnionFind temp = union_find;
            if (type == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    temp.union_set(3 * (x - 1) + i, 3 * (y - 1) + i);
                }
                if (!(is_paradox(temp)))
                {
                    union_find.union_set(3 * (x - 1) + i, 3 * (y - 1) + i);
                }
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    temp.union_set(3 * (x - 1) + i, 3 * (y - 1) + ((i + 1) % 3));
                }
                if (!(is_paradox(temp)))
                {
                    union_find.union_set(3 * (x - 1) + i, 3 * (y - 1) + ((i + 1) % 3));
                }
            }
        }
    }
}