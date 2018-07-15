#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> des;
int a[100007], p[100007];
int ans = 0;

struct node
{
	int val;
	node *l, *r;

	// int merge(int a, int b)
	// 	{
	// 		int x;
	// 		x = 
	// 		return x;
	// 	}

	node* build(int start, int end)
		{
			if(start == end)
				val = 0;
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
				}
			return this;
		}

	node* update(int start, int end, int x, int v)
		{
			if(start == end)
				{
					val = a[start] +
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

		int n, i, j, u, v;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i], p[i] = p[i - 1] + a[i];
		for(i = 0; i < n; i++) cin >> u, des.pb(u);
		
		return 0;
	}