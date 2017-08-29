#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

#define maxn 100001
#define oo 1000000001
#define x first
#define prev sdfdfasdf
#define y second
using namespace std;
typedef pair < int , int > II;
typedef pair < int , II > III;
III e[maxn];
vector < int > g[maxn];
int cnt[maxn],child[maxn],s[maxn],pos[maxn],head[maxn],cur[maxn],d[maxn],itmax[maxn],itmin[maxn];
int n,deg[maxn],cl[maxn],prev[maxn],x[maxn],hlt[maxn],dhlt[maxn],pose[maxn];
void doc()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        deg[u]++;g[u].push_back(v);
        deg[v]++;g[v].push_back(u);
        e[i]=III(w,II(u,v));
    }
}
void hatlote()
{
    int l=1,r=0;
    x[++r]=1;
    cl[1]=1;
    while(l<=r)
    {
        int u=x[l++];
        for(int i=0;i<deg[u];i++)
        {
            int v=g[u][i];
            if(cl[v]==0)
            {
                cl[v]=1;
                prev[v]=u;
                x[++r]=v;
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        int u=x[i],slmax=0,j0=0;
        for(int j=0;j<deg[u];j++)
        {
            cnt[u]=1;
            int v=g[u][j];
            if(prev[v]==u)
            {
                cnt[u]+=cnt[v];
                if(slmax<cnt[v])
                {
                    child[u]=v;
                    j0=j;
                    slmax=cnt[v];
                }
            }
        }
         if(slmax*2<cnt[u]) child[u]=0,j0=0;
         swap(g[u][0],g[u][j0]);
    }
    int k=0,sn=0;
    s[++sn]=1,hlt[++k]=1,pos[1]=k,head[1]=1;
    while(sn)
    {
        int u=s[sn];
        if(cur[u]<deg[u]&&g[u][cur[u]]==prev[u]) cur[u]++;
        if(cur[u]==deg[u]) sn--;else
        {
            int v=g[u][cur[u]++];
            hlt[++k]=v,pos[v]=k;
            if(v==child[u]) head[v]=head[u];head[v]=v;
            s[++sn]=v;
        }
    }
    dhlt[1]=1;
    for(int i=1;i<=n;i++)
    {
        int u=x[i];
        for(int j=0;j<deg[u];j++)
        {
            int v=g[u][j];
            if(prev[v]==u&&child[u]!=v) dhlt[v]=dhlt[head[u]]+1;
        }
    }
    for(int i=1;i<n;i++)
    {
        int u=e[i].y.x,v=e[i].y.y;
        if(prev[v]==u) pose[i]=pos[v];else pose[i]=pos[u];
    }
}
void suait(int r)
{
    int tlmax,tlmin,trmax,trmin;
    tlmax=(d[2*r]%2)?-itmin[2*r]:itmax[2*r];
    tlmin=(d[2*r]%2)?-itmax[2*r]:itmin[2*r];
    trmax=(d[2*r+1]%2)?-itmin[2*r+1]:itmax[2*r+1];
    trmin=(d[2*r+1]%2)?-itmax[2*r+1]:itmin[2*r+1];
    itmax[r]=max(tlmax,trmax);
    itmin[r]=max(tlmin,trmin);
}
void gan(int r,int k,int l,int u,int val)
{
    if(u<k||u>l) return;
    if(u<=k&&l<=u)
    {
        itmax[r]=itmin[r]=val;
        return;
    }
    int g=(k+l)/2;
    gan(2*r,k,g,u,val);
    gan(2*r+1,g+1,l,u,val);
    suait(r);
}
void daodau(int r,int k,int l,int u,int v)
{
    if(u>l||v<k) return;
    if(u<=k&&l<=v)
    {
        d[r]++;return;
    }
    int g=(k+l)/2;
    d[2*r]+=d[r],d[2*r+1]+=d[r];d[r]=0;
    daodau(2*r,k,g,u,v);
    daodau(2*r+1,g+1,l,u,v);
    suait(r);
}
int get(int r,int k,int l,int u,int v)
{
    if(v<k||u>l) return -oo;
    if(u<=k&&l<=v) return (d[r]%2)?-itmin[r]:itmax[r];
    d[2*r]+=d[r],d[2*r+1]+=d[r];
    d[r]=0;
    int g=(k+l)/2;
    int t1=get(2*r,k,g,u,v);
    int t2=get(2*r+1,g+1,l,u,v);
    suait(r);
    return max(t1,t2);
}
int dis(int u,int v)
{
    int ds=-oo;
    while(dhlt[head[u]]>dhlt[head[v]])
    {
        ds=max(ds,get(1,1,n,pos[head[u]],pos[u]));
        u=prev[head[u]];
    }
    while(dhlt[head[u]]<dhlt[head[v]])
    {
        ds=max(ds,get(1,1,n,pos[head[v]],pos[v]));
        v=prev[head[v]];
    }
    while(head[u]!=head[v])
    {
        ds=max(ds,get(1,1,n,pos[head[u]],pos[u]));
        u=prev[head[u]];
        ds=max(ds,get(1,1,n,pos[head[v]],pos[v]));
        v=prev[head[v]];
    }
    if(pos[u]>pos[v]) ds=max(ds,get(1,1,n,pos[v]+1,pos[u]));
    else ds=max(ds,get(1,1,n,pos[u]+1,pos[v]));
    return ds;
}
string ss;
// void tinh()
// {
//     for(int i=1;i<n;i++) gan(1,1,n,pose[i],e[i].x);
//     while(1)
//     {
//         cin>>ss;
//         if(ss[0]=='C')
//         {
//             int i,val;
//             cin>>i>>val;
//             gan(1,1,n,pose[i],val);
//         }else
//         if(ss[0]=='Q')
//         {
//             int u,v;
//             cin>>u>>v;
//             cout<<dis(u,v)<<endl;
//         }else
//         if(ss[0]=='N')
//         {
//             int u,v;
//             cin>>u>>v;
//             daodau(1,1,n,u,v);
//         }else break;
//         ss.clear();
//     }
// }
void khoitao()
{
    for(int i=1;i<=n;i++)
    {
        cl[i]=prev[i]=deg[i]=x[i]=hlt[i]=dhlt[i]=head[i]=pos[i]=pose[i]=d[i]=0;
        g[i].clear();
        child[i]=cnt[i]=0;
    }
}
int main()
{
    //freopen("CHANGE.inp","r",stdin);
    //freopen("CHANGE.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        doc();
        hatlote();
        // tinh();
        khoitao();
    }
}

