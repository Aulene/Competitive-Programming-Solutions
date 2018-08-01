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
vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 0; i < n; i++) {
			cin >> u >> v;
			for(j = u; j <= v; j++) a[j] = 1;
		}

		for(i = 1; i <= m; i++)
			if(!a[i]) vs.pb(i);

		cout << vs.size() << endl;
		for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;

		return 0;
	}