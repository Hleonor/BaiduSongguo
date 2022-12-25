//
// Created by Hleonor on 2022-11-20.
//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> edges[210];
    int cost[210];
    int n,a,b;
    int i, folds;
    scanf("%d %d %d", &n, &a, &b);
    for(i = 1; i <= n; i++)
    {
        // cin>>folds;
        scanf("%d", &folds);
        if(i + folds <= n)
        {
            edges[i].push_back(i+folds);
        }
        if(i - folds >= 1)
        {
            edges[i].push_back(i-folds);
        }
    }
    for(i = 1; i <= n; i++)
    {
        cost[i] =- 1;
    }
    queue<int> Q;
    cost[a]=0;
    Q.push(a);
    int u,j,k;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(j = 0; j < edges[u].size(); j++)
        {
            k = edges[u][j];
            if(cost[k] == -1)
            {
                Q.push(k);
                cost[k] = cost[u] + 1;
            }
        }
    }
    printf("%d", cost[b]);
    return 0;
}


