#include<bits/stdc++.h>

using namespace std;

long long minus_[100001];
int cmp(const void* _a, const void* _b) // 升序排列
{
    long long* a = (long long*)_a;    //强制类型转换
    long long* b = (long long*)_b;
    return *a - *b;
}

int main( )
{
    int N;
    scanf("%d" , &N);
    long long number = 1;
    long long positive_result = 1; // 正数乘积结果
    long long minus_result = 1; // 负数乘积结果
    int minus_cnt = 0; // 负数个数
    int positive_cnt = 0; // 正数个数
    for(int i = 1; i <= N; i++)
    {
        scanf("%lld" , &number);
        number %= 998244353;
        if (number > 0) // 正数直接乘到结果里
        {
            positive_cnt++;
            positive_result *= number;
            positive_result %= 998244353;
        }
        else if (number < 0) // 负数则加入到数组里，后续做处理
        {
            minus_cnt++;
            minus_[minus_cnt] = number;
        }
    }

    if (positive_cnt == 0 && minus_cnt == 0) // 如果正数负数个数都为0，说明输入全是0
    {
        printf("0");
        exit(0);
    }

    if (minus_cnt) // 如果负数个数不为0
    {
        if (N == 1) // 如果负数不为0个，并且输入只有一个，则结果就是输入的那个负数
        {
            printf("%lld" , minus_[1]);
            exit(0);
        }
        if (positive_cnt == 0 && minus_cnt == 1)
        {
            printf("0");
            exit(0);
        }
        qsort(&minus_[1] , minus_cnt , sizeof(long long) , cmp);
        if (minus_cnt % 2) // 如果是奇数个负数
        {
            for (int i = 1; i <= minus_cnt - 1; i++)
            {
                minus_result *= minus_[i];
                minus_result %= 998244353;
            }
        }
        else // 如果是偶数个负数
        {
            for (int i = 1; i <= minus_cnt; i++)
            {
                minus_result *= minus_[i];
                minus_result %= 998244353;
            }
        }
    }

    printf("%lld" , positive_result * minus_result % 998244353);
    return 0;
}