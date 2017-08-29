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

int a[5007], prefix[5007], dp[5007][5007]; // best way to choose sums until i using j pairs

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, k, i, j;
		int u, ans = 0;

		cin >> n >> m >> k;

		for(i = 0; i < 5007; i++)
			for(j = 0; j < 5007; j++)
				dp[i][j] = 0;

		for(i = 1; i <= n; i++)
			cin >> a[i], prefix[i] = prefix[i - 1] + a[i];

		for(i = 1; i <= n; i++)
			if(i - m + 1 >= 1)
				dp[i][1] = max(dp[i - 1][1], prefix[i] - prefix[i - m]);

		for(i = 2; i <= k; i++)
			{
				for(j = 1; j <= n; j++)
					if(j - m >= 1)
						dp[j][i] = max(prefix[j] - prefix[j - m] + dp[j - m][i - 1], dp[j - 1][i]);
			}

		// for(i = 1; i <= k; i++)
		// 	{
		// 		for(j = 1; j <= n; j++)
		// 			cout << dp[j][i] << " ";
		// 		cout << endl;
		// 	}
		ans = dp[n][k];
		cout << ans << endl;
		return 0;
	}