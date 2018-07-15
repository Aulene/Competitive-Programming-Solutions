#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <int, int> > vs;
vector <int> v;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, s, i, j, u, vx, m, ans = -1;

		cin >> n >> s;

		for(i = 0; i < n; i++)
			{
				cin >> u >> vx;
				v.pb(u * 60 + vx);
				// cout << u * 60 + vx << endl;
			}

		for(i = 0; i < n - 1; i++)
			{
				if(v[i + 1] - v[i] >= 2 * s + 2) {
					ans = v[i] + 1 + s;
					break;
				}
			}

		if(ans == -1) {
			ans = v[n - 1] + 1 + s;
		}	

		if(v[0] > s) {
			ans = 0;
		}

		// cout << ans << endl;
		cout << ans / 60 << " " << ans % 60 << endl;

		return 0;
	}