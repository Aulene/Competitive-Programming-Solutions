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

int a[107], b[107];
int dp1[107][100007], dp2[107][100007];

int recur(int dp[][100007], int x[], int index, int k)
{
	if(k == 0) return 0;
	if(index == 0 || k < 0) return mod;
	if(dp[index][k] != -1) return dp[index][k];

	int ans = min(1 + recur(dp, x, index - 1, k - x[index]), recur(dp, x, index - 1, k));
	return dp[index][k] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, ans = mod;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];
		cin >> m;
		for(i = 1; i <= m; i++) cin >> b[i];

		for(i = 0; i < 107; i++)
			for(j = 0; j < 100007; j++) dp1[i][j] = dp2[i][j] = -1;
		
		for(i = 0; i <= 100000; i++)
			recur(dp1, a, n, i), recur(dp2, b, m, i);

		for(i = 1; i <= 100000; i++)
			ans = min(ans, dp1[n][i] + dp2[m][i]);


		if(ans >= mod || n == 0 || m == 0) cout << "impossible\n";
		else cout << ans << endl;
		return 0;
	}