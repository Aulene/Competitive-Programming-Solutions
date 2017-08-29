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

#define int long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first

int ind[100007], height[100007], subtree[100007];
int segtree[4 * 100007], lazy[4 * 100007], ans[100007];
vector < pair<int, int> > g[100007];
vector <int> o;
vector< pair <pair <int, int>, pair<int, int> > > order;

void dfs1(int cur, int p)
{
	if(p != -1)
		height[cur] = height[p] + 1;

	for(int i = 0; i < g[cur].size(); i++)
		{
			int x = g[cur][i].f;
			
			if(x == p)
				continue;
			
			dfs1(x, cur);
		}
}

void dfs(int cur, int p)
{
	o.pb(cur);
	subtree[cur] = 1;

	for(int i = 0; i < g[cur].size(); i++)
		{
			int v = g[cur][i].f;

			if(v != p)
				{
					dfs(v, cur);
					subtree[cur] += subtree[v];
				}			
		}
}

void update(int node, int a, int b, int l, int r, int val)
{
	if(lazy[node])
		{
			segtree[node] ^= lazy[node];
			if(a != b)
				{
					lazy[2 * node] ^= lazy[node];
					lazy[2 * node + 1] ^= lazy[node];
				}

			lazy[node] = 0;
		}

	if(a > b || a > r || b < l)
		return;

	if(a >= l && b <= r)
		{
			segtree[node] ^= val;
			
			// cout << "A " << a << " " << "B " << b << endl;
			// cout << "TREE NODE " << node << " UPDATED WITH " << val << endl;

			if(a != b)
				{
					lazy[2 * node] ^= val;
					lazy[2 * node + 1] ^= val;
					// cout << "LAZY'D " << 2 * node << " AND " << 2 * node + 1 << endl; 
				}

			return;
		}

	int mid = (a + b) / 2;
	update(2 * node, a, mid, l, r, val);
	update(2 * node + 1, mid + 1, b, l, r, val);
	segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
}

int query(int node, int a, int b, int l, int r)
{
	if(lazy[node])
		{
			segtree[node] ^= lazy[node];

			if(a != b)
				{
					// cout << "UNLAZY'D " << 2 * node << " AND " << 2 * node + 1 << endl;
					lazy[2 * node] ^= lazy[node];
					lazy[2 * node + 1] ^= lazy[node];
				}

			lazy[node] = 0;
		}

	if(a > b || a > r || b < l)
		return 0;

	if(a >= l && b <= r)
		return segtree[node];

	int mid = (a + b) / 2;

	return max(query(2 * node, a, mid, l, r), query(2 * node + 1, mid + 1, b, l, r));
}

signed main()
{
	int i, j, n, t, x, y, z, q;

	cin >> t;
	
	while(t--)
		{
			cin >> n;

			for(i = 0; i <= n; i++)
				g[i].clear();

			for(i = 0; i < 100007; i++)
				{
					segtree[i] = 0;
					lazy[i] = 0;
				}

			order.clear();
			o.clear();

			for(i = 1; i <= n - 1; i++)
			{
				cin >> x >> y >> z;

				g[x].pb(mp(y, z));
				g[y].pb(mp(x, z));
				order.pb(mp(mp(z, -1),mp(x, y)));
			}

			cin >> q;

			for(i = 1; i <= q; i++)
				{
					cin >> x >> y >> z;
					order.pb(mp(mp(z, i),mp(x, y)));
				}

			sort(order.begin(), order.end());
			
			dfs1(1, -1);
			o.pb(-1);
			dfs(1, -1);

			cout << "Oi operations" << endl;
			for(i = 1; i <= n; i++)
				{
					ind[o[i]] = i;
					cout << o[i] << " " << i << " " << ind[o[i]] << endl;
				}
			cout << "Oi complete" << endl;

			// cout << "HEIGHT IN" << endl;
			// for(i = 1; i <= n; i++)
			// 	cout << height[i] << " ";
			// cout << endl << "HEIGHT OUT" << endl;

			// cout << "SIZE IN" << endl;
			// for(i = 1; i <= n; i++)
			// 	cout << subtree[i] << " ";
			// cout << endl << "SIZE IN" << endl;

			// cout << "O IN" << endl;
			// for(i = 1; i <= n; i++)
			// 	cout << o[i] << " ";
			// cout << endl << "O OUT" << endl;

			// cout << "IND IN" << endl;
			// for(i = 1; i <= n; i++)
			// 	cout << ind[i] << " ";
			// cout << endl << "IND OUT" << endl;

			// cout << "STORE IN" << endl;
			// for(i = 0; i <= order.size(); i++)
			// 	cout << order[i].f.f << " " << order[i].f.s << " " << order[i].s.f << " " << order[i].s.s << endl;
			// cout << "STORE OUT" << endl;

			for(auto it:order)
				{
					// cout << "OPEN " << it.f.f << " " << it.f.s << " " << it.s.f << " " << it.s.s << endl;

					if(it.f.s == -1)
						{
							x = it.s.f;
							y = it.s.s;
							z = it.f.f;

							if(height[x] < height[y])
								{
									// cout << "UPDATING " << ind[y] << " " << ind[y] + subtree[y] - 1 << " WITH VALUE " << z << endl;
									update(1, 1, n, ind[y], ind[y] + subtree[y] - 1, z);
								}
							else
								{
									// cout << "UPDATING " << ind[x] << " " << ind[x] + subtree[x] - 1 << " WITH VALUE " << z << endl;
									update(1, 1, n, ind[x], ind[x] + subtree[x] - 1, z);
								}
						}
					else
						{
							x = it.s.f;
							y = it.s.s;
							// cout << "QUERYING " << ind[x] << " AND " << ind[y] << endl; 
							ans[it.f.s] = (query(1, 1, n, ind[x], ind[x]) ^ query(1, 1, n, ind[y], ind[y]));
							// cout << "RESULT OF LEFT QUERY " << query(1, 1, n, ind[x], ind[x]) << endl;
							// cout << "RESULT OF RIGHT QUERY " << query(1, 1, n, ind[y], ind[y]) << endl;
							// cout << "ANSWER OF QUERY " << ans[it.f.s] << endl;
						}

					// cout << "LAZY IN" << endl;
					// for(i = 1; i <= 4 * n; i++)
					// 	cout << lazy[i] << " ";
					// cout << endl;
					// cout << "LAZY OUT" << endl;

					// cout << "TREE IN" << endl;
					// for(i = 1; i <= 4 * n; i++)
					// 	cout << segtree[i] << " ";
					// cout << endl;
					// cout << "TREE OUT" << endl;
					// cout << "CLOSE" << endl;
				}

			for(i = 1; i <= q; i++)
				cout << ans[i] << endl;
		}
	return 0;
}