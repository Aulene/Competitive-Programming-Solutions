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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> g[100007];
int ans[100007]; bool f1[100007];


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, k, u, v, c;
		bool ansx;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 100007; i++) ans[i] = 0, f1[i] = 0, g[i].clear();
				ansx = 1;

				cin >> n >> m;

				for(i = 0; i < m; i++)
					{ 	
						cin >> u >> v;
						g[u].pb(v);
					}

				for(i = 0; i <= n; i ++) sort(g[i].begin(), g[i].end());

				u = 1;

				for(i = 0; i < g[0].size(); i++)
					ans[g[0][i]] = u, u++;
				
				for(i = 1; i < n; i++)
					{
						if(g[i].size() == 1)
							{
								v = 0, c = 0;

								for(j = g[i][0]; j <= n; j++)
									if(ans[j]) v = ans[j], c++;
								
								if(c > 1) { ansx = 0; break; }
								else
									{
										for(k = g[i][0]; k <= n; k++)
											if(ans[k] == 0) ans[k] = v;
									}
							}
						else
							{
								for(j = 1; j < g[i].size(); j++)
									{
										u = g[i][j - 1], v = g[i][j];

										if(v - u == 1 && ans[v] && ans[v - 1])
											{
												for(k = u + 1; k < v; k++)
													if(ans[k] && ans[k - 1] && ans[k] != ans[k - 1]) { ansx = 0; break; }
												if(!ansx) break;
											}
										else if(v - u != 1)
											{
												for(k = u; k < v; k++)
													if(ans[k] == 0) ans[k] = i;
 											}			
									}
							}

						if(!ansx)
							break;
					}

				if(ansx)
					{
						for(i = 1; i <= n; i++)
							{
								if(f1[ans[i]] == 1)
									{ 
										if(find(g[0].begin(), g[0].end(), i) != g[0].end()) { ansx = 0; break; } 
									}
								else f1[ans[i]] = 1;
							}
					}

				if(ansx)
					{ 
						for(i = 1; i <= n; i++) cout << ans[i] << " "; 
						cout << endl;
					}
				else
					cout << -1 << endl;
			}

		return 0;
	}