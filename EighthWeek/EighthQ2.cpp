//
// Created by Hleonor on 2022-11-03.
//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    if (n == 1 || n == 2)
    {
        printf("1");
        exit(0);
    }
    if (n > 0)
    {
        for (long long a = 2; a * a <= n; a++) // 至少保证了2次方
        {
            for (long long b = 2; pow(a, b) <= n; b++) // 在保证了2次方的基础上往上加
            {
                if (pow(a, b) == n) // 第一个找到的就是底数最小的，对应指数最大，直接输出指数
                {
                    printf("%lld", b);
                    exit(0);
                }
            }
        }
    }
    else
    {
        for (long long a = -2; a * a >= n; a--) // 至少保证了2次方
        {
            for (long long b = 2; pow(a, b) >= n; b++) // 在保证了2次方的基础上往上加
            {
                if (pow(a, b) == n) // 第一个找到的就是底数最小的，对应指数最大，直接输出指数
                {
                    printf("%lld", b);
                    exit(0);
                }
            }
        }
    }

    return 0;
}