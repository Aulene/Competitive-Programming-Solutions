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

int a[200007];
int l[200007], r[200007];
 
struct node
{
	int val;
	node *l, *r;
 
	node *build(int start, int end)
		{
			if(start == end)
				val = 0;
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = 0;
				}
			return this;
		}
 
	node *update(int start, int end, int a, int b, int v)	
		{
			if(start == end) {
				val = v;
				return this;
			}

			if(start > b || end < a)
				return this;
 
			if(start >= a && end <= b) {
				val = v;
				l = l -> update(start, mid, a, b, v);
				r = r -> update(mid + 1, end, a, b, v);
			}
			
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
				return 0;
			else if(a > mid)
				return r -> query(mid + 1, end, a, b);
			return l -> query(start, mid, a, b);
		}
};


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++)
			{
				if(!l[a[i]]) l[a[i]] = i;
				r[a[i]] = i;
			}

		node *root = new node;
		root = root -> build(1, n);

		for(i = 1; i <= m; i++)
			{
				u = l[i], v = r[i];

				// cout << u << " " << v << endl;

				if(u == 0) continue;

				root = root -> update(1, n, u, v, i);
			}

		for(i = 1; i <= n; i++) 
			cout << root -> query(1, n, i, i) << " ";

		return 0;
	}