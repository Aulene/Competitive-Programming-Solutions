#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
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

const int N = 2007;
int dp[N][N];

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
		
		int n, m, k, i, j, u, v;

		cin >> n >> m >> k;

		dp[1][0] = m;

		for(i = 1; i <= n; i++) {
			for(j = 0; j <= k; j++) {
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + ((m - 1) * dp[i][j]) % mod) % mod;
			}
		}

		cout << dp[n][k] << endl;

		return 0;
	}