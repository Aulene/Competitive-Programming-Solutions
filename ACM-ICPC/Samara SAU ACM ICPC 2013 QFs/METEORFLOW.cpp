#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

compare
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = 0, t = 0, shield = 0;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> u >> v;
			pq.p(mp(u, v));
		}

		while(!pq.empty()) {
			u = pq.top().f, v = pq.top().s;
			pq.pop();
			cout << u << " " << v << endl;

			shield += u - t;
			t = u;

			if(shield >= v) {
				shield -= v;
			}
			else ans++;
		}

		cout << ans << endl;
		return 0;
	}