#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, a, b, ans;

		cin >> t;

		while(t--)
			{
				u = 0;

				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> a >> b;
						b += u;
						u = max(b - a, 0LL);
					}

				if(u) cout << 1 << endl;
				else cout << 0 << endl;
			}
		return 0;
	}