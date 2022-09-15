#include <iostream>
using namespace std;

int arr[10001] = {0};
int main()
{
    // clock_t start = clock();
    arr[1] = 1;
    int N , a;
    scanf("%d%d" , &N , &a);
    int middleVar = 0;
    int maxBitCnt = 10000;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= 10000; j++)
        {
            middleVar = arr[j] * i + middleVar;
            arr[j] = middleVar % 10;
            middleVar = middleVar / 10;
        }
        middleVar = 0;
    }

    for (int i = 10000; i >= 1; i--)
    {
        if(arr[i] != 0)
        {
            maxBitCnt = i;
            break;
        }
    }

    int cnt = 0;
    for (int i = maxBitCnt; i >= 1; i--)
    {
        // printf("%d" , arr[i]);
        if (a == arr[i])
        {
            cnt++;
        }
    }
    printf("%d" , cnt);
    return 0;
}
