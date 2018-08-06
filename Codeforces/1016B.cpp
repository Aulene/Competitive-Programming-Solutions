#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, i, j, u, v;
		string s, s1;

		cin >> n >> m >> q;

		cin >> s >> s1;

		for(i = 0; i < n - m + 1; i++) {

			int ans = 1;

			for(j = 0; j < m; j++) {
				if((i + j >= n) || s[i + j] != s1[j]) {
					ans = 0;
					break;
				}
			}

			a[i + 1] = ans;
		}

		for(i = 1; i <= n; i++) a[i] = a[i - 1] + a[i];

		while(q--)
			{
				cin >> u >> v;

				int ans = 0;

				if(v - m + 1 >= u)
					ans = a[v - m + 1] - a[u - 1];

				cout << ans << endl;
			}
		return 0;
	}