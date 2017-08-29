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

int lazy[400007];

struct node
{
	int val;
	node *l, *r;

	int merge(int a, int b) { return a + b; }

	node* build(int start, int end)
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

	node* update(int start, int end, int a, int b, int level)
		{
			if(lazy[level])
				{
					val = end - start + 1 - val;

					if(start != end)
						{
							lazy[2 * level] = (lazy[2 * level] + lazy[level]) % 2;
							lazy[2 * level + 1] = (lazy[2 * level + 1] + lazy[level]) % 2;
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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		int n, m, u, v, i, j;

		cin >> n >> m;

		node *root = new node;
		root = root -> build(1, n);

		while(m--)
			{
				cin >> u >> v >> j;
			
				if(u == 0) root = root -> update(1, n, v, j, 1);
				else cout << root -> query(1, n, v, j, 1) << endl;
			}

		return 0;
	}