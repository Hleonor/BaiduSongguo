//
// Created by Hleonor on 2022-10-14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a , int b)
{
    return a > b;
}

int main()
{
    int n;
    vector<int> pearl;
    vector<int> beautifulness;
    int result = 0;
    scanf("%d" , &n);
    for (int i = 0; i < n ; i++)
    {
        int x;
        scanf("%d" , &x);
        pearl.push_back(x);
    }
    sort(pearl.begin() , pearl.end() , cmp);
    int last_number = 0;
    int get_ = 0;
    for (int i = 0; i < pearl.size(); i++)
    {
        if (i % 2 == 0)
        {
            beautifulness.push_back(pearl[get_]);
        }
        else
        {
            beautifulness.push_back(pearl[pearl.size() - 1 - get_]);
            get_++;
        }
        result += abs(last_number - beautifulness[beautifulness.size() - 1]);
        last_number = beautifulness[beautifulness.size() - 1];
    }
    result -= pearl[0];
    result += abs(beautifulness[0] - beautifulness[beautifulness.size() - 1]);
    printf("%d" , result);
    return 0;
}