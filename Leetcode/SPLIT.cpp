#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int splitArray(vector<int>& nums, int m) 
{
	int i, j, k, u = 0, v, sum = 0, ans = 0;
	int n = nums.size();

	int dp[57][1007];
	int prefix[1007];

	for(i = 0; i < 1007; i++) 
		{
			prefix[i] = 0;
			for(j = 0; j < 57; j++) 
				dp[j][i] = INT_MAX;
		}

	for(i = 1; i <= n; i++) 
		prefix[i] = prefix[i - 1] + nums[i - 1];

	for(i = 1; i <= n; i++)
		dp[1][i] = prefix[i];

	for(i = 2; i <= m; i++) 
		{
			for(j = i; j <= n; j++)
				{
					for(k = i; k <= j; k++)
						{
							dp[i][j] = min(dp[i][j], max(prefix[j] - prefix[k - 1], dp[i - 1][k - 1]));

							// cout << i << " " << j << " " << k << endl;
							// cout << dp[i][j] << " " << prefix[j] - prefix[k - 1] << " " << dp[i - 1][k - 1] << endl;
							// cout << endl;
						}
				}
		}

	// for(i = 1; i <= m; i++) {
	// 	for(j = 1; j <= n; j++) cout << dp[i][j] << " "; cout << endl;
	// }
	
	ans = dp[m][n];

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		vector <int> vs;

		cin >> n >> m;
		for(i = 0; i < n; i++) cin >> u, vs.pb(u);
		cout << splitArray(vs, m) << endl;

		return 0;
	}