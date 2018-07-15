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

int a[107][507], dp[107][507];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, ans = 10000000007;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) cin >> a[i][j];

		for(i = 1; i <= m; i++) dp[n][i] = a[n][i];

		for(i = n - 1; i >= 1; i--)
			{
				for(j = 1; j <= m; j++)
					{
						if(j == 1) dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
						else if(j == m) dp[i][j] = min(dp[i + 1][j - 1], dp[i + 1][j]) + a[i][j];
						else dp[i][j] = min(dp[i + 1][j], min(dp[i + 1][j + 1], dp[i + 1][j - 1])) + a[i][j];
					}
			}

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= m; j++)
					cout << dp[i][j] << " ";
				cout << endl;
 			}
		
		for(i = 1; i <= m; i++) ans = min(ans, dp[1][i]);

		cout << ans << endl;
		
		return 0;
	}