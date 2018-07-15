#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int pref[5007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, q, u, v, i, j;

		// ifstream cin ("GBUS.in");
		// ofstream cout ("GBUS.out");

		cin >> t;

		for(int T = 1; T <= t; T++)
			{
				memset(pref, 0, sizeof(pref));

				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> u >> v;
						pref[u]++;
						pref[v + 1]--;
					}

				for(i = 1; i < 5007; i++) pref[i] = pref[i - 1] + pref[i];

				cin >> q;

				cout << "Case: #" << T << ": ";
				while(q--)
					{
						cin >> u;
						cout << pref[u] << " ";
					}
				cout << endl;
			}
		return 0;
	}