#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[200007], p[200007];
vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;
		bool ans = 1;

		string s;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i], vs.pb(mp(a[i], i)); cin >> s;
	
		sort(vs.begin(), vs.end());

		s += '0';

		for(i = 0; i < n; i++)
			p[i + 1] = p[i] + (int) s[i] - '0';
		
		for(i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;

		for(i = 0; i < n; i++)	
			{
				int u = vs[i].f, v = vs[i].s, cur = i + 1;

				if(v == cur) continue;
				if(v > cur) swap(cur, v);

				cout << u << " " << cur << " " << v << " " << abs(p[cur] - p[v]) << endl;

				if(!(abs(p[cur] - p[v]) == abs(cur - v - 1))) ans = 0;
			}

		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;

		return 0;
	}