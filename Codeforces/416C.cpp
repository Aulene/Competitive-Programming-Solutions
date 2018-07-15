#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <int, int> > vs;
int a[1007];
int dp[1007][1007]; // max profit from seating first i visitors in j tables

bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.s == b.s)
		return a.f > b.f;
	return a.s > b.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, c, p, i, j, u, v;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(u, v));	
			}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 0; i < n; i++) 
			cout << vs[i].f << " " << vs[i].s << endl;

		cin >> m;
		for(i = 1; i <= m; i++) cin >> a[i];

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= m; j++)
					{
						int ans = dp[i - 1][j];

						if(a[j] >= vs[i - 1].f)
							ans = max(ans, dp[i - 1][j - 1] + vs[i - 1].s);
						dp[i][j] = ans;
					}
			}

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= m; j++) cout << dp[i][j] << " ";
				cout << endl;
			}

		cout << dp[n][m] << endl;
		return 0;
	}