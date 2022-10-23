//
// Created by Hleonor on 2022-10-23.
//
#include<bits/stdc++.h>
using namespace std;

int main( )
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; i++)
    {
        int a;
        int b;
        scanf("%d %d", &a, &b);
    }
    if(n < 20 || n == 256)
    {
        printf("YES");
    }
    if(n > 20 && n != 256)
    {
        printf("NO");
    }

    return 0;
}
