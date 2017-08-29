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

double dp[1007][1007]; bool x[1007][1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, q;
		double ad = sqrt(20000);

		cin >> n >> m >> q;

		while(q--) { cin >> u >> v;  x[u][v] = 1; }

		for(i = 1; i < 1007; i++)
			dp[0][i] = dp[i][0] = 100 * i;
		
		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				{
					dp[i][j] = 100 + min(dp[i - 1][j], dp[i][j - 1]);
					if(x[i][j]) dp[i][j] = min(dp[i][j], ad + dp[i - 1][j - 1]);
				}

		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 1; j <= m; j++) 
		// 			cout << dp[i][j] << " "; 
		// 		cout << endl;
		// 	}

		cout << (int) round(dp[n][m]) << endl;

		return 0;
	}