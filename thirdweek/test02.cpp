#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    for (int i = 0;i<10;i++) // 从键盘输入10个整数
    {
        cin>>arr[i];
    }
    for (int i = 0;i<10;i++) // 输出10个整数
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl; // 换行
    int* p = arr;
    for (int i = 0;i<10;i++)
    {
        cout<<*p<<' ';
        p++;
    }
}