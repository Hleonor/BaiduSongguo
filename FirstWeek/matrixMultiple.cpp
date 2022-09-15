#include<bits/stdc++.h>

using namespace std;

int mat1[1001][1001] = {0};
int mat2[1001][1001] = {0};
int ret[1001][1001] = {0};

int main( )
{
    int l , m , n;
    scanf("%d%d%d" , &l , &m , &n);
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d" , &mat1[i][j]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d" , &mat2[i][j]);
        }
    }

    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                ret[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }


    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // scanf("%d" , &mat1[i][j]);
            printf("%d " , ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}