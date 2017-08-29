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

int a[45007];

struct node
{
	pair <int, int> val;
	node *l, *r;

	pair <int, int> merge(pair <int, int> a, pair <int, int> b)
		{
			pair <int, int> x;
			x.f = max(a.f, b.f);
			x.s = max(min(a.f, b.f), max(a.s, b.s));
			return x;
		}

	node* build(int start, int end)
		{
			if(start == end)
				{
					val.f = a[start];
					val.s = -1e9;
					// cout << start << " " << val.f << " " << val.s << endl;
				}
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
					// cout << start << " " << end << " " << val.f << " " << val.s << endl;
				}
			return this;
		}

	node* update(int start, int end, int x, int v)
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

	pair <int, int> query(int start, int end, int a, int b)
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

node tree[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i;

		cin >> n;

		for(i = 0; i < n; i++)
			cin >> a[i];

		node *root = new node;
		root = build(1, 1);
		
		return 0;
	}