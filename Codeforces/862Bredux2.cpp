#include<iostream>
#include<string>
#include<sstream>
#include<queue>
#include<set>
#include<stack>
#include<cstring>
#include<vector>
#include<bitset>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<map>
#include<functional>
 
 using namespace std;
#define mx 100005
vector<int>g[mx];
int color[mx],visited[mx];
int cycle;
void bfs(int s)
{
    color[s]=1;
    visited[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
 
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i];
            if(visited[v])
            {
                if(color[v]==color[u])
                {
                    cycle=1;
                }
            }
            else
            {
                q.push(v);
                color[v]=1-color[u];
                visited[v]=1;
            }
        }
    }
 
 
}
int main()
{
    int n,m;
    cin>>n;
    m=n-1;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    bfs(1); //cout<<"here";
    int red=0,blue=0;
    for(int i=1; i<=n; i++)
    {
        if(color[i]) red++;
        else blue++;
    }
  //  cout<<red<<" "<<blue<<endl;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(color[i])
        {
            ans+=(blue-g[i].size());
        }
        else
        {
            ans+=(red-g[i].size());
        }
    }
    cout<<ans/2<<endl;
 
}