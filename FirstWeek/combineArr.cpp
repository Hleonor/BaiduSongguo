#include<bits/stdc++.h>
using namespace std;

int arr[99999999];
int arr2[99999999];
int cmp1(const void* _a, const void* _b)
{
    int* a = (int*)_a;    //强制类型转换
    int* b = (int*)_b;
    return *a - *b;
}

int cmp2(const void* _a, const void* _b)
{
    int* a = (int*)_a;    //强制类型转换
    int* b = (int*)_b;
    return *b - *a;
}

int main( )
{
    long long size;
    scanf("%lld" , &size);
    for (long long i = 1; i <= size; i++)
    {
        scanf("%d" , &arr[i]);
    }
    if (size % 2) // 奇数
    {
        long long middle = (1 + size) / 2;
        int book = arr[middle];
        qsort(&arr[1] , middle - 1 , sizeof(int) , cmp1);
        qsort(&arr[middle + 1] , middle - 1 , sizeof(int) , cmp2);
        long long former = 1;
        long long latter = middle + 1;
        for (long long i = 1; i <= size; i++)
        {
            if (i % 2)
            {
                arr2[i] = arr[former];
                former++;
            }
            else
            {
                arr2[i] = arr[latter];
                latter++;
            }
        }
        arr2[size] = book;
    }
    else // 偶数
    {
        qsort(&arr[1] , size/2 , sizeof(int) , cmp1);
        qsort(&arr[size / 2] , size / 2 , sizeof(int) , cmp2);
        long long former = 1;
        long long latter = size / 2 + 1;
        for (long long i = 1; i <= size; i++)
        {
            if (i % 2)
            {
                arr2[i] = arr[former];
                former++;
            }
            else
            {
                arr2[i] = arr[latter];
                latter++;
            }
        }
    }

    for (long long i = 1; i <= size; i++)
    {
        printf("%d " , arr2[i]);
    }

    return 0;
}