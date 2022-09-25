//
// Created by Hleonor on 2022-09-25.
//
#include <iostream>
#include <string>
using namespace std;

bool book = true;
int main()
{
    int n , k;
    scanf("%d%d", &n, &k);
    string str;
    cin >> str;
    int left;
    int record = 0;
    for (int i = 0; i < n; i++)
    {
        left = i + 1;
        for (int j = 0; j < n; j++)
        {
            if (left < n)
            {
                if (str[j] != str[left])
                {
                    book = false;
                }
                left++;
            }
        }
        if (book)
        {
            break;
        }
        book = true;
        record = i + 1;
    }
    int count = n - record - 1;
    int left_count = n - count;
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j < left_count; j++)
        {
            printf("%c", str[j]);
        }
    }
    cout << str;
    return 0;
}