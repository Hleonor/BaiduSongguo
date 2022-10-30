//
// Created by Hleonor on 2022-10-30.
//
#include<iostream>
using namespace std;

int n, m;
int map[3010][3010] = {0};
int sumOfDimond = 0;

void findDimond(int x)
{
    int num = 0;
    int node[3010];
    for (int i = 1; i <= n; i++)
    {
        if (map[x][i])
        {
            node[num] = i; // 记录节点x能到的点
            num++;
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
             for (int k = 1; k <= n; k++)
             {
                 if (map[node[i]][k] && map[node[j]][k] && k != x) // k != x保证不回头
                 {
                     sumOfDimond++;
                 }
             }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    int v1, v2;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &v1, &v2);
        map[v1][v2] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        findDimond(i);
    }
    printf("%d", sumOfDimond);

    return 0;
}