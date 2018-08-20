/*
ID: aussyle1
PROG: concom
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair < pair <int, int>, int> > vs;
int a[107][107], c[107];
bool vis[107];

bool cmp(pair < pair <int, int>, int> a, pair < pair <int, int>, int> b) { return a.s < b.s; }

void dfs(int idx)
{
	if(vis[idx]) return ;
	vis[idx] = 1;

	for(int i = 1; i <= 100; i++) {
		c[i] += a[idx][i];
		if(c[i] > 50) dfs(i);
	}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		ifstream cin ("concom.in");
		ofstream cout ("concom.out");

		int n, m, i, j, u, v, w;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> u >> v >> w;
			a[u][v] = w;
			vs.pb(mp(mp(u, v), w));
		}

		for(i = 1; i <= 100; i++) {
			memset(vis, 0, sizeof(vis));
			memset(c, 0, sizeof(c));
			dfs(i);

			for(j = 1; j <= 100; j++)
				if(c[j] > 50 && i != j) cout << i << " " << j << endl;
		}

		return 0;
	}
