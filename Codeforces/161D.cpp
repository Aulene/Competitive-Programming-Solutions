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

const int N = 50007;
const int K = 507;

int dp[N][K];
int ans = 0;
int k;

vvi g(N);

void dfs(int idx = 1, int p = -1) {
	dp[idx][0] = 1;
	for(auto it : g[idx])
		if(it != p) {
			dfs(it, idx);
			for(int j = 1; j < K; j++)
				dp[idx][j] += dp[it][j - 1];
		}
}

void dfs2(int idx = 1, int p = -1) {

	ans += 2 * dp[idx][k];

	for(auto it : g[idx])
		if(it != p) {
			for(int j = 1; j < k; j++) {

				// cout << idx << " " << it << " " << j << endl;
				// cout << (dp[it][j]) * (dp[idx][k - j] - dp[it][k - j - 1]) << endl;

				ans += (dp[it][j - 1]) * (dp[idx][k - j] - dp[it][k - j - 1]);
			}
			dfs2(it, idx);
		}

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

		cin >> n >> k;

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
		}

		dfs();

		// for(int i = 1; i <= n; i++) {
		// 	for(int j = 0; j <= m + 2; j++) cout << dp[i][j] << " "; cout << endl;
		// }
		// cout << endl;
		
		dfs2();

		cout << ans / 2 << endl;

		return 0;
	}