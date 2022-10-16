//
// Created by Hleonor on 2022-10-15.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef pair <double, double> PDD;
int used[N], stk[N];
PDD q[N];
int n;

double get_dist (PDD a, PDD b) // 求距离
{
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt (dx * dx + dy * dy);
}
PDD operator - (PDD a, PDD b) // 向量减法
{
    return {a.first - b.first, a.second - b.second};
}
double cross (PDD a, PDD b) // 向量叉积
{
    return a.first * b.second - a.second * b.first;
}

double area (PDD a, PDD b, PDD c) // 两个向量叉积
{
    return cross (b - a, c - a);
}
double andrew ()
{
    sort (q, q + n); // 按照极角排序
    int top = 0;
    for (int i = 0; i < n; i ++)
    {
        while (top >= 2 && area (q[stk[top - 1]], q[stk[top]], q[i]) <= 0)
        {
            if (area(q[stk[top - 1]], q[stk[top]], q[i]) < 0)
            {
                used[stk[top --]] = false;
            }
            else
            {
                top --;
            }
        }
        stk[++ top] = i;
        used[i] = true;
    }
    used[0] = false;
    for (int i = n - 1; i >= 0; i --)
    {
        if (used[i])
        {
            continue;
        }
        while (top >= 2 && area(q[stk[top - 1]], q[stk[top]], q[i]) <= 0)
        {
            top -- ;
        }
        stk[ ++ top] = i;
    }
    double res = 0;
    for (int i = 2; i <= top; i ++)
    {
        res += get_dist (q[stk[i - 1]], q[stk[i]]);
    }
    return res;
}

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> q[i].first >> q[i].second;
    }

    double res = andrew ();
    printf ("%.2lf", res);
    return 0;

}
