#include<bits/stdc++.h>
#include <vector>
#define mod 10007
using namespace std;
vector<int> vec;
int point = 0, perfect = 0;

void merge()
{
    if (vec.size() <= 1) // 如果只有一个元素，直接返回
    {
        return;
    }
    int flag = 0; // 标记是否有序
    for (int i = 0; i < vec.size()-1; i++)
    {
        if (vec[i] == vec[i+1]) // 合并相同的元素
        {
            flag = 1;
            vec[i] *=2;
            point += vec[i];
            point %= mod;
            vec.erase(vec.begin() + i + 1);
            if (vec[i] > 2048)
            {
                vec.erase(vec.begin()+i);
                perfect++;
            }
            break;
        }
    }
    if(flag)
    {
        merge();
    }
}

void ins(int num,int pos)
{
    point += num;point = point % mod;
    if (vec.empty())
    {
        vec.push_back(num);
    }
    else
    {
        vec.insert(vec.begin() + pos,1,num);
        merge();
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int num,pos;
        cin>>num>>pos;
        ins(num,pos);
    }
    for (int i = 0; i <vec.size(); i++)
    {
        cout << vec[i] <<" ";
    }
    cout <<'\n';
    cout<<point<<" "<<perfect<<"\n";
}

