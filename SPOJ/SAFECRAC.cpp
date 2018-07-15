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

int dp[100007][17], dp2[100007]; // passcode with i digits ending at j

int sum(int n)
{
	int ans = 0;
	for(int i = 0; i < 10; i++) ans = (ans + dp[n][i]) % mod;
	return ans;
}

void compute(int i, int j)
{
	if(j == 0) dp[i][j] = dp[i - 1][7] % mod;
	if(j == 1) dp[i][j] = (dp[i - 1][2] + dp[i - 1][4]) % mod;
	if(j == 2) dp[i][j] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % mod;
	if(j == 3) dp[i][j] = (dp[i - 1][2] + dp[i - 1][6]) % mod;
	if(j == 4) dp[i][j] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % mod;
	if(j == 5) dp[i][j] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % mod;
	if(j == 6) dp[i][j] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % mod;
	if(j == 7) dp[i][j] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % mod;
	if(j == 8) dp[i][j] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % mod;
	if(j == 9) dp[i][j] = (dp[i - 1][6] + dp[i - 1][8]) % mod;
}

void ans()
{
	for(int i = 0; i < 10; i++) dp[1][i] = 1;

	for(int i = 2; i <= 100000; i++)
		for(int j = 0; j < 10; j++)
			compute(i, j);
	for(int i = 1; i < 100001; i++) dp2[i] = sum(i);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j;

		ans();

		cin >> t;

		while(t--)
			{
				cin >> n;
				cout << dp2[n] << endl;
				// for(int i = 0; i < 10; i++)
				// 	{
				// 		cout << i << " " << dp[n][i] << endl;
				// 	}
			}
		return 0;
	}