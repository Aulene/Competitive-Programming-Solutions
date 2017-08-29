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

int a[1000007];
bool lazy[4000007];

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
					val = merge(l -> val, r -> val);
				}

			return this;
		}

	node* update(int start, int end, int a, int b, int level)
		{
			if(lazy[level])
				{
					if(start != end)
						{
							lazy[2 * level] = 1;
							lazy[2 * level + 1] = 1;
						}
						
					lazy[level] = 1;
				}
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, u, v, i, j;

		cin >> n >> m;

		while(m--)
			{
				cin >> q >> u >> v;

			}

		return 0;
	}