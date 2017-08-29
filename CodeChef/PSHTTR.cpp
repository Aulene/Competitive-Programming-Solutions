// Segtree code adapted from https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/ and http://se7so.blogspot.in/2012/12/segment-trees-and-lazy-propagation.html

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
#define mp make_pair
#define s second
#define f first

lli vs[100007], height[100007];
lli subtree[100007];
lli segtree[400027], lazy[400027];
lli ans[100007];
vector < pair<lli, lli> > g[100007];
vector <lli> o;
vector< pair <pair <lli, lli>, pair<lli, lli> > > order;

void dfs1(lli u, lli p)
{
	if(p != -1)
		height[u] = height[p] + 1;

	for(lli i = 0; i < g[u].size(); i++)
		{
			lli x = g[u][i].f;
			
			if(x == p)
				continue;
			
			dfs1(x, u);
		}
}

void dfs(lli u, lli p)
{
	o.pb(u);
	subtree[u] = 1;

	for(lli i = 0; i < g[u].size(); i++)
		{
			lli v = g[u][i].f;

			if(v != p)
				{
					dfs(v, u);
					subtree[u] += subtree[v];
				}			
		}
}

void update(lli node, lli a, lli b, lli l, lli r, lli val)
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
			
			if(a != b)
				{
					lazy[2 * node] ^= val;
					lazy[2 * node + 1] ^= val;
				}

			return;
		}

	lli mid = (a + b) / 2;
	update(2 * node, a, mid, l, r, val);
	update(2 * node + 1, mid + 1, b, l, r, val);
	segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
}

lli query(lli node, lli a, lli b, lli l, lli r)
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
		return 0;

	if(a >= l && b <= r)
		return segtree[node];

	lli mid = (a + b) / 2;

	// return query(2 * node, a, mid, l, r) ^ query(2 * node + 1, mid + 1, b, l, r);
	return max(query(2 * node, a, mid, l, r), query(2 * node + 1, mid + 1, b, l, r));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	lli i, j, n, t, x, y, z, q;

	scanf("%lld", &t);
	
	while(t--)
		{
			scanf("%lld", &n);

			for(i = 0; i <= n; i++)
				g[i].clear();

			for(i = 0; i < 400027; i++)
				{
					segtree[i] = 0;
					lazy[i] = 0;
				}

			for(i = 0; i < 100007; i++)
				ans[i] = 0;

			order.clear();
			o.clear();

			for(i = 1; i <= n - 1; i++)
				{
					scanf("%lld %lld %lld", &x, &y, &z);

					g[x].pb(mp(y, z));
					g[y].pb(mp(x, z));
					order.pb(mp(mp(z, -1),mp(x, y)));
				}

			scanf("%lld", &q);

			for(i = 1; i <= q; i++)
				{
					scanf("%lld %lld %lld", &x, &y, &z);
					order.pb(mp(mp(z, i),mp(x, y)));
				}

			sort(order.begin(), order.end());
			
			dfs1(1, -1);
			o.pb(-1);
			dfs(1, -1);

			for(i = 1; i <= n; i++) vs[o[i]] = i;

			for(auto it:order)
				{
					if(it.f.s == -1)
						{
							x = it.s.f;
							y = it.s.s;
							z = it.f.f;

							if(height[x] < height[y])
								update(1, 1, n, vs[y], vs[y] + subtree[y] - 1, z);
							else
								update(1, 1, n, vs[x], vs[x] + subtree[x] - 1, z);
						}
					else
						{
							x = it.s.f;
							y = it.s.s;

							ans[it.f.s] = (query(1, 1, n, vs[x], vs[x]) ^ query(1, 1, n, vs[y], vs[y]));
						}
				}

			for(i = 1; i <= q; i++)
				printf("%lld\n", ans[i]);
		}
	return 0;
}