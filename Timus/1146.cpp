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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[107][107], pref[107][107], dp[107][107];

int solve(int n)
{
	int ans = 0, sum;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) // (i, j) is (x1, y1), the starting point
			for(int k = i; k <= n; k++)
				for(int l = j; l <= n; l++) // (k, l) is (x2, y2), the ending point
					{
						// sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y2 - 1] + dp[x1 - 1][y1 - 1]
						sum = dp[k][l] - dp[i - 1][l] - dp[k][j - 1] + dp[i - 1][j - 1]; 
						ans = max(ans, sum);
					}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) cout << dp[i][j] << " "; cout << endl;
	}
	return ans;
}

int brute(int n)
{
	int ans = 0, sum;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = i; k <= n; k++)
				for(int l = j; l <= n; l++) {
					sum = 0;
					for(int x = i; x <= k; x++)
						for(int y = j; y <= l; y++) sum += a[x][y];
					ans = max(ans, sum);
				}

	return ans;
}

int solveBetter(int n)
{
	int ans = 0, sum;

	for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) pref[i][j] = pref[i][j - 1] + a[i][j];
		
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++) {
			sum = pref[1][j] - pref[1][i - 1];
			ans = max(ans, sum);

			for(int k = 2; k <= n; k++) {
				sum = pref[k][j] - pref[k][i - 1] + max(0, sum);
				ans = max(ans, sum);
			}
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, k, l, sum, u, ans = -1000007;

		cin >> n;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				cin >> a[i][j];

		cout << brute(n) << endl;
		cout << solve(n) << endl;
		cout << solveBetter(n) << endl;
		return 0;
	}