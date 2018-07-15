#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 0;

		cin >> n;
		for(i = 0; i < n; i++) cin >> u, vs.pb(u);
		sort(vs.begin(), vs.end());

		for(i = 1; i <= n; i++)
			ans += abs(i - vs[i - 1]);
		cout << ans << endl;
		return 0;
	}