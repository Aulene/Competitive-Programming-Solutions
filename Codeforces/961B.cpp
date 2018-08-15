#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], b[100007], p[100007], p2[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j, u, v, ans = 0;

		cin >> n >> k;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= n; i++) cin >> b[i];
		for(i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
		for(i = 1; i <= n; i++)
			if(b[i]) p2[i] = p2[i - 1] + a[i];
			else p2[i] = p2[i - 1];

		u = 1, v = k;

		while(v <= n)
			{
				ans = max(ans, p2[u - 1] + (p[v] - p[u - 1]) + (p2[n] - p2[v]));
				u++, v++;
			}

		cout << ans << endl;
		return 0;
	}