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
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

const int N = 200007;

vvi g(N);
int a[N], dp[N];

int dfs(int idx, int p = -1) {

	if(dp[idx] != -1) return dp[idx];

	int ans = a[idx], minx = INT_MAX;

	for(auto it : g[idx])
		if(it != p) {
			ans += dfs(it, idx);
			minx = min(minx, dp[it]);
		}

	// cout << idx << " " << g[idx].size() << " " << ans << " " << minx << endl;

	if(((p != -1) && g[idx].size() > 1 && ((g[idx].size() - 1) % 2) == 1) || ((p == -1) && (g[idx].size() % 2 == 1))) 
		ans -= minx;

	// cout << idx << " " << ans << endl;

	return dp[idx] = ans;
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) dp[i] = -1;

		for(i = 1; i <= n; i++) {
			cin >> u >> a[i];
			if(i != 1) g[u].pb(i), g[i].pb(u);
		}

		cout << dfs(1) << endl;

		// for(i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;

		return 0;
	}