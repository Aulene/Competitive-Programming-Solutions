#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[1007][1007][2];
int a[1007];
int n;

int recur(int i, int j, bool k)
{
	if(dp[i][j][k] != -1) return dp[i][j][k];
	if(i > j) return 0;

	int ans = 0;

	if(k)
		{
			if(a[i] >= a[j]) ans = recur(i + 1, j, 0) - a[i];
			else ans = recur(i, j - 1, 0) - a[j];
		}
	else
		{
			ans = recur(i + 1, j, 1) + a[i];
			ans = max(ans, recur(i, j - 1, 1) + a[j]);
		}

	return dp[i][j][k] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, ans, t = 1;

		while(cin >> n)
			{
				if(!n) break;

				for(i = 0; i < 1007; i++)
					for(j = 0; j < 1007; j++) dp[i][j][0] = dp[i][j][1] = -1;

				for(i = 1; i <= n; i++) cin >> a[i];

				ans = recur(1, n, 0);
				printf("In game %lld, the greedy strategy might lose by as many as %lld points.\n", t, ans);

				t++;
			}

		return 0;
	}