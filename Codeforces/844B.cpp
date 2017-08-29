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

int a[57][57];
int dp[257][257];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, ans = 0, black, white;

		for(i = 0; i < 257; i++) dp[i][0] = 1;
		for(i = 1; i < 257; i++)
			for(j = 0; j < 257; j++)
				{
		            if (j == 0 || j == i)
		                dp[i][j] = 1;
		            else
		                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		        }

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				cin >> a[i][j];
		ans = n * m;

		for(i = 1; i <= n; i++)
			{
				white = black = 0;

				for(j = 1; j <= m; j++)
					if(a[i][j] == 0) white++;
					else black++;

				for(j = 2; j <= black; j++)
					ans += dp[black][j];
				for(j = 2; j <= white; j++)
					ans += dp[white][j];
			}

		for(i = 1; i <= m; i++)
			{
				white = black = 0;

				for(j = 1; j <= n; j++)
					if(a[j][i] == 0) white++;
					else black++;

				for(j = 2; j <= black; j++)
					ans += dp[black][j];
				for(j = 2; j <= white; j++)
					ans += dp[white][j];
			}

		cout << ans << endl;

		return 0;
	}	