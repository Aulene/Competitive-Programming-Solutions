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

int lazy[4 * 100007];

struct node
{
	int val;
	node *l, *r;

	int merge(int a, int b)
		{ return a + b; }

	node *build(int start, int end)
		{
			if(start == end)
				val = 0;
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	node *update(int start, int end, int a, int b, int v, int level)	
		{
			if(lazy[level] != 0)
				{
					val += (end - start + 1) * lazy[level];

					if(start != end)
						{
							lazy[2 * level] += lazy[level];
							lazy[2 * level + 1] += lazy[level];
						}

					lazy[level] = 0;
				}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b)
				{
					val += (end - start + 1) * v;

					if(start != end)
						{
							lazy[2 * level] += v;
							lazy[2 * level + 1] += v;
						}			

					return this;
				}

			l = l -> update(start, mid, a, b, v, 2 * level);
			r = r -> update(mid + 1, end, a, b, v, 2 * level + 1);
			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int start, int end, int a, int b, int level)
		{
			if(lazy[level] != 0)
				{
					val += (end - start + 1) * lazy[level];

					if(start != end)
						{
							lazy[2 * level] += lazy[level];
							lazy[2 * level + 1] += lazy[level];
						}

					lazy[level] = 0;
				}

			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return val;
			else
				return merge(l -> query(start, mid, a, b, 2 * level), r -> query(mid + 1, end, a, b, 2 * level + 1));
		}
};

	int query(int start, int end, int a, int b, int level)
		{
			if(lazy[level] != 0)
				{
					val += (end - start + 1) * lazy[level];

					if(start != end)
						{
							lazy[2 * level] += lazy[level];
							lazy[2 * level + 1] += lazy[level];
						}

					lazy[level] = 0;
				}

			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return tree[level];
			else
				return merge(l -> query(start, mid, a, b, 2 * level), r -> query(mid + 1, end, a, b, 2 * level + 1));
		}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, m, u, v, q, x, ans;

		cin >> t;

		while(t--)
			{
				memset(lazy, 0, sizeof(lazy));
				cin >> n >> m;

				node *root = new node;
				root = root -> build(1, n);

				while(m--)
					{
						cin >> q;

						if(!q)
							{
								cin >> u >> v >> x;
								root = root -> update(1, n, u, v, x, 1);
							}
						else
							{
								cin >> u >> v;
								ans = root -> query(1, n, u, v, 1);
								cout << ans << endl;
							}
					}
			}

		return 0;
	}