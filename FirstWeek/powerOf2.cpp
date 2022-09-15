#include <iostream>
using namespace std;

int arr[51] = {0};
int main()
{
    // clock_t start = clock();
    arr[1] = 2;
    int N;
    scanf("%d" , &N);
    int middleVar = 0;
    int maxBitCnt = 50;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= 50; j++)
        {
            middleVar = arr[j] * 2 + middleVar;
            arr[j] = middleVar % 10;
            middleVar = middleVar / 10;
        }
        middleVar = 0;
    }

    for (int i = 49; i >= 1; i--)
    {
        if(arr[i] != 0)
        {
            maxBitCnt = i;
            break;
        }
    }
    for (int i = maxBitCnt; i >= 1; i--)
    {
        printf("%d" , arr[i]);
    }


    /*clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);*/
    return 0;
}
