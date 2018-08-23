#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

vi vs;
int px[12];

int numdig(int x) {
	int ret = 0;
	while(x) ret++, x /= 10;
	return ret;
}

int chck(int x) {
	int frs = 0, sv = 0, n;
	while(x) {
		n = x % 10, x /= 10;
		if(n == 7) sv++;
		else frs++;
	}
	if(frs == sv) return 1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, ans = 0;

		px[1] = 10;
		for(i = 2; i < 10; i++) px[i] = px[i - 1] * 10;

		cin >> n;
		vs.pb(4); vs.pb(7);

		u = 0; v = 2;

		while(true)
			{
				for(i = u; i < v; i++) {
					j = numdig(vs[i]);
					m = 4 * px[j] + vs[i];

					if(m >= n && chck(m)) {
						ans = m;
						break;
					}
					
					vs.pb(m);
				}

				if(ans) break;

				for(i = u; i < v; i++) {
					j = numdig(vs[i]);
					m = 7 * px[j] + vs[i];

					if(m >= n && chck(m)) {
						ans = m;
						break;
					}
					
					vs.pb(m);
				}

				if(ans) break;
				u = v; v = vs.size();
				// cout << vs[u] << endl;

				// cout << u << " " << v << endl;
			}

		cout << ans << endl;

		return 0;
	}