//
// Created by Hleonor on 2022-10-30.
//
#include<bits/stdc++.h>
using namespace std;
#define N 10010

int h[N], ne[N], e[N], idx, vis[N], reg[N];

void add(int x, int y)
{
    e[++idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
}

int dfs(int x)
{
    vis[x] = 1;
    priority_queue<int> q;
    for (int i = h[x]; i; i = ne[i])
    {
        int y = e[i];
        if (!vis[y])
        {
            q.push(dfs(y));
        }
    }
    int ans = 0;
    int i = 0;
    while (!q.empty())
    {
        ans = max(ans, q.top() + (++i));
        q.pop();
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        add(x, i), add(i, x);
    }
    int MIN = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        reg[i] = dfs(i);
        MIN = min(MIN, reg[i]);
    }
    printf("%d\n", MIN + 1);
    for (int i = 1; i <= n; i++)
    {
        if (reg[i] == MIN)
        {
            printf("%d ", i);
        }
    }
}
