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

int a[100007], ans[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, i, j, u, v, x, y, z;

		cin >> n >> m;
		for(i = 1; i <= n; i++) cin >> a[i];

		while(m--)
			{
				cin >> q;

				if(q == 1)
					{
						 cin >> u >> v;

						 x = ans[u], y = u;
						 z = a[u] + x;

						 for(i = u + 1; i <= n; i++)
						 	{
						 		x += ans[i];
						 		if((i - y > 100) || !v) break;
						 		if(a[i] + x > z)
						 			{
						 				z = a[i] + x;
						 				y = i;
						 				v--;
						 			}
						 	}

						 cout << y << endl;
					}
				else
					{
						cin >> u >> v >> j;
						ans[u] += j, ans[v + 1] -= j;
					}
			}
		return 0;
	}