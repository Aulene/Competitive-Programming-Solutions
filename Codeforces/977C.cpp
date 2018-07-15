#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[200007];
vector <int> vs, ax;
unordered_map <int, int> vis;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j, u, v, ans = -1;

		cin >> n >> k;

		for(i = 0; i < n; i++) 
			{
				cin >> a[i];
				ax.pb(a[i]);
				if(!vis[a[i]]) {
					vis[a[i]] = 1;
					vs.pb(a[i]);
				}
			}

		sort(ax.begin(), ax.end());
		sort(vs.begin(), vs.end());

		// for(i = 0; i < ax.size(); i++) cout << ax[i] << " "; cout << endl;

		for(i = 0; i < vs.size(); i++)
			{
				// cout << vs[i] << endl;

				u = vs[i] - 1;

				v = lower_bound(ax.begin(), ax.end(), u) - ax.begin();

				// cout << u << " " << v << endl;

				if(v == k) {
					ans = u;
					break;
				}

				u = vs[i];

				// v = upper_bound(ax.begin(), ax.end(), u) - ax.begin();

				// cout << u << " " << v << endl;

				if(v == k) {
					ans = u;
					break;
				}	
			}

		cout << ans << endl;

		return 0;
	}