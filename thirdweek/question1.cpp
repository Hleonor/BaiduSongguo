//
// Created by Hleonor on 2022-09-25.
//

#include<iostream>
using namespace std;
int _point_[110];
int _map_[110][110];

#define INT_MAX 2147483647
int main()
{
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <=n; i++)
    {
        cin >> _point_[i];
    }
    int start , end;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        _map_[start][end] = 1;
        _map_[end][start] = 1;
    }
    int max = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (_map_[i][j] == 1 && j!=i)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (_map_[j][k] == 1 && k != i && k != j)
                    {
                        if (_map_[k][i] == 1)
                        {
                            if (_point_[i] + _point_[j] + _point_[k] < max)
                            {
                                max = _point_[i] + _point_[j] + _point_[k];
                            }
                        }
                    }
                }
            }
        }
    }
    if (max == INT_MAX)
    {
        printf("-1");
    }
    else
    {
        printf("%d", max);
    }
    return 0;
}