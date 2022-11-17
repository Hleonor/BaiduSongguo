//
// Created by Hleonor on 2022-11-10.
//
#include<bits/stdc++.h>
using namespace std;
int n, m;
int takeout[1010];

int main( )
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &takeout[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // 降序排列
        sort(takeout + 1, takeout + m + 1, greater<int>());
        ans += takeout[1];
        takeout[1]--;
    }
    printf("%d", ans);
    return 0;
}