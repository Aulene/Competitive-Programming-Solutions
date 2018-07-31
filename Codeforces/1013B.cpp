#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], vs[100007];
vector <int> vx[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = -1, sum;

		cin >> n >> m;

		for(i = 1; i <= 100000; i++) {
			int u = i & m;
			vx[u].pb(i);
		}

		// for(i = 1; i <= m; i++) {
		// 	cout << i << endl;
		// 	for(j = 0; j < vx[i].size(); j++) cout << vx[i][j] << " "; cout << endl;
		// }

		for(i = 0; i < n; i++)
			{
				cin >> a[i], vs[a[i]]++;
				if(vs[a[i]] > 1) {
					ans = 0;
				}
			}

		if(ans == -1) {
			for(i = 1; i <= 100000; i++) {
				u = i & m;

				if(vs[i] && vs[u] == 1 && u != i) {
					// cout << i << " " << u << endl;
					ans = 1;
					break;
				}
			}
			
		}

		if(ans == -1) {

			for(i = 0; i <= 100000; i++) 
				{
					sum = 0;
					for(j = 0; j < vx[i].size(); j++) sum += vs[vx[i][j]];

					if(sum >= 2) {
						ans = 2;
						break;
					}

				}

		}
		cout << ans << endl;

		return 0;
	}