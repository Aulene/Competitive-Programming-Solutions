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

vvi vs(4007);
vi E;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v;
		pair <int, int> pz;

		cin >> n;

		for(i = 0; i < n; i++)
			for(j = 0; j < 4; j++)
				{
					cin >> u;
					vs[j].pb(u);
				}

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				E.pb(vs[2][i] + vs[3][j]);

		sort(E.begin(), E.end());

		int ans = 0;

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				{
					pz = equal_range(E.begin(), E.end(), - (vs[0][i] + vs[1][j]));
					v = upper_bound(E.begin(), E.end(), - (vs[0][i] + vs[1][j])) - E.begin();
					u = lower_bound(E.begin(), E.end(), - (vs[0][i] + vs[1][j])) - E.begin();
					ans += v - u;
				}

		cout << ans << endl;

		return 0;
	}	