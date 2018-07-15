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

int a[100007], m[100007], ans[100007], pre[100007];
vector < vector <int> > v(100007);
vector < pair < pair <int, int>, int > > g;

int dfs(int idx, int x, int y)
{
	int ans = 0, N = a[idx];
	x = (x + N - 1) % N;
	y = (y + N - 1) % N;

	if(x > y) swap(x, y);

	for(int i = x; i != y; i++) ans += v[idx][i];
	ans = min(ans, m[idx] - ans);
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, q, i, j, u, w, x, y, z, X, Y, num, k;
		int ans1, ans2;
		int v1, c1, v2, c2;

		cin >> t;

		while(t--)
			{
				g.clear();
				v.clear();
				for(i = 0; i < 100007; i++) ans[i] = a[i] = m[i] = pre[i] = 0;
					
				cin >> n >> q;
				
				for(i = 0; i < n; i++)
					{
						cin >> a[i];
						m[i] = 0;

						for(j = 0; j < a[i]; j++)
							{
								cin >> u;
								m[i] += u;
								v[i].pb(u);
							}	
					}

				X = Y = 0;

				for(i = 0; i < n; i++)
					{
						cin >> x >> y >> z;
						g.pb(mp(mp(x, y), z));
						X += z;
					}

				for(i = 0; i < n; i++)
					{
						num = (i + n - 1) % n;

						x = g[num].f.s;
						y = g[i].f.f;

						ans[i] = dfs(i, x, y);
						Y += ans[i];
					}	

				pre[0] = ans[0] + g[0].s;
				for(i = 0; i < n; i++) pre[i] = pre[i - 1] + ans[i] + g[i].s;

				while(q--)
					{
						cin >> v1 >> c1 >> v2 >> c2;
						c1--; c2--;

						if(c1 > c2) swap(c1, c2);

						ans1 = pre[c2] + g[c1].s - pre[c1] - ans[c2] - g[c2].s;
						x = ans1;

						k = dfs(c1, v1, g[c1].f.f);
						ans1 += min(k, m[c1] - k);

						k = dfs(c2, v2, g[c2].f.s);
						ans1 += min(k, m[c2] - k);

						ans2 = X + Y - x - ans[c1] - ans[c2];

						int idx = (c1 + n - 1) % n;

						ans2 += dfs(c1, v1, g[idx].f.s);
						ans2 += dfs(c2, v2, g[c2].f.f);

						cout << min(ans1, ans2) << endl;
					}

			}

		return 0;
	}