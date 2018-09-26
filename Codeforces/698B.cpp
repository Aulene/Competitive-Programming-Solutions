/*
7
4 3 2 6 3 5 2
 */
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define N 200007

vector <int> path;
vector < vector <int> > cycles;
int vis[N], a[N];
vvi g(N);

void cycleFind(int v, int p) 
{
    path.push_back(v);
    vis[v] = 1;
    
    int vispar = 0;

    for(int i = 0; i < g[v].size(); i++)
	    {
	    	int u = g[v][i];

	    	if(u == p && !vispar) {
	    		vispar = 1;
	    		continue;
	    	}

	    	if(vis[u] != 2) 
			    {
			        if(vis[u] == 1) 
				        {
				            cycles.emplace_back();

				            int id = path.size() - 1;
				            
				            while(path[id] != u)
				                cycles.back().push_back(path[id--]);

				            cycles.back().push_back(u);
				        } 
			        else
			            cycleFind(u, v);
			    }
    	}
    

    path.pop_back();
    vis[v] = 2;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, ans = 0, root = -1;

		cin >> n;

		for(i = 1; i <= n; i++) 
			{
				cin >> a[i];

				if(a[i] == i)
					{
						if(root == -1)
							root = i;
						else	
							{
								ans++;
								a[i] = root;
								g[i].pb(root);
								g[root].pb(i);
							}
					}
				else 
					g[i].pb(a[i]), g[a[i]].pb(i);	
			}

		// cout << root << endl;
		
		if(root == -1) {
			root = 1;
			ans++;
			a[1] = 1;
		}
		for(int i = 1; i <= n; i++)
			if(!vis[i]) cycleFind(i, -1);

		for(i = 0; i < cycles.size(); i++) {
			for(j = 0; j < cycles[i].size(); j++) cout << cycles[i][j] << " "; cout << endl;
		} cout << endl;

		for(i = 0; i < cycles.size(); i++)
			{
				u = cycles[i][0], v = cycles[i][cycles[i].size() - 1];

				if(u != v) {
					a[v] = root;
					ans++;
				}
			}

		cout << ans << endl;
		for(i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;

		return 0;
	}