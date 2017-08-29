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
#define mod 1000000007
#define pb push_back

vector < pair <int, int > > g[10007];

int endNode;
int ans;

int dfs(int index, int dist)
{
	if(dist>ans)
		return 0;

    if(index==endNode)
        {
            ans=min(ans, dist);
            return 0;
        }
    
    vector< pair<int, int> >::iterator it;
    int u;
    
    for(it=g[index].begin(); it!=g[index].end(); it++)
        {
            u=it->first;
            dfs(u, dist+it->second);
        }
    
    return 0;
}

int main()
{
    int n, m, q, i, u, v, wt;
    
    cin >> n >> m >> q;
    
    for(i=0; i<m; i++)
	    {
	        cin >> u >> v;
	        g[u].pb(make_pair(v, wt));
	        g[v].pb(make_pair(u, wt));
	    }
    
    while(q--)
        {
            ans=100000001;
            cin >> u >> endNode;
            dfs(u, 0);
            cout << ans << endl;
        }
    
    return 0;
}