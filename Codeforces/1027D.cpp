#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

vi path;
vvi cycles;
int vis[200007], a[200007], c[200007];

void dfs(int v) 
{
    path.pb(v);
    vis[v] = 1;

    int u = a[v];
    
    if(vis[u] != 2) 
	    {
	        if(vis[u] == 1) 
		        {
		            cycles.emplace_back();

		            int id = path.size() - 1;
		            
		            while(path[id] != u)
		                cycles.back().pb(path[id--]);

		            cycles.back().pb(u);
		        } 
	        else
	            dfs(u);
	    }

    path.pop_back();
    vis[v] = 2;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> c[i];
		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++)
			if(!vis[i]) dfs(i);

		for(i = 0; i < cycles.size(); i++) {
			u = INT_MAX;
			for(j = 0; j < cycles[i].size(); j++) 
				u = min(u, c[cycles[i][j]]);
				// cout << cycles[i][j] << " "; cout << endl;
			ans += u;
		}
		cout << ans << endl;

		return 0;	
	}