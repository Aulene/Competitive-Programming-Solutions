#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[1007], b[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= m; i++) cin >> b[i];

		u = 1, v = 1;

		while(u <= n && v <= m)
			{
				if(a[u] <= b[v]) {
					ans++;
					u++;
					v++;
					continue;
				}
				else {
					u++;
					continue;
				}
			}

		cout << ans << endl;

		return 0;
	}