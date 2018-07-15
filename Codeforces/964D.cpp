#include<bits/stdc++.h>
using namespace std;
 
int visit[200007];
 
void bfs(vector<int>*g,int src)
{
    int x,i;
    queue<int>qu;
    visit[src]=true;
    qu.push(src);
    while(!qu.empty())
    {
        int f=qu.front();
        qu.pop();
        printf("%d\n",f);
        for(i=0;i<g[f].size();i++)
        {
            x=g[f][i];
            if(!visit[x])
            {
                qu.push(x);
                visit[x]=1;
            }
        }
    }
 
}
 
 
int main()
{
    vector<int>g[200007];
    int n,i,a,c1=0,c2=0,src;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a!=0)
        {
            g[i].push_back(a);
            g[a].push_back(i);
        }
    }
    for(i=1;i<=n;i++)
        {
            if(g[i].size()%2==1)
            {
                c1++;
            }
            else
            {
                c2++;
                src=i;
            }
        }
    
    if(c1==(n-1)&&c2==1)
        {
            printf("YES\n");
            bfs(g,src);
        }
    else
    {
        printf("NO\n");
    }
    return 0;
}