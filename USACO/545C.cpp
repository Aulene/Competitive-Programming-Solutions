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
vector <int> vs2;
int dp[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(u, v));
				vs2.pb(u);
			}

		for(i = vs.size() - 1; i >= 0; i--)
			{
				int idx = lower_bound(vs2.begin(), vs2.end(), vs[i].f + vs[i].s) - vs2.begin() + 1;
				dp[i] = max(dp[idx] + 1, dp[i + 1]);
			}

		cout << dp[0] << endl;
		return 0;
	}