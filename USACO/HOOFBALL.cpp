#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[107];
int dp[107], ansx;
bool vis[107];

int dfs(int idx)
{
	if(vis[idx]) return 0;
	vis[idx] = 1;
	return dfs(dp[idx]);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		// sort(a + 1, a + n + 1);

		for(i = 1; i <= n; i++)
			{
				v = 100007;

				for(j = 1; j <= n; j++)
					if(i != j)
						{
							if(v > abs(a[i] - a[j]))
								{
									v = abs(a[i] - a[j]);
									dp[i] = j;
								}
							else if(v == abs(a[i] - a[j]))
								{
									if(j < dp[i]) dp[i] = j;
								}
						}
			}

		for(i = 1; i <= n; i++)
			cout << i << " " << dp[i] << endl;
			 
		int ans = 0;

		for(i = 1; i <= n; i++)
			{
				if(!vis[i]) 
					{
						dfs(i); 
						ans++;
						cout << i << endl;
					}
			}
		cout << ans << endl;
		return 0;
	}