#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[107], b[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u = 0, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i], u = u ^ a[i];
		for(i = 1; i <= m; i++) cin >> b[i], u = u ^ b[i];
		

		if(u) cout << "NO" << endl;
		else
			{
				cout << "YES" << endl;
				for(i = 1; i <= n; i++) {
					for(j = 1; j <= m; j++) v = a[i] ^ b[j], cout << v << " "; cout << endl;
				}
			}
		return 0;
	}