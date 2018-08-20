#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[107][107][107];
int n, m;

int recur(int idx, int shares, int prev)
{
	if(dp[idx][shares][prev] != -1) 
		return dp[idx][shares][prev];

	if(shares == 0) 
		{
			// cout << idx << " " << shares << " " << prev << " " << 1 << endl;
			return dp[idx][shares][prev] = 1;
		}

	if(idx > n) return 0;

	int ans = 0;

	if(idx == 1)
		{
			for(int i = 0; i <= shares; i++)
				ans = ans + recur(idx + 1, shares - i, i);
		}
	else
		{
			for(int i = 0; i <= min(shares, prev - 1); i++)
				ans = ans + recur(idx + 1, shares - i, i);
		}

	// cout << idx << " " << shares << " " << prev << " " << ans << endl;

	return dp[idx][shares][prev] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, i, j, k, u, v, ans;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 107; i++)
					for(j = 0; j < 107; j++) 
						for(k = 0; k < 107; k++) dp[i][j][k] = -1;

				cin >> m >> n;
				ans = recur(1, m, -1);
				cout << ans << endl;
			}

		return 0;
	}