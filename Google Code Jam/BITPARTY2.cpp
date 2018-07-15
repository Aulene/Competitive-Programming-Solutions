#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 100000000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair < pair <int, int>, int> > vs;
int n;

int recur(int idx, int b, int r)
{
	if(b == 0) return 0;
	if(idx >= n || r <= 0) return mod;

	int ans = recur(idx + 1, b, r);

	for(int j = 1; j <= min(b, vs[idx].f.f); j++)
		{
			int ans2 = max(j * vs[idx].f.s + vs[idx].s, recur(idx + 1, b - j, r - 1));
			ans = min(ans, ans2);
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, T = 1, m, r, b, c, i, j, k, u, v, s, p, ans;

		cin >> t;

		while(T <= t)
			{
				vs.clear();

				cin >> r >> b >> n;

				for(i = 0; i < n; i++)
					{
						cin >> m >> s >> p;
						vs.pb(mp(mp(m, s), p));
					}

				ans = recur(0, b, r);
				cout << "Case #" << T << ": " << ans << endl;
				
				T++;
			}

		return 0;
	}