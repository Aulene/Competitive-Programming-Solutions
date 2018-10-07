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

vector < vector <int> > g(200007);
int dp[200007][4];
/*
	dp[idx][1] = sum of distances from all nodes at dist 1
	dp[idx][2] = sum of distances from all nodes at dist 2 
 */

int dfs(int idx, int p = -1)
{
	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p) {
			dp[idx][1]++;
			dfs(g[idx][i], idx);
			dp[idx][2] += dp[g[idx][i]][1];
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

		cin >> n;

		for(i = 0; i < n - 1; i++) {
			 cin >> u >> v;
			 g[u].pb(v), g[v].pb(u);
		}



		return 0;
	}