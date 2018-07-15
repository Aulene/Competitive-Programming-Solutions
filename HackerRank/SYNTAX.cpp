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

int a[200007], lazy[400007];

struct node
{
	int val;
	node *l, *r;

	int merge(int a, int b) { return a + b; }

	node* build(int start, int end)
		{
			if(start == end)
				val = a[start];
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}

			return this;
		}

	node* update(int start, int end, int a, int b, int level)
		{
			if(lazy[level])
				{
					val = end - start + 1 - val;

					if(start != end)
						{
							lazy[2 * level] = (lazy[2 * level] + 1) % 2;
							lazy[2 * level + 1] = (lazy[2 * level + 1] + 1) % 2;
						}

					lazy[level] = 0;
				}

			if(end < a || start > b) 
				return this;

			if(start >= a && end <= b)
				{
					val = end - start + 1 - val;

					if(start != end)
						{
							lazy[2 * level] = (lazy[2 * level] + 1) % 2;
							lazy[2 * level + 1] = (lazy[2 * level + 1] + 1) % 2;
						}			

					return this;
				}

			l = l -> update(start, mid, a, b, 2 * level);
			r = r -> update(mid + 1, end, a, b, 2 * level + 1);
			val = merge(l -> val, r -> val);

			return this;
		}	

	int query(int start, int end, int a, int b, int level)
		{
			if(lazy[level] != 0)
				{
					val = end - start + 1 - val;

					if(start != end)
						{
							lazy[2 * level] = (lazy[2 * level] + lazy[level]) % 2;
							lazy[2 * level + 1] = (lazy[2 * level + 1] + lazy[level]) % 2;
						}

					lazy[level] = 0;
				}

			if(start >= a && end <= b) 
				return val;
			else if(end < a || start > b) 
				return 0;
			else
				return merge(l -> query(start, mid, a, b, 2 * level), r -> query(mid + 1, end, a, b, 2 * level + 1));
		}
};

node tree[100007];
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, w;
		int p = 0, q = 0;
		string s;

		cin >> n >> m >> s;

		for(i = 0; i < n - 1; i++)
			{
				if(s[i] == '>') a[i + 1] = 1;
				else a[i + 1] = 0;
			}

		node *root = new node;
		root = root -> build(1, n - 1);

		while(m--)
			{
				cin >> u >> v >> w;

				if(u == 1)
					{
						root = root -> update(1, n - 1, v, w - 1, 1);
					}
				else
					{
						int ans = 0;

						if(w > v) 
							{
								ans = root -> query(1, n - 1, v, w - 1, 1);
								ans = (w - v) - ans;
							}
						else
							{
								ans = root -> query(1, n - 1, w, v - 1, 1);
								// ans = n - 1 - ans;
							}

						cout << ans << endl;
					}

				// cout << p << " " << q << endl;
			}
		return 0;
	}