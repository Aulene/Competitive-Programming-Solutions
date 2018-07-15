#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007];

struct node
{
	int val;
	node *l, *r;

	int merge(int a, int b)
		{
			int x = a + b;
			return x;
		}

	node* build(int start, int end)
		{
			if(start == end)
				val = a[start] * a[start];
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	node* updateInc(int start, int end, int x, int v)
		{
			if(start == end)
				{
					val.f = v;
					return this;
				}
			else if(x <= mid)
				l = l -> update(start, mid, x, v);
			else
				r = r -> update(mid + 1, end, x, v);

			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				{
					// cout << start << " " << end << endl;
					return val;
				}
			else if(end < a || start > b)
				return mp(-1e9, -1e9);
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int T, t, n, m, q, i, j, u, v, w;

		cin >> t;

		for(T = 1; T <= t; T++)
			{
				cin >> n >> m;

				for(i = 1; i <= n; i++) cin >> a[i];

				while(m--)
					{
						cin >> q;

						if(q == 0)
							{
								cin >> u >> v >> w;

							}
						else if(q == 1)
							{
								cin >> u >> v >> w;
							}
						else
							{
								cin >> u >> v;
							}
					}
			}

		return 0;
	}