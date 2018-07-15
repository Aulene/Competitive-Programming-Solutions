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

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > g(507), r(507);
queue < pair <int, int> > q;
bool vis[507][507];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, k, i, j, u, v;

		cin >> t;

		while(t--)
			{
				bool ans = 1;

				cin >> k >> n;

				for(i = 0; i < n; i++) 
					for(j = 0; j< n; j++) vis[i][j] = 0;

				for(i = 0; i < n; i++) g[i].clear(), r[i].clear();
				for(i = 0; i < n; i++) cin >> u, g[u].pb(i);
				for(i = 0; i < n; i++) cin >> u, r[u].pb(i);

				for(i = 0; i < n; i++) q.p(mp(i, i)), vis[i][i] = 1;

				while(!q.empty())
					{
						pair <int, int> idx = q.front();
						q.pop();

						for(i = 0; i < g[idx.f].size(); i++)
							for(j = 0; j < g[idx.s].size(); j++)
								{
									int x = g[idx.f][i], y = g[idx.s][j];

									if(!vis[x][y])
										{
											q.p(mp(x, y));
											vis[x][y] = 1;
										}
								}

						for(i = 0; i < r[idx.f].size(); i++)
							for(j = 0; j < r[idx.s].size(); j++)
								{
									int x = r[idx.f][i], y = r[idx.s][j];

									if(!vis[x][y])
										{
											q.p(mp(x, y));
											vis[x][y] = 1;
										}
								}
					}

				for(i = 0; i < n; i++)
					for(j = 0; j < n; j++) ans &= vis[i][j];

				if(ans) cout << k << " YES\n";
				else cout << k << " NO\n";
			}	
		return 0;
	}