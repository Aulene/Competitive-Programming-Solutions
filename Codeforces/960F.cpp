#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define mid (start + end) / 2
#define N 100000

struct node
{
	int val;
	int builtL, builtR = 0;

	node *l, *r;

	int merge(int a, int b)
		{
			int x = max(a, b);
			return x;
		}

	node* build(int start, int end)
		{
			builtL = builtR = val = 0;
			return this;
		}

	node* update(int start, int end, int x, int v)
		{
			if(start == end)
				{
					if(val == 0)
						val = v;
					return this;
				}

			if(x <= mid)
				{
					if(!builtL) {
						l = new node;
						l = l -> build(start, mid);
						builtL = 1;
					}

					l = l -> update(start, mid, x, v);
				}
			else
				{
					if(!builtR) {
						r = new node;
						r = r -> build(mid + 1, end);
						builtR = 1;
					}

					r = r -> update(mid + 1, end, x, v);
				}

			if(builtL && builtR) val = merge(l -> val, r -> val);
			else if(builtL) val = l -> val;
			else if(builtR) val = r -> val;
			else val = 0;

			return this;
		}

	int query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				return val;
			else if(end < a || start > b)
				return 0;
			else
				{
					if(builtL && builtR)
						return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
					else if(builtL) return l -> query(start, mid, a, b);
					else if(builtR) return r -> query(mid + 1, end, a, b);
					else return 0;
				}
		}
};

int a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, w, val, ans = 0;

		cin >> n >> m;

		node *root[n + 2];

		for(i = 0; i < n; i++) {
			root[i] = new node;
			root[i] = root[i] -> build(0, N - 1);
		}

		for(i = 0; i < m; i++) 
			{
				cin >> u >> v >> w;
				
				u--, v--;

				if(w == 0) val = 0;
				else val = root[u] -> query(0, N - 1, 0, w - 1);

				ans = max(ans, val + 1);
				root[v] = root[v] -> update(0, N - 1, w, val + 1);
			}

		cout << ans << endl;
		return 0;
	}