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
	pair < pair <int, int> , pair <int, int> > val; //prefixmax, suffixmax, insidemax, suminside
	node *l, *r;

	pair < pair <int, int> , pair <int, int> > merge(pair < pair <int, int> , pair <int, int> > a, pair < pair <int, int> , pair <int, int> > b)
		{
			pair < pair <int, int> , pair <int, int> > x;
			x.f.f = max(a.f.f, a.s.s + b.f.f);
			x.f.s = max(a.f.s + b.s.s, b.f.s);
			x.s.s = a.s.s + b.s.s;
			x.s.f = max(b.s.f, a.f.s + b.f.f);
			x.s.f = max(x.s.f, a.s.f);
			x.s.f = max(x.s.f, x.f.s);
			x.s.f = max(x.s.f, x.f.f);
			return x;
		}

	node* build(int start, int end)
		{
			if(start == end)
				{
					val.f.f = val.f.s = val.s.f  = val.s.s = a[start];
				}
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}

			return this;
		}

	pair < pair <int, int> , pair <int, int> > query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				{
					// cout << start << " " << end << endl;
					return val;
				}
			else if(end < a || start > b)
				return mp(mp(-1e9, -1e9), mp(-1e9, -1e9));
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, u, v;
		pair < pair <int, int> , pair <int, int> > ans;

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		node *root = new node;
		root = root -> build(1, n);

		cin >> m;

		while(m--)
			{
				cin >> u >> v;
				ans = root -> query(1, n, u, v);
				cout << ans.s.f << endl;
			}
		return 0;
	}