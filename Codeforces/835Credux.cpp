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

int stars[105][105][11];
int dp[105][105][11];

signed main() 
{
	int n, q, c, t, x1, x2, y1, y2, ans, i, j, k;
	int u, v, lol;

	cin >> n >> q >> c;

	for(i = 0; i < n ;i++ )
		{
			cin >> u >> v >> lol;
			for(k = 0; k <= c; k++)
				stars[u][v][k] += (lol + k) % (c + 1);
		}

	for(k = 0; k <= c; k++)
		dp[0][0][k] = stars[0][0][k];

	for(i = 1; i <= 101; i++)
		for(k = 0; k <= c; k++)
			dp[i][0][k] = stars[i][0][k] + dp[i - 1][0][k];

	for(j = 1; j <= 101; j++)
		for(k = 0; k <= c; k++)
			dp[0][j][k] = stars[0][j][k] + dp[0][j - 1][k];

	for(i = 1; i <= 101; i++)
		for(j = 1; j <= 101; j++)
			for(k = 0; k <= c; k++)
				dp[i][j][k]= dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k] + stars[i][j][k];

	while(q--)
		{
			cin >> t >> x1 >> y1 >> x2 >> y2;
			t = t % (c + 1);
			ans = dp[x2][y2][t] - dp[x2][y1 - 1][t] - dp[x1 - 1][y2][t] + dp[x1 - 1][y1 - 1][t];
			cout << ans << endl;
		}

	return 0;
}