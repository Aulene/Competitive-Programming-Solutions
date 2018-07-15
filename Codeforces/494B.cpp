#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[1007][1007]; // no of ways to create substring of j chars from first i chars

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s1, s2;
		int n, m, i, j, u, v;

		cin >> s1 >> s2;
		s1 = "0" + s1;
		s2 = "0" + s2;
		n = s1.size(), m = s2.size();

		dp[0][0] = 1;

		for(i = 1; i <= m; i++)
			{
				for(j = 1; j <= n; j++)
					{
						if(s2[i] == s1[j])
							{
								dp[i][j] 
							}
						else
							{
							
							}
					}
			}

		for(i = 1; i < n; i++)
			{
				for(j = 1; j < m; j++) cout << dp[i][j] << " "; cout << endl;
			}
		cout << dp[n][m] << endl;
		return 0;
	}