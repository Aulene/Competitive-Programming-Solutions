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

vi ord;
vvi g(200007);
vector < set <int> > sx(200007);
queue <int> q;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, node;
		bool ans = 1;

		cin >> n;

		for(i = 0; i < n - 1; i++) 
			{
				cin >> u >> v;
				sx[u].insert(v);
				sx[v].insert(u);
				g[u].pb(v);
				g[v].pb(u);
			}

		for(i = 0; i < n; i++) cin >> u, ord.pb(u);

		i = 0;

		if(ord[0] != 1) {
			cout << "No" << endl;
			return 0;
		}

		q.p(1);
		i = 1;
		node = 1;

		while(i < n)
			{
				// cout << i << " " << node << endl;

				u = ord[i];

				if(sx[node].count(u) != 0)
					{
						// cout << "EBOLA" << endl;
						sx[u].erase(node);
						sx[node].erase(u);
						q.p(u);
						i++;
					}
				else
					{
						if(!q.empty())
							{
								// cout << "HOLA" << endl;
								node = q.front();
								q.pop();
								continue;
							}
						else
							{ ans = 0; break;}
					}
			}

		if(i != n) ans = 0;

		if(ans) cout << "Yes" << endl;
		else cout << "No" << endl;

		return 0;
	}