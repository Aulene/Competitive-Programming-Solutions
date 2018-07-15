#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int ans[200007];
vector < pair <int, int> > vs;

bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.f != b.f) return a.f < b.f;
	return a.s < b.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, l = 0, r = 0;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(u, v));
			}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 0; i < n; i++) cout << vs[i].f << " " << vs[i].s << endl;
			
		while(l < n && r < n)
			{
				
			}

		return 0;
	}