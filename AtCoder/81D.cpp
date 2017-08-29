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

int n;
int dp[57][7];
string s1, s2;

int recur(int i)
{
	if(i == n - 1)
		{
			if(s1[i] == s2[i])
				{
					dp[i][0] = 3;
					dp[i][1] = 0;
					return 3;
				}
			else
				{
					dp[i][0] = dp[i][1] = 0;
					return 0;
				}
		}
	else if(i == n - 2)
		{
			recur(i + 1);

			if(s1[i] == s1[i + 1] && s2[i] == s2[i + 1])
				{
					dp[i][0] = (2 * dp[i + 1][0]) % mod;
					dp[i][1] = 6;
				}
				
			return 0;
		}

	int ans = 0, ans1 = 0, ans2 = 0;

	if(s1[i] == s1[i + 1] && s2[i] == s2[i + 1])
		{
			// cout << i << " t1\n";

			recur(i + 2);

			if(s1[i + 2] == s2[i + 2])
				ans1 = 2 * dp[i + 2][0] % mod;

			if(s1[i + 2] == s1[i + 3] && s2[i + 2] == s2[i + 3])
				ans1 = (ans1 + 3 * dp[i + 2][1]) % mod;

			ans1 %= mod;
		}

	if(s1[i] == s2[i])
		{
			// cout << i << " t2\n";

			recur(i + 1);

			if(s1[i + 1] == s2[i + 1])
				ans2 = (2 * dp[i + 1][0]) % mod;

			if(s1[i + 1] == s1[i + 2] && s2[i + 1] == s2[i + 2])
				ans2 = (ans2 + dp[i + 1][1]) % mod;

			ans2 %= mod;
		}

	dp[i][0] = ans2;
	dp[i][1] = ans1;

	ans = (ans1 + ans2) % mod;
	// cout << i << " " << ans1 << " " << ans2 << endl;
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, ans;

		for(i = 0; i < 57; i++) 
			for(j = 0; j < 7; j++) 
				dp[i][j] = -1;

		cin >> n >> s1 >> s2;	
		recur(0);

		// for(i = 0; i < n; i++) 
		// 	{
		// 		for(j = 0; j < 2; j++) 
		// 			cout << dp[i][j] << " ";
		// 		cout << endl;
		// 	}

		ans = (dp[0][0] + dp[0][1]) % mod;
		cout << ans % mod << endl;

		return 0;
	}