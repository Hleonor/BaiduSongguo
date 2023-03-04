//
// Created by Hleonor on 2023-03-04.
//
#include<bits/stdc++.h>
/*N =（(n + 1)(2n^2 + 3n - 1) / 8）,n为奇数；

N =  （n(n + 2)(2n + 1)  / 8）,n为偶数；*/
using namespace std;

int main()
{
    int n, a[100 + 10], b[100 + 10];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int sum = 0;
        if (a[i] % 2 == 0)
        {//偶数等分
            sum = a[i] * (a[i] + 2) * (2 * a[i] + 1) / 8;
        }
        else
        {
            sum = (a[i] + 1) * (2 * a[i] * a[i] + 3 * a[i] - 1) / 8;
        }
        b[i] = sum;
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << endl;
    }

    return 0;
}