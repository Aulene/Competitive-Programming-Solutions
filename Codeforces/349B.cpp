#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[1007];
vector < pair <int, int> > vs;

bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.s == b.s) return a.f > b.f;
	return a.s < b.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;
		string ans = "";

		cin >> n;
		for(i = '1'; i <= '9'; i++) cin >> a[i], vs.pb(mp((char) i, a[i]));

		sort(vs.begin(), vs.end(), cmp);

		// for(i = 0; i < vs.size(); i++) cout << vs[i].f << " " << vs[i].s << endl;

		while(n) {
			if(n - vs[0].s < 0) break;
			n -= vs[0].s;
			ans += vs[0].f;
		}


		for(i = 0; i < ans.size(); i++)
			{
				u = a[ans[i]];

				for(j = '9'; j >= '1'; j--) 
					{
						v = a[j];

						if(n + u - v >= 0) {
							n = n + u - v;
							ans[i] = (char) (j);
							break;
						} 
					}
			}

		if(ans.size()) cout << ans << endl;
		else cout << -1 << endl;

		return 0;
	}