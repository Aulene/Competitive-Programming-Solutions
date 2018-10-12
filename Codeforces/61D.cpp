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

int maxDist = -1, maxDistNode, ans = 0;
int a[100007], dp[100007];
vector < vector <pi> > g(100007);

int dfsSum(int idx, int p = -1) 
{
	int ans = 0;

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i].f != p) {
			ans += g[idx][i].s + dfsSum(g[idx][i].f, idx);
		}
	return dp[idx] = ans;
}

void distDfs(int idx, int dist, int p = -1)
{
	for(int i = 0; i < g[idx].size(); i++) {
		int ndist = dist + g[idx][i].s;

		if(g[idx][i].f != p) {
			if(ndist > maxDist) {
				maxDist = ndist;
				maxDistNode = g[idx][i].f;
			}
			distDfs(g[idx][i].f, ndist, idx);
		}
	}
}

int dfs(int idx, int p = -1)
{
	int adder = 0, over = 0;
	if(idx == maxDistNode) over = 1;

	for(int i = 0; i < g[idx].size(); i++) {
		if(g[idx][i].f != p) {

			ans += g[idx][i].s;
			adder = over = dfs(g[idx][i].f, idx);
			
			if(!adder) ans += g[idx][i].s;
			else adder = 0;
		}
	}

	return over;
}

bool cmp(pi a, pi b) { return a.s < b.s; }

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, w;

		cin >> n;

		for(i = 0; i < n - 1; i++) {
			 cin >> u >> v >> w;
			 g[u].pb({v, w}), g[v].pb({u, w});
		}

		// for(i = 1; i <= n; i++) sort(g[i].begin(), g[i].end(), cmp);

		// for(i = 1; i <= n; i++) {
		// 	cout << i << endl;
		// 	for(j = 0; j < g[i].size(); j++) cout << g[i][j].f << " " << g[i][j].s << endl;
		// }

		// dfsSum(1);
		// for(i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;

		distDfs(1, 0);
		// cout << maxDistNode << " " << maxDist << endl;
		dfs(1, 0);
		cout << ans << endl;
		
  		return 0;
	}