#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> g[200007];
int vis[200007];

void bfs(int src)
{
    int u, v, i;
    queue <int> q;
    vis[src] = 1;

    q.push(src);
    
    while(!q.empty())
	    {
	        u = q.front();
	        q.pop();

	        cout << u << endl;
	        
	        for(i = 0; i < g[u].size(); i++)
		        {
		            v = g[u][i];
		            if(!vis[v])
			            {
			                q.push(v);
			                vis[v] = 1;
			            }
		        }
	    }
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, a, u, v, odd = 0, even = 0, src;
	
		cin >> n;

	    for(i = 1; i <= n; i++)
		    {
		       	cin >> u;
		        if(u) g[i].push_back(u), g[u].push_back(i);
		    }

	    for(i = 1; i <= n; i++)
	        {
	            if(g[i].size() % 2 == 1)
	           		odd++;
	            else
		            {
		                even++;
		                src = i;
		            }
	        }
	    
	    if((odd == (n - 1)) && even == 1)
	        {
	            cout << "YES" << endl;
	            bfs(src);
	        }
	    else
	    	cout << "NO" << endl;

		return 0;
	}