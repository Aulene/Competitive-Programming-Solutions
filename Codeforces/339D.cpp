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

int a[150007], N;

struct node
{
	int val;
	node *l, *r;

	int merge(int a, int b, int level) 
		{ 
			int x;

			if(N % 2 == 1)
				{
					if(level % 2 == 1) x = a | b;
					else x = a ^ b;
				}
			else
				{
					if(level % 2 == 0) x = a | b;
					else x = a ^ b;
				}

			return x;
		}

	node* build(int start, int end, int level)
		{
			if(start == end)
				val = a[start];
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid, level + 1), r = r -> build(mid + 1, end, level + 1);
					val = merge(l -> val, r -> val, level);
				}

			return this;
		}

	node* update(int start, int end, int u, int v, int level)
		{
 			if(start == end)
				{
					val = v;
					return this;
				}
			else if(u <= mid) l = l -> update(start, mid, u, v, level + 1);
			else r = r -> update(mid + 1, end, u, v, level + 1);

			val = merge(l -> val, r -> val, level);
			return this;
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, q, i, j, u, v, ans;

		cin >> N >> q;
		n = pow(2, N);

		for(i = 1; i <= n; i++)
			cin >> a[i];

		node *root = new node;
		root = root -> build(1, n, 1);

		while(q--)
			{
				cin >> u >> v;
				root -> update(1, n, u, v, 1);
				cout << root -> val << endl;
			}
		return 0;
	}