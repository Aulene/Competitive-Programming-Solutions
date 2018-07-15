#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int vs[200007];
vector <int> a, ansv;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) {
			cin >> j;
			a.pb(j);
		}

		while(m--) {
			cin >> u >> v;
			vs[u]++;
			vs[v + 1]--;
		}

		for(i = 1; i <= n; i++)
			vs[i] = vs[i - 1] + vs[i], ansv.pb(vs[i]);

		sort(a.begin(), a.end());
		sort(ansv.begin(), ansv.end());

		// for(i = 0; i < a.size(); i++) cout << a[i] << " "; cout << endl;
		// for(i = 0; i < ansv.size(); i++) cout << ansv[i] << " "; cout << endl;
			
		for(i = 0; i < n; i++) ans += a[i] * ansv[i];

		cout << ans << endl;

		return 0;
	}