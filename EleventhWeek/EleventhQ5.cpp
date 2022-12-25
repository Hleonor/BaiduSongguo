//
// Created by Hleonor on 2022-12-25.
//
#include<bits/stdc++.h>

using namespace std;

int main( )
{
    string str;
    cin >> str;
    int m;
    scanf("%d" , &m);
    // 声明一个字符串字典
    map<char , string> strMap;
    for (int i = 1; i <= m; i++)
    {
        char str1;
        string str2;
        cin >> str1 >> str2;
        strMap[str1] = str2;
    }
    int p = 0;
    while (p < str.length())
    {
        if (str.length() > 1000)
        {
            printf("impossible");
            return 0;
        }
        // 从字典中查找是否有匹配的字符串
        char ch = str[p];
        if (strMap.find(ch) != strMap.end())
        {
            // 如果有匹配的字符串，就将其替换
            str.replace(p , 1 , strMap[ch]);
        }
        p++;
    }
    cout << str;
    return 0;
}