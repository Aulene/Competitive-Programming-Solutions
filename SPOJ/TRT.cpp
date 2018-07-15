#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[2007][2007];
int a[2007];
int n;

int recur(int i, int j)
{
	if(dp[i][j] != -1) return dp[i][j];
	if(i > j) return 0;

	int ans1, ans2, ans;
	ans1 = recur(i + 1, j) + (i + n - j) * a[i];
	ans2 = recur(i, j - 1) + (i + n - j) * a[j];
	ans = max(ans1, ans2);
	return dp[i][j] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j;

		memset(dp, -1, sizeof(dp));

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];
		cout << recur(1, n) << endl;

		return 0;
	}