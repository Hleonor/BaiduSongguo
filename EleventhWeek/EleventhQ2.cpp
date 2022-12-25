//
// Created by Hleonor on 2022-12-25.
//
#include<bits/stdc++.h>

using namespace std;
inline int read() {
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}
inline void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=5e5+50;
struct edge{
    int to,nex;
}e[N<<1];
int head[N],n,m;
int dep[N];
int num;
int fa[N][20];
inline void add(int x,int y)
{
    e[num]=(edge){y,head[x]};
    head[x]=num++;
}
inline void dfs(int x,int pre)
{
    fa[x][0]=pre;
    dep[x]=dep[pre]+1;
    int too;
    for(int i=head[x];i!=-1;i=e[i].nex)
    {
        too=e[i].to;
        if(too==pre)
            continue;
        dfs(too,x);
    }
}
inline int lca(int u,int v)
{
    if(dep[u]>dep[v]) swap(u,v);
    int temp=dep[v]-dep[u];
    for(int i=0;(1<<i)<=temp;++i)
    {
        if((1<<i)&temp)
            v=fa[v][i];
    }
    if(u==v)
        return u;
    for(int i=(int)log2(n*1.0);i>=0;--i)
    {
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}
inline int big_lca(int x, int y, int z, int &ans) {
    int root[3];
    root[0] = lca(x, y);
    root[1] = lca(y, z);
    root[2] = lca(x, z);
    if (root[0] == root[1] && root[1] == root[2]) {//情况一
        ans = root[0];
        return (dep[x] - dep[root[0]]) + (dep[y] - dep[root[0]]) + (dep[z] - dep[root[0]]);
    }
    if (root[0] == root[1] && root[1] != root[2]) {//情况二
        ans = root[2];
        return (dep[x] - dep[root[2]]) + (dep[y] - dep[root[0]]) + (dep[z] - dep[root[2]]) + (dep[root[2]] - dep[root[0]]);
    }
    if (root[0] != root[1] && root[1] == root[2]) {//情况二
        ans = root[0];
        return (dep[x] - dep[root[0]]) + (dep[y] - dep[root[0]]) + (dep[z] - dep[root[2]]) + (dep[root[0]] - dep[root[1]]);
    }
    if (root[0] == root[2] && root[1] != root[2]) {//情况二
        ans = root[1];
        return (dep[x] - dep[root[2]]) + (dep[y] - dep[root[1]]) + (dep[z] - dep[root[1]]) + (dep[root[1]] - dep[root[2]]);
    }
}
int main ()
{
    n=read(),m=read();
    memset(head,-1,sizeof(head));
    int uu,vv;
    for(int i=1;i<n;++i)
    {
        uu=read(),vv=read();
        add(uu,vv);
        add(vv,uu);
    }
    dfs(1,0);
    for(int j=0;(1<<(j+1))<n;++j)
    {
        for(int i=1;i<=n;++i)
        {
            if(fa[i][j]<=0) fa[i][j+1]=0;
            else fa[i][j+1]=fa[fa[i][j]][j];
        }
    }
    int x,y,z,ans,p;
    for(int i=1;i<=m;++i)
    {
        x=read(),y=read(),z=read();
        p=big_lca(x,y,z,ans);
        write(ans);
        printf(" ");
        write(p);
        printf("\n");
    }
    return 0;
}