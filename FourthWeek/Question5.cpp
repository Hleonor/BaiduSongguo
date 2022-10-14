#include<bits/stdc++.h>

using namespace std;

int main( )
{
    int n;
    int x,y;
    scanf("%d",&n);
    for (int i = 0;i < n; i++)
    {
        scanf("%d%d",&x,&y);
        if (y>x)
        {
            printf("0\n");
            continue;
        }
        if (y == x || y == 0)
        {
            printf("1\n");
            continue;
        }

        int a = y;
        int b = x-y;

        if (a & b)
        {
            printf("0\n");
            continue;
        }
        else
        {
            printf("1\n");
            continue;
        }
    }
    return 0;
}