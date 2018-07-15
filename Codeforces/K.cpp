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

		int t, n, i, a, b, c, d, grade, ans = 0;
		double m;

		cin >> t;

		while(t--)
			{
				ans = 0;

				cin >> n >> m;

				grade = ceil(n * m);

				for(i = 0; i < n; i++) {
					cin >> a;
					if(a >= 50) ans++;
				}

				if(ans >= grade) cout << "YES\n";
				else cout << "NO\n";
			}
		return 0;
	}