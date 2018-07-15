#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[3007], b[3007], c[3007];
int dp[3007][7];
int n;

int recur(int idx, bool prev)
{
	int ans1, ans2;

	if(idx == n) {
		if(prev) return b[idx];
		return a[idx];
	}
	
	if(dp[idx][prev] != -1) return dp[idx][prev];

	if(prev) {
		ans1 = recur(idx + 1, 1) + b[idx];
		ans2 = recur(idx + 1, 0) + c[idx];
	}
	else {
		ans1 = recur(idx + 1, 1) + a[idx];
		ans2 = recur(idx + 1, 0) + b[idx];
	}

	return dp[idx][prev] = max(ans1, ans2);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int m, i, j, u, v;

		cin >> n;

		for(i = 0; i < 3007; i++)
			for(j = 0; j < 7; j++) dp[i][j] = -1;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= n; i++) cin >> b[i];
		for(i = 1; i <= n; i++) cin >> c[i];
		
		cout << recur(1, 0) << endl;

		return 0;
	}