//
// Created by Hleonor on 2022-10-30.
//
#include<iostream>
using namespace std;
int map[3010][3010];
int node[3010];
int n, m;
int sum = 0;

void findDiamond(int x)
{
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (map[x][i])
        {
            node[num++] = i; // 记录起点是x的终点
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (k != x && map[node[i]][k] && map[node[j]][k])
                {
                    sum++;
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    int point1, point2;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &point1, &point2);
        map[point1][point2] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        findDiamond(i);
    }
    printf("%d", sum);
    return 0;
}