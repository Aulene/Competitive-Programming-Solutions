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
#define mid (start + end) / 2

int a[50007];

struct node
{
	pair < pair <int, int>, pair <int, int> > val; // presum, sufsum, mainsum, anssum
	node *l, *r;

	pair < pair <int, int>, pair <int, int> > merge(pair < pair <int, int>, pair <int, int> > a, pair < pair <int, int>, pair <int, int> > b)
		{
			pair < pair <int, int>, pair <int, int> > x;

			x.f.f = max(a.f.f, a.s.f + b.f.f);
			x.f.s = max(a.f.s + b.s.f, b.f.s);
			x.s.f = a.s.f + b.s.f;

			x.s.s = max(a.s.s, b.s.s);
			x.s.s = max(x.s.s, x.f.f);
			x.s.s = max(x.s.s, x.f.s);
			x.s.s = max(x.s.s, x.s.f);
			x.s.s = max(x.s.s, a.f.s + b.f.f);
			return x;
		}

	node *build(int start, int end)
		{
			if(start == end)
				val.f.f = val.f.s = val.s.f = val.s.s = a[start];
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);					
				}
			return this;
		} 

	node *update(int start, int end, int u, int v)
		{
			if(start == end)
				{
					val.f.f = val.f.s = val.s.f = val.s.s = v;
					return this;
				}
			else if(u <= mid)
				l = l -> update(start, mid, u, v);
			else
				r = r -> update(mid + 1, end, u, v);

			val = merge(l -> val, r -> val);
			return this;
		}

	pair < pair <int, int>, pair <int, int> > query(int start, int end, int a, int b)
		{
			if(end < a || start > b)
				return mp(mp(-1e9, -1e9), mp(-1e9, -1e9));
			else if(start >= a && end <= b)
				return val;
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}

};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, q, u, v;
		pair < pair <int, int>, pair <int, int> > ans;

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		cin >> m;

		node *root = new node;
		root = root -> build(1, n);

		while(m--)
			{
				cin >> q >> u >> v;

				if(!q)
					root = root -> update(1, n, u, v);
				else
					ans = root -> query(1, n, u, v), cout << ans.s.s << endl;
			}
		return 0;
	}