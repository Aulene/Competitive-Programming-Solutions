#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

int a[1007][1007], b[1007][1007], dp[1007][1007][3];
int n, m;

int recur(int i, int j, bool done)
{
	if(i > n || j > m) {
		if(!done) return -10000007;
		return 0;
	}

	if(dp[i][j][done] != -1) return dp[i][j][done];

	int ans = 0;

	if(done) {
		ans = a[i][j] + max(recur(i + 1, j, 1), recur(i, j + 1, 1));
	}
	else {
		ans = max(recur(i + 1, j, 1), recur(i, j + 1, 1));
		ans = max(ans, a[i][j] + max(recur(i + 1, j, 0), recur(i, j + 1, 0)));
	}

	return dp[i][j][done] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int u, q, v, i, j, x, y, ans;

		for(i = 0; i < 1007; i++)
			for(j = 0; j < 1007; j++) dp[i][j][0] = dp[i][j][1] = -1;

		cin >> n >> m;

		for(i = 1; i <= n; i++) 
			for(j = 1; j <= m; j++) cin >> a[i][j];
		
		for(i = 1; i <= n; i++) 
			for(j = 1; j <= m; j++) b[i][j] = a[i][m - j + 1];
		
		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) a[i][j] += b[i][j];

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) cout << a[i][j] << " "; cout << endl;
		}

		ans = recur(1, 1, 0);

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) cout << dp[i][j][0] << " "; cout << endl;
		} cout << endl;

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) cout << dp[i][j][1] << " "; cout << endl;
		} cout << endl;
		

		cout << ans << endl;

		return 0;   
	}