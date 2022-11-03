//
// Created by Hleonor on 2022-11-03.
//
#include<bits/stdc++.h>
using namespace std;

int main( )
{
    long long n, m;
    scanf("%lld %lld", &n, &m);
    long long drop = 0;
    for (long long i = 1;i <= m; i++)
    {
        long long this_drop = n / 3;
        if (this_drop == 0)
        {
            break;
        }
        drop += this_drop;
        n -= this_drop;
    }
    printf("%lld", drop);
    return 0;
}