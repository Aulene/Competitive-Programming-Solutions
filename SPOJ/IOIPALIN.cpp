#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

// int tab[5007][5007];
string s, rev;
int dpPrev[5007], dp[5007];

int lcs(int n)
{
	int i, j, k, ans = 1;
	int x = 0;

	rev = s;
	reverse(rev.begin(), rev.end());

	for(i = 0; i <= n; i++) dp[i] = dpPrev[i] = 0;
		
 	for(i = 0; i <= n; i++)
		{
			for(j = 0; j <= n; j++)
				{
					if(i == 0 || j == 0)
						dp[j] = 0;
					else if(s[i - 1] == rev[j - 1])
						{
							dp[j] = dpPrev[j - 1] + 1;
							// tab[i][j] = tab[i - 1][j - 1] + 1;
							// ans = max(ans, dp[j]);
						}
					else
						// tab[i][j] = 0;
						dp[j] = max(dpPrev[j], dp[j - 1]);
				}

			for(j = 0; j <= n; j++)
				dpPrev[j] = dp[j], dp[j] = 0;
		}
	
	return dpPrev[n];
}

signed main()
	{
		int n, i, t;
		cin >> t;

		while(t--) {
			cin >> s;
			n = s.size();
			cout << n - lcs(n) << endl;
		}
		
		return 0;
	}
