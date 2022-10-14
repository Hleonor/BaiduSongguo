#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string str;
    Solution(string s) : str(s) {}

    Solution operator+(const Solution& b)
    {
        Solution c(this->my_add(this->str, b.str));
        return c;
    }
    string my_add(string number1, string number2) {
        int i = number1.size() - 1;
        int j = number1.size() - 1;
        string result ="";
        int add = 0;
        //考虑下标从0开始的情况，所以size-1
        //同时考虑所有位数耗尽，但是还存在进位的情况
        while(i>=0 || j>=0 || add != 0){
            int x = i >= 0 ? number1[i] - '0' : 0;
            int y = j >= 0 ? number2[j] - '0' : 0;
            int ret = x + y + add;
            //填入的位数再换成char数据类型
            result.push_back('0' + ret % 10);
            add = ret / 10;
            i--;
            j--;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main( )
{
    string m , n;
    cin >> m >> n;
    Solution m_(m) , n_(n);
    Solution ret = m_ + n_;
    cout<< ret.str;
    return 0;
}