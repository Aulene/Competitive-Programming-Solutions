/*
ID: aussyle1
PROG: money
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n, m;
int a[27];
int dp[27][10007];

int recur(int idx, int m)
{
	if(m == 0)
		return dp[idx][m] = 1;

	if(idx > n) 
		return 0;

	if(dp[idx][m] != -1) return dp[idx][m];

	int ans = 0;

	for(int i = 0; ; i++) 
		{
			int u = m - a[idx] * i;
			if(u >= 0) ans += recur(idx + 1, u);
			else break;
		}

	return dp[idx][m] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		ifstream cin ("money.in");
		ofstream cout ("money.out");
		
		int i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 0; i < 27; i++)
			for(j = 0; j < 10007; j++) 
				dp[i][j] = -1;

		cout << recur(1, m) << endl;
 		return 0;
	}