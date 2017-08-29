#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>
 
using namespace std;
 
#define lli long long int
#define verybigval LLONG_MAX
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
 
vector< pair< lli, lli > > g[100007];
vector<lli> browser;
priority_queue< pair <lli, lli >, vector < pair <lli, lli > >, greater < pair <lli, lli > > > pq;
lli dist[100007];
bool vis[100007];

lli k, x, m, s, n;
lli a, b, c;

lli dijkstra1(lli start)
{
    lli i, v, d;
    lli minDist=verybigval;
    vector< pair <lli, lli> >::iterator it;
 
    for(i=0; i<100007; i++)
        {
            dist[i]=verybigval;
            vis[i]=0;
        }

    dist[start]=0;
    pq.p(mp(start, dist[start]));
 
    while(!pq.empty())
        {
            v=pq.top().first;
            d=pq.top().second;
            pq.pop();
            
            if(vis[v])
                continue;

            vis[v]=1;

            for(it=g[v].begin(); it!=g[v].end(); it++)
                if(dist[it->first] > it->second+d)
                    {
                        dist[it->first]=it->second+d;
                        pq.p(mp(it->first, dist[it->first]));
                    }
        }
    
    minDist=dist[1];
    for(i=2; i<=k; i++)
        minDist=min(minDist, dist[i]);

    for(i=1; i<=k; i++)
        dist[i]=min(dist[i], minDist+x);

    return 0;
}
 
lli dijkstra2(lli start)
{
    lli i, v, d;
    vector< pair <lli, lli> >::iterator it;
    vector<lli>::iterator it2;

    for(i=1; i<100007; i++)
        vis[i]=0;
    
    for(it2=browser.begin(); it2!=browser.end(); it2++)
        pq.p(mp(*it2, dist[*it2]));

    while(!pq.empty())
        {
            v=pq.top().first;
            d=pq.top().second;
            pq.pop();   
            
            if(vis[v])
                continue;

            vis[v]=1;

            for(it=g[v].begin(); it!=g[v].end(); it++)
                if(dist[it->first] > it->second+d)
                    {
                        dist[it->first]=it->second+d;
                        pq.p(mp(it->first, dist[it->first]));
                    }
        }
    
    return 0;
}

int main()
    {
        lli t, n, i, j;

        cin >> t;
 
        while(t--)
            {
                cin >> n >> k >> x >> m >> s;
 
                for(i=0; i<m; i++)
                    {
                        cin >> a >> b >> c;
                        g[a].pb(mp(b, c));
                        g[b].pb(mp(a, c));

                        if(a<=k)
                            browser.pb(a);
                        if(b<=k)
                            browser.pb(b);
                    }   
 
                dijkstra1(s);
                dijkstra2(s);

                for(i=1; i<=n; i++)
                    cout << dist[i] << " ";
                cout << endl;
 
                for(i=0; i<100007; i++)
                    g[i].clear();
                browser.clear();
            }
        return 0;
    } 