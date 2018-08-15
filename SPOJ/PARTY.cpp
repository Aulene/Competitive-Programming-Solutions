#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

pair <int, int> vs[507];
int dp[107][507];
int n, m;

int recur(int idx, int budget, int fun)
{
	if(idx > n) return 0;
	
	if(dp[idx][budget] != -1) 
		return dp[idx][budget];

	int ans = recur(idx + 1, budget);

	if(budget >= vs[idx].f)	
		recur(idx + 1, budget - vs[idx].f, fun + vs[idx].s);

	return dp[idx][budget] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v;

		while(true)
			{
				cin >> n >> m;

				if(n == 0 && m == 0) break;

				for(i = 0; i < 107; i++)
					for(j = 0; j < 507; j++) dp[i][j] = -1;

				for(i = 0; i < m; i++) {
					cin >> u >> v;
					vs[i] = mp(u, v);
				}

				pair <int, int> ans = mp(0, 0);
				recur(0, n);

				for(i = 0; i < 107; i++)
					for(j = 0; j < 507; j++) {
						if(dp[i][j] > ans.f) {
							ans.f = dp[i][j];
							ans.s = j;
						}
						else if(dp[i][j] == ans.f) {
							if(j < ans.s) {
								ans.s = j;
							}
						}
					}

				cout << ans.s << " " << ans.f << endl;
			}

		return 0;
	}