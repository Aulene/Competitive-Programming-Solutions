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

int a[307][307], dp[307][307];
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, q, u, v, w, ans;
			
		cin >> n;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++) cin >> a[i][j];
				
		cin >> q;

		while(q--)
			{
				cin >> u >> v >> w;

				a[u][v] = w;

				for(i = 1; i <= n; i++)
					for(j = 1; j <= n; j++)
						dp[i][j] = a[i][j];

				for(i = 1; i <= n; i++)
					for(j = 1; j <= n; j++)
						dp[i][j] = min(dp[i][j], min(dp[i][u] + w + dp[v][j], dp[i][v] + w + dp[u][j]));

				ans = 0;

				for(i = 1; i <= n; i++)
					for(j = i; j <= n; j++) ans += dp[i][j];

				cout << ans / 2 << " ";
			}

		return 0;
	}