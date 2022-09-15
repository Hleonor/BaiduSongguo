#include<bits/stdc++.h>

using namespace std;

int pawn[999999];
int dp[999999];

int main( )
{
    int n;
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d" , &pawn[i]);
    }

    dp[1] = 0;
    /*if((!pawn[1] && pawn[2] && pawn[3]) || (pawn[1] && pawn[2] && !pawn[3]) || (pawn[1] && pawn[2] && pawn[3]))
    {
        dp[2] = 1;
    }*/
    if (pawn[1] && pawn[2])
    {
        dp[2] = 1;
    }
    else
    {
        dp[2] = 0;
    }

    for(int i = 3; i <= n; i++)
    {
        if(pawn[i])
        {
            /*if(pawn[i + 1] && i < n)
            {
                dp[i] = min(dp[i - 2] , dp[i - 1]) + 1;
                continue;
            }*/
            if (i == n)
            {
                dp[i] = min(dp[i - 2] , dp[i - 1]) + 1;
                break;
            }

            if (pawn[i - 1])
            {
                dp[i] = min(dp[i - 2] , dp[i - 1]) + 1;
                continue;
            }
            dp[i] = min(dp[i - 2] , dp[i - 1]);
        }
        else
        {
            // dp[i] = min(dp[i - 1], dp[i - 2]);
            dp[i] = dp[i - 1];
        }
    }
    printf("%d" , dp[n]);
    return 0;
}