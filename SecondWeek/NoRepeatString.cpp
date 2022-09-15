#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int getMaxNoRepeatLen(string str)
{
    int len = str.length();
    vector<int> pos(128, 0);
    int i = 0;
    int maxLen = 0;
    for (int j = 0; j < len; j++)
    {
        i = max(i , pos[str[j]]);
        pos[str[j]] = j + 1;
        maxLen = max(maxLen, j - i + 1);
    }
    return maxLen;
}
int main( )
{
    string str;;
    getline(cin, str);
    printf("%d" , getMaxNoRepeatLen(str));
    return 0;
}