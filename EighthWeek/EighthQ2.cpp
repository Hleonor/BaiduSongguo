//
// Created by Hleonor on 2022-11-03.
//
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
LL n;
bool mk[100010];
int p[100010], len;
LL read() // 读入函数
{
    LL x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
LL LLabs(LL a)
{
    return a < 0 ? -a : a;
}
void getp()
{
    for (int i = 2; i <= 100000; i++)
    {
        if (!mk[i])
        {
            p[++len] = i;
            for (int j = 2 * i; j <= 100000; j += i)
            {
                mk[j] = 1;
            }
        }
    }
}
void work()
{
    int flag = (n < 0), ans = 0;
    n = LLabs(n);
    for (int i = 1; i <= len; i++)
    {
        if ((LL)p[i] * p[i] > n)
        {
            break;
        }
        if (n % p[i] != 0)
        {
            continue;
        }
        int now = 0;
        while (n % p[i] == 0)
        {
            n /= p[i], now++;
        }
        if (!ans)
        {
            ans = now;
        }
        else
        {
            ans = __gcd(ans, now);
        }
    }
    if (n != 1)
    {
        ans = 1;
    }

    if (flag)
    {
        while (ans % 2 == 0)
        {
            ans /= 2;
        }
    }
    cout << ans << endl;
}
int main()
{
    getp();
    scanf("%lld", &n);
    work();
}