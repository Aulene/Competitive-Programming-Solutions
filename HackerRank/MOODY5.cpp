#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

pair < int, pair <int, int> > parent[400007];
vector <int> vs;
set <int> s;
int p2[100007];

void find(int idx) {
	pair < int, pair <int, int> > pz;

	while(idx)
		{
			pz = parent[idx];
			s.insert(pz.s.f);
			s.insert(pz.s.s);
			// cout << idx << " " << pz.f << " " << pz.s.f << " " << pz.s.s << endl;
			idx = pz.f;
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, q, i, j, k, p, u, v, ans;

		p2[0] = 1;
		for(i = 1; i < 100007; i++) p2[i] = (2 * p2[i - 1]) % mod;

		cin >> n >> m;

		for(t = 1; t <= m; t++)
			{
				cin >> q;

				if(q == 1)
					{
						cin >> p >> u >> v;
						parent[t] = mp(p, mp(u, v));
					}
				else
					{
						s.clear();
						set <int> s1, s2;
						cin >> p >> k;
						for(i = 0; i < k; i++) cin >> u, s1.insert(u);

						find(p);
						set_intersection(s.begin(), s.end(), s1.begin(), s1.end(), inserter(s2, s2.begin()));

						u = k - s2.size();

						if(s2.size()) ans = (p2[u] * 2) % mod;
						else ans = p2[u];
						
						cout << ans << endl;
					}
			}
		return 0;
	}