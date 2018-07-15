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

		int T, t, n, i, j, u, v, ans;

		cin >> T;

		for(t = 1; t <= T; t++)
			{
				cin >> n;

				ans = 0;
				v = 1;

				while(n)
					{
						u = n % 10;
						n /= 10;

						if(u % 2 == 1) ans += v;
						v++;
					}

				cout << "Case #" << t << ": " << ans << endl;
			}

		return 0;
	}