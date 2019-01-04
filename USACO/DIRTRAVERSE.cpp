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

const int N = 100007;

int a[N], leaf[N], lv[N], dp[N];
int num = 0;

vvi g(N);

int sub(int idx, int p = -1) {
	int ans = leaf[idx];
	for(auto it : g[idx])
		if(it != p) ans += sub(it, idx);
	return lv[idx] = ans;
}

int dfs(int idx, int p = -1) {
	if(leaf[idx] == 1) return a[idx];

	int ans = 0;
	if(p != -1) ans = (a[idx] + 1) * lv[idx];

	// cout << p << " " << idx << " " << (a[idx] + 1) * lv[idx] << endl;

	for(auto it : g[idx]) 
		if(it != p) ans += dfs(it, idx);

	// cout << p << " " << idx << " " <<  ans << endl;

	return ans;
}

void dfs2(int idx, int p = -1) {
	if(p != -1) dp[idx] = dp[p] + 3 * (num - lv[idx]) - ((1 + a[idx]) * lv[idx]);
	for(auto it : g[idx])
		if(it != p) dfs2(it, idx);
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
		
		ifstream cin ("dirtraverse.in");
		ofstream cout ("dirtraverse.out");
		
		int n, m, i, j, u, v, ans = LLONG_MAX;
		string s;

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> s >> m;
			a[i] = s.size();
			
			if(m == 0) leaf[i] = 1, num++;

			for(j = 0; j < m; j++) {
				cin >> v;
				g[i].pb(v), g[v].pb(i);
			}
		}

		sub(1);
		// for(i = 1; i <= n; i++) cout << lv[i] << " "; cout << endl;
		dp[1] = dfs(1);
		dfs2(1);
		// for(i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;
		for(i = 1; i <= n; i++) ans = min(ans, dp[i]);

		cout << ans << endl;

		return 0;
	}