//
// Created by Hleonor on 2022-09-25.
//
#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e6+5;
struct node
{
    int id,score;
    bool operator < (node a)
    {
        if(score != a.score)
            return score>a.score;
        else
            return id<a.id;
    }
}a[maxn];
int score[maxn];
int n,m;
int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i = 0;i<n;i++)
    {
        int id,s;
        cin>>id>>s;
        score[id] = s;
    }
    cin>>m;
    int t;
    vector<node>b;
    for (int i = 0;i<m;i++)
    {
        b.clear();
        while (true)
        {
            cin>>t;
            if (!t) break;
            struct node anode = {t,score[t]};
            b.push_back(anode);
        }
        sort(b.begin(),b.end());
        for (auto k:b)
        {
            cout<<k.id<<' ';
        }
        cout<<'\n';
    }

    return 0;
}