#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define N 5007

int pal[N][N], dp[N][N];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, i, j, u, v;
	string s;

	cin >> s;
	n = s.size();

	for(i = 0; i < n; i++) pal[i][i] = dp[i][i] = 1;
	for(i = 0; i < n - 1; i++)
		if(s[i] == s[i + 1]) pal[i][i + 1] = pal[i + 1][i] = 1;

	for(i = 0; i < n; i++)
		{
			u = i + 1;

			for(j = i + 2; j < n; j++)
				{
					v = j - 1;

					if(s[i] == s[j])
						{
							if((u <= v && pal[u][v]) || (u > v)) { pal[i][j] = pal[j][i] = 1; }
						}
				}
		}

	// for(i = 0; i < n; i++)
	// 	{
	// 		for(j = 0; j < n; j++)
	// 			cout << pal[i][j] << " "; cout << endl;
	// 	} cout << endl;

	for(j = 2; j < n; j++)
		for(i = 0; i < n; i++)
			if(i + j - 1 < n)
				{
					// cout << "DP[" << i << "][" << i + j - 1 << "] = DP[" << i << "][" << i + j - 2 << "] + DP[" << i + 1 << "][" << i + j - 1 << "] - DP[" << i + 1 << "][" << i + j - 2 << "] + " << pal[i][i + j - 1] << endl; 
					// cout << "DP[" << i << "][" << i + j - 1 << "] = " << dp[i][i + j - 2] << " + " << dp[i + 1][i + j - 1] << " - " << dp[i + 1][i + j - 2] << " + " << pal[i][i + j - 1] << endl;
					dp[i][i + j - 1] = dp[i][i + j - 2] + dp[i + 1][i + j - 1] - dp[i + 1][i + j - 2] + pal[i][i + j - 1];
				}

	// for(i = 0; i < n; i++)
	// 	{
	// 		for(j = 0; j < n; j++)
	// 			cout << dp[i][j] << " "; cout << endl;
	// 	}

	cin >> m;

	for(i = 0; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		cout << dp[u][v] << endl;
	}
	return 0;
}