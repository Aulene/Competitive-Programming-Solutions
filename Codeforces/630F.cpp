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

int dp[807][807];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans;

		cin >> n;

		for(i = 1; i < 807; i++) dp[i][1] = i;

		for(i = 2; i < 807; i++)
			for(j = 2; j < 807; j++)
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

		// cout << dp[n][5] << " " << dp[n][6] << " " << dp[n][7] << endl; 
		ans = dp[n][5] + dp[n][6] + dp[n][7];
		cout << ans << endl;

		return 0;
	}