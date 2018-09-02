#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

string s1, s2;
int dp[5007][5007];

int recur(int n, int m)
{
	if(n == 0) return m;
	if(m == 0) return n;

	if(dp[n][m] != -1) return dp[n][m];

	if(s1[n - 1] == s2[m - 1]) return dp[n][m] = recur(n - 1, m - 1);

	int ans = 1 + min(recur(n - 1, m), min(recur(n, m - 1), recur(n - 1, m - 1)));
	return dp[n][m] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, n, m, i, j, u, v, ans;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 5007; i++)
					for(j = 0; j < 5007; j++) dp[i][j] = -1;
						
				cin >> s1 >> s2;
				n = s1.size(), m = s2.size();
				ans = recur(n, m);
				cout << ans << endl;
			}

		return 0;
	}