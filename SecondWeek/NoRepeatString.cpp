#include <iostream>
#include <string.h>
using namespace std;

int main( )
{
    char str[99999] = {'\0'};
    gets(str);
    int maxLen = 0;
    /*printf("%d\n" , strlen(str));
    printf("%s\n", str);*/
    for (int i = 0; i < strlen(str); i++) // 起点为i
    {
        for (int j = 1; j <= strlen(str) - i + 1; j++) // 截取长度为j
        {
            char subStr[99999];
            strncpy(subStr, str + i, j); // 从i处开始截取长度为j的字符串
            int k;
            for (k = 0; k < strlen(subStr); k++) // 判断subStr中第k个字符是否重复出现
            {
                if (strchr(subStr, subStr[k]) != strrchr(subStr, subStr[k])) // 如果子串subStr中第k个字符正向查找和负向查找的位置不一致，说明该字符在子串中重复
                {
                    break;
                }
            }
            if (k == strlen(subStr)) // 只有当退出上面那层for循环时k正好处于subStr字符串最后一个位置时，说明此时没有重复，应考虑更新最大长度
            {
                if (k >= maxLen) // 如果k大于原先的maxLen，则更新maxLen
                {
                    maxLen = k;
                }
            }
        }
    }
    printf("%d" , maxLen);
    return 0;
}