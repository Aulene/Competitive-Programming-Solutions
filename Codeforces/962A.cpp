#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u = 0, v = 0, ans;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i], u += a[i];

		if(u % 2 == 1) u = u / 2 + 1;
		else u = u / 2;
		// cout << u << endl;

		for(i = 0; i < n; i++)
			{
				v += a[i];

				if(v >= u) {
					ans = i + 1;
					break;
				}
			}

		cout << ans << endl;
		return 0;
	}