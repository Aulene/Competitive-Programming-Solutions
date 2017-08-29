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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2

int a[200007];

struct node
{
	int val;
	node *l, *r;

	int merge(int a, int b) {return min(a, b);}

	node* build(int start, int end)
		{
			if(start == end)
				{
					val = a[start];
					return this;
				} 

			l = new node, r = new node;
			l = l -> build(start, mid), r = r -> build(mid + 1, end);
			val = merge(l -> val, r -> val);
			return this;
		}	

	node* update(int start, int end, int a, int b, int x)
		{
			if(a > end || b < start)
				return this;

			if(start == end)
				{
					val += x;
					return this;
				}

			if(mid >= end) l = l -> update(start, mid, a, b, x);
			else if(mid < start) r = r -> update(mid + 1, end, a, b, x);
			else l = l -> update(start, mid, a, b, x), r = r -> update(mid + 1, end, a, b, x);

			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				return val;
			else if(start > b || end < a)
				return 10000007;
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, m, u, v, x, ans;
		char c;

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		cin >> m;

		node *root = new node;
		root = root -> build(1, n);

		while(m--)
			{
				scanf("%d %d%c", &u, &v, &c);

				u++, v++;

				if(c != '\n')
					{
						cin >> x;

						// cout << "update" << endl;
						if(v < u)
							{
								root = root -> update(1, n, u, n, x);
								root = root -> update(1, n, 1, v, x);
							}
						else
							root = root -> update(1, n, u, v, x);
					}
				else
					{
						// cout << "query" << endl;
						if(v < u) ans = min(root -> query(1, n, u, n), root -> query(1, n, 1, v));
						else ans = root -> query(1, n, u, v);
						cout << ans << endl;
					}
			}
		return 0;
	}