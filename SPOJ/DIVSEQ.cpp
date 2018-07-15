#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000009
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > vs(1007);
int dp[1007][1007];

void comp(int m)
{
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= sqrt(i); j++)
			if(i % j == 0) {
					if(j == sqrt(i)) vs[i].pb(j);
					else vs[i].pb(j), vs[i].pb(i / j);
				}
	
	for(int i = 1; i <= m; i++) {
		for(int j = 2; i * j <= m; j++) {
			vs[i].pb(i * j);
		}
	}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		comp(m);

		// for(int i = 1; i <= 10; i++) {
		// 	cout << i << " ";
		// 	for(j = 0; j < vs[i].size(); j++) cout << vs[i][j] << " "; cout << endl;
		// }

		for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= m; j++) {

					if(i == 1) dp[i][j] = 1;

					for(int k = 0; k < vs[j].size(); k++) {
						dp[i + 1][vs[j][k]] = (dp[i + 1][vs[j][k]] + dp[i][j]) % mod;
					}
				}
			}

		for(int i = 1; i <= m; i++) ans = (ans + dp[n][i]) % mod;

		cout << ans << endl;
	
 		return 0;
	}