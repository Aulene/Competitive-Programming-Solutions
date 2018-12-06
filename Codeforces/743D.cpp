#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

const int N = 200007;

int a[N], dp[N], dp2[N], dp3[N];
vvi g(N);

int ans = 0;

pi merge(pi a, int b) {
	if(b > a.f) {
		a.s = a.f;
		a.f = b;
	} else if(b > a.s) a.s = b;
	return a;
}

void dfs(int idx, int p = -1) {
	
	dp[idx] = a[idx];
	pi xv = mp(LLONG_MIN, LLONG_MIN);

	for(auto it : g[idx]) {
		if(it != p) {
			dfs(it, idx);
			dp[idx] = dp[idx] + dp[it];
			dp2[idx] = max(dp2[idx], dp[it]);
			xv = merge(xv, dp2[it]);
		}
	}

	dp3[idx] = xv.f + xv.s;
	ans = max(ans, dp3[idx]);
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
		}

		dfs(1);

		cout << ans << endl;

		return 0;
	}