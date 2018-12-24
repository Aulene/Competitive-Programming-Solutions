/*
ID: aussyle1
PROG: inflate
LANG: C++
*/

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
#define zp mp(0, 0)

const int N = 10007;

int dp[N];

vpi vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		ifstream cin ("inflate.in");
		ofstream cout ("inflate.out");
		
		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			vs.pb({u, v});
		}

		for(i = 1; i <= n; i++) {
			dp[i] = dp[i - 1];
			for(j = 0; j < m; j++)
				if(i - vs[j].s >= 0) 
					dp[i] = max(dp[i], vs[j].f + dp[i - vs[j].s]);
			ans = max(ans, dp[i]);
		}

		cout << ans << endl;

		return 0;
	}