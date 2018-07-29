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

		int t, n, m, u;

		cin >> t;

		while(t--) 
			{
				cin >> n >> m;

				if(n < m) {
					n = n + m;
					m = n - m;
					n = n - m;
				}

				if(!(n % 2) && !(m % 2)) cout << "abdullah\n";
				else cout << "hasan\n";
			}
		return 0;
	}