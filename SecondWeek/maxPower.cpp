#include <iostream>
using namespace std;

int score;
int maxPower;
int P[30][30];
int Q[30][30];
int PQ[30][30];
int prev_[30];
int book[30];

void my_dfs(int n , int i)
{
    if (i > n)
    {
        maxPower = max(maxPower , score);
        return;
    }

    if (score + prev_[n] - prev_[i - 1] < maxPower)
    {
        return;
    }

    for (int j = 1; j <= n; j++)
    {
        if (book[j])
        {
            continue;
        }
        book[j] = 1;
        score += PQ[i][j];
        my_dfs(n , i + 1);

        book[j] = 0;
        score -= PQ[i][j];
    }
}
int main()
{
    int n;
    scanf("%d" , &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d" , &P[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d" , &Q[i][j]);
            PQ[j][i] = Q[i][j] * P[j][i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            prev_[i] = max(prev_[i] , PQ[i][j]);
        }
        prev_[i] += prev_[i - 1];
    }

    my_dfs(n , 1);
    printf("%d" , maxPower);
    return 0;
}