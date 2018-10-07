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
#define mid (start + end) / 2
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

int a[1000007];

// int lazy0[4 * 100007], lazy1[4 * 100007], lazy2[4 * 100007];
int lazy[4 * 100007];

struct RangeSTreeLazy
{
	pair < pair <int, int>, int> val;

	RangeSTreeLazy *l, *r;

	pair < pair <int, int>, int> merge(pair < pair <int, int>, int> a, pair < pair <int, int>, int> b) 
		{ return mp(mp(a.f.f + b.f.f, a.f.s + b.f.s), a.s + b.s); }

	RangeSTreeLazy *build(int start, int end)
		{
			if(start == end) { val = {{0, 0}, end - start + 1}; }
			else
				{
					l = new RangeSTreeLazy, r = new RangeSTreeLazy;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	RangeSTreeLazy *update(int lazy[], int start, int end, int a, int b, int level = 1)	
		{
			if(lazy[level])
				{	
					if(start != end)
						{
							lazy[2 * level] += lazy[level];
							lazy[2 * level + 1] += lazy[level];
						}

					lazy[level] %= 3;

					while(lazy[level]--)
						{
							pair < pair <int, int>, int> np = {{val.s, val.f.f}, val.f.s};
							val = np;
						}
				}

			lazy[level] = 0;

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b)
				{
					pair < pair <int, int>, int> np = {{val.s, val.f.f}, val.f.s};
					val = np;

					if(start != end)
						{
							lazy[2 * level]++;
							lazy[2 * level + 1]++;
						}			

					return this;
				}

			l = l -> update(lazy, start, mid, a, b, 2 * level);
			r = r -> update(lazy, mid + 1, end, a, b, 2 * level + 1);
			val = merge(l -> val, r -> val);
			return this;
		}

	pair < pair <int, int>, int> query(int lazy[], int start, int end, int a, int b, int level = 1)
		{
			if(lazy[level])
				{
					// cout << level << " is absolutely fucked.\n"; 
					
					if(start != end)
						{
							lazy[2 * level] += lazy[level];
							lazy[2 * level + 1] += lazy[level];
						}

					lazy[level] %= 3;

					while(lazy[level]--)
						{
							pair < pair <int, int>, int> np = {{val.s, val.f.f}, val.f.s};
							val = np;
						}
				}

			lazy[level] = 0;

			if(start > b || end < a)
				return mp(mp(0, 0), 0);
			else if(start >= a && end <= b)
				return val;
			else
				return merge(l -> query(lazy, start, mid, a, b, 2 * level), r -> query(lazy, mid + 1, end, a, b, 2 * level + 1));
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, u, v, i, j, x, y, ans;
		int nx, ny, nz;

		// cin >> n >> m;
		scanf("%d %d", &n, &m);

		// RangeSTreeLazy *tree0 = new RangeSTreeLazy;
		// RangeSTreeLazy *tree1 = new RangeSTreeLazy;
		// RangeSTreeLazy *tree2 = new RangeSTreeLazy;
		// tree0 = tree0 -> build(1, n, 1);
		// tree1 = tree1 -> build(1, n);
		// tree2 = tree2 -> build(1, n);

		RangeSTreeLazy *root = new RangeSTreeLazy;
		root = root -> build(0, n - 1);

		while(m--)
			{
				scanf("%d %d %d", &q, &u, &v);
				// cin >> q >> u >> v;

				if(q == 0) {
					root = root -> update(lazy, 0, n - 1, u, v);
					ppi ans = root -> query(lazy, 0, n - 1, 0, n - 1);
					// cout << ans.f.f << " " << ans.f.s << " " << ans.s << endl;
				}
				else {
					ppi ans = root -> query(lazy, 0, n - 1, u, v);
					// cout << ans.f.f << " " << ans.f.s << " " << ans.s << endl;
					printf("%d\n", ans.s);
				}
			}

		return 0;
	}