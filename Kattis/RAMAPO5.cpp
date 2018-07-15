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

int tree[1000007], sz[1000007];

int root(int n)
{
	while(tree[n] != n)
		{
			tree[n] = tree[tree[n]];
			n = tree[n];
		}
	return n;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, q, i, j, x, y, rx, ry;
		char op;

		cin >> n >> q;

		for(i = 1; i <= n; i++) tree[i] = i, sz[i] = 1;

		while(q--)
			{
				cin >> op >> x >> y;

				if(op == '=')
					{
						rx = root(x), ry = root(y);
						if(sz[rx] < sz[ry])
							{
								sz[ry] += sz[rx];
								tree[rx] = tree[ry]; 
							}
						else
							{
								sz[rx] += sz[ry];
								tree[ry] = tree[rx];
							}
					}
				else
					{
						if(root(x) == root(y)) cout << "yes\n";
						else cout << "no\n";
					}
			}
		return 0;
	}