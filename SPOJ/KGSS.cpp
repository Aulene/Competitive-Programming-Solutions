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
#define p push
#define pb push_back
#define mp make_pair
#define mid (start + end) / 2
#define f first
#define s second

int a[200007];

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

int main()
	{
		int n, i, j, k, m;
		pair <int, int> ans;
		char c;

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		node *root = new node;
		root = root -> build(1, n);

		cin >> m;

		while(m--)
			{
				cin >> c >> i >> j;

				if(c == 'U')
					{
						root = root -> update(1, n, i, j);
					}
				else
					{
						ans = root -> query(1, n, i, j);
						cout << ans.f + ans.s << endl;
					}
			}

		return 0;
	}