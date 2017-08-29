#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define int long long int
#define mod 1000000007
#define inf 100000000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[1007], b[2007];
int dp[1007][2007];

signed main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, p, last, i, j;
	int ans = 100000000000007;

	cin >> n >> k >> p;

	for(i = 1; i <= n; i++)
		cin >> a[i];
	
	for(i = 1; i <= k; i++)
		cin >> b[i];

	sort(a + 1, a + n + 1);
	sort(b + 1, b + k + 1);

	for(i = 0; i < 1007; i++)
		for(j = 0; j < 2007; j++)
			dp[i][j] = inf;

	for(i = 0; i < 2007; i++)
		dp[0][i] = 0;

	for(i = 1; i <= n; i++)
		for(j = 1; j <= k; j++)
			dp[i][j] = max(min(dp[i][j - 1], abs(a[i] - b[j]) + abs(p - b[j])), dp[i - 1][j - 1]);

	// for(i = 1; i <= n; i++)
	// 	{
	// 		for(j = 1; j <= k; j++)
	// 			cout << dp[i][j] << " ";
	// 		cout << endl;
	// 	}

	ans = dp[n][k];

	cout << ans << endl;

	return 0;
}