#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2

int x[100007], y[100007];

struct maxTree
{
	pair <int, int> val;
	maxTree *l, *r;

	pair <int, int> merge(pair <int, int> a, pair <int, int> b)
		{
			if(a.s > b.s) return a;
			return b;
		}

	maxTree* build(int a[], int start, int end)
		{
			if(start == end)
				{
					val.f = start;
					val.s = a[start];
				}
			else
				{
					l = new maxTree, r = new maxTree;
					l = l -> build(a, start, mid), r = r -> build(a, mid + 1, end);
					val = merge(l -> val, r -> val);
				}

			return this;
		}

	maxTree* update(int start, int end, int x, int v)
		{
			if(start == end)
				{
					val.s = v;
					return this;
				}
			else if(x <= mid)
				l = l -> update(start, mid, x, v);
			else
				r = r -> update(mid + 1, end, x, v);

			val = merge(l -> val, r -> val);
			return this;
		}

	pair <int, int> query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				return val;
			else if(end < a || start > b)
				return mp(0, -1e10);
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

struct minTree
{
	pair <int, int> val;
	minTree *l, *r;

	pair <int, int> merge(pair <int, int> a, pair <int, int> b)
		{
			if(a.s < b.s) return a;
			return b;
		}

	minTree* build(int a[], int start, int end)
		{
			if(start == end)
				{
					val.f = start;
					val.s = a[start];
				}
			else
				{
					l = new minTree, r = new minTree;
					l = l -> build(a, start, mid), r = r -> build(a, mid + 1, end);
					val = merge(l -> val, r -> val);
				}

			return this;
		}

	minTree* update(int start, int end, int x, int v)
		{
			if(start == end)
				{
					val.s = v;
					return this;
				}
			else if(x <= mid)
				l = l -> update(start, mid, x, v);
			else
				r = r -> update(mid + 1, end, x, v);

			val = merge(l -> val, r -> val);
			return this;
		}

	pair <int, int> query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				return val;
			else if(end < a || start > b)
				return mp(0, 1e10);
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		pair <int, int> maxv, minv, maxv2, minv2;
		int touchMyTralala;
		int ans1, ans2, ans3, ans;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			{
				cin >> u >> v;
				x[i] = u;
				y[i] = v;
			}

		minTree *minRootX = new minTree;
		minRootX = minRootX -> build(x, 1, n);
		maxTree *maxRootX = new maxTree;
		maxRootX = maxRootX -> build(x, 1, n);

		minTree *minRootY = new minTree;
		minRootY = minRootY -> build(y, 1, n);
		maxTree *maxRootY = new maxTree;
		maxRootY = maxRootY -> build(y, 1, n);

		
		while(m--)
			{
				cin >> u >> v;
				maxv = maxRootX -> query(1, n, u, v);
				minv = minRootX -> query(1, n, u, v);
				
				// bhenchod 
				// 2ndmax - min
				touchMyTralala = maxv.f;
				maxRootX = maxRootX -> update(1, n, touchMyTralala, -1e10);
				maxv2 = maxRootX -> query(1, n, u, v);

				ans1 = maxv2.s - minv.s;
				maxRootX = maxRootX -> update(1, n, touchMyTralala, maxv.s);

				// 2ndmin - max
				
				touchMyTralala = minv.f;
				minRootX = minRootX -> update(1, n, touchMyTralala, 1e10);
				minv2 = minRootX -> query(1, n, u, v);

				ans2 = maxv.s - minv2.s;
				minRootX = minRootX -> update(1, n, touchMyTralala, minv.s);

				ans = min(ans1, ans2);
				// cout << ans1 << " " << ans2 << endl;

				//Y FUCKCKCKCKKCK
				maxv = maxRootY -> query(1, n, u, v);
				minv = minRootY -> query(1, n, u, v);	

				touchMyTralala = maxv.f;
				maxRootY = maxRootY -> update(1, n, touchMyTralala, -1e10);
				maxv2 = maxRootY -> query(1, n, u, v);

				ans1 = maxv2.s - minv.s;
				maxRootY = maxRootY -> update(1, n, touchMyTralala, maxv.s);

				// 2ndmin - max

				touchMyTralala = minv.f;
				minRootY = minRootY -> update(1, n, touchMyTralala, 1e10);
				minv2 = minRootY -> query(1, n, u, v);

				ans2 = maxv.s - minv2.s;
				minRootY = minRootY -> update(1, n, touchMyTralala, minv.s);

				ans3 = min(ans1, ans2);
				
				ans = max(ans, ans3);
				cout << ans << endl;
			}

		return 0;
	}