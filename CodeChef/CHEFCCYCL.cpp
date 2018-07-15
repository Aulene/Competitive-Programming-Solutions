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

#define pb push_back
#define mp make_pair
#define f first
#define s second

struct cycle
{
	int u, v, sz;
	vector <int> a, pre;

	void calcprefix()
		{
			pre.resize(sz);
			pre[0] = a[0];
			for(int i = 1; i < sz; i++) pre[i] = pre[i - 1] + a[i];
		}

	int dist(int ux, int vx)
		{
			if(ux == vx) return 0;
			if(ux > vx) swap(ux, vx);

			int ans = pre[vx - 1] - (ux == 0 ? 0 : pre[ux - 1]);

			return min(ans, pre[sz - 1] - ans); 
		}

	int insideDist() { return dist(u, v); }
};

vector < pair < pair <int, int>, int> > vs;
cycle g[100007];
int ans1[100007], ans2[100007], sum;

int withinCycle(int idx, int u, int v) { return g[idx].dist(u, v); }

int outsideCycle(int u, int v, int idx)
{
	if(u > v) swap(u, v);

	if(!idx) return ans1[v - 1] - (u == 0 ? 0 : ans1[u - 1]) + ans2[v - 1] - ans2[u]; 
    else return sum - g[u].insideDist() - g[v].insideDist() - (ans1[v - 1] - (u == 0 ? 0 : ans1[u - 1]) + ans2[v - 1] - ans2[u]);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, u, v, w, q, numedge;
		int x, y, z, v1, c1, v2, c2;
		int ans1x, ans2x, ans;

		cin >> t;

		while(t--)
			{
				vs.clear();
				
				sum = 0;

				cin >> n >> q;

				for(i = 0; i < n; i++)
					{
						cin >> m;
						
						g[i].a.resize(m);
						g[i].sz = m;	

						for(j = 0; j < m; j++) cin >> g[i].a[j];
						g[i].calcprefix();
					}

				for(i = 0; i < n; i++)
					{
						cin >> x >> y >> z; x--; y--;
						vs.pb(mp(mp(x, y), z));
					}

				for(i = 0; i < n; i++)
					{
						if(!i)
							{
								g[i].u = vs[n - 1].f.s;
								g[i].v = vs[i].f.f;
							}
						else
							{
								g[i].u = vs[i - 1].f.s;
								g[i].v = vs[i].f.f;
							}
						
						sum += vs[i].s + g[i].insideDist();
					}
				
				// cout << sum << endl;
 		
				ans1[0] = vs[0].s;
				ans2[0] = g[0].insideDist();
				
				for(i = 1; i < n; i++)
					{
						ans1[i] = ans1[i - 1] + vs[i].s;
						ans2[i] = ans2[i - 1] + g[i].insideDist();
					}

				while(q--)
					{
						cin >> v1 >> c1 >> v2 >> c2;
						v1--; c1--; v2--; c2--;

						if(c1 > c2)
							{
								swap(c1, c2);
								swap(v1, v2);
							}

						ans1x = withinCycle(c1, v1, g[c1].v) + outsideCycle(c1, c2, 0) + withinCycle(c2, v2, g[c2].u);
						ans2x = withinCycle(c1, v1, g[c1].u) + outsideCycle(c1, c2, 1) + withinCycle(c2, v2, g[c2].v);
						
						// cout << ans1x << " " << ans2x << endl;

						// cout << withinCycle(c1, v1, g[c1].u) << " " << outsideCycle(c1, c2, 1) << " " << withinCycle(c2, v2, g[c2].v) << endl;
						ans = min(ans1x, ans2x);
						cout << ans << endl;
					}
			}

		return 0;
	}