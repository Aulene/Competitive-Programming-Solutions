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

vector <int> vs;
unordered_map <int, int> m;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v;

		cin >> t;

		while(t--)
			{
				m.clear();
				vs.clear();
				
				int ans = 0;

				cin >> n;

				for(i = 0; i < n; i++) {
					cin >> u >> v;
					m[v]++;
					vs.pb(u);
				}

				for(i = 0; i < vs.size(); i++) {
					ans += m[vs[i]];
				}


					cout << ans << endl;
			}
		return 0;
	}