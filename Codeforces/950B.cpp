#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], b[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= m; i++) cin >> b[i];

		int asum = 0, bsum = 0, ans = 0;
		u = 1, v = 1;

		while(u <= n && v <= m)
			{
				if(asum <= bsum)
					{
						asum += a[u];
						u++;
					}
				else
					{
						bsum += b[v];
						v++;
					}
				
				if(asum == bsum)
					{
						asum = bsum = 0;
						ans++;
					}
			}

		while(u <= n)
			asum += a[u], u++;
		while(v <= m)
			bsum += b[v], v++;

		if(asum == bsum) ans++;

		cout << ans << endl;
		return 0;
	}