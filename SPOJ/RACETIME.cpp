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

int a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, i, j, u, v, q;
		char op;

		cin >> n >> q;
		for(i = 1; i <= n; i++) cin >> a[i];

		while(q--)
			{
				cin >> op;

				if(op == 'C')
					{
						int ans = 0;
						cin >> u >> v >> j;
						for(i = u; i <= v; i++)
							if(a[i] <= j) ans++;
						cout << ans << endl;
					}
				else
					{
						cin >> u >> v;
						a[u] = v;
					}
			}

		return 0;
	}