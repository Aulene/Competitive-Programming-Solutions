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

int dp[N][4];

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
		
		int n, l, r, i, j, u, v, n1, n2, n0;
	
		cin >> n >> l >> r;

		n0 = r / 3 - (l - 1) / 3;
		n1 = (r + 2) / 3 - (l + 1) / 3;
		n2 = (r - l + 1) - n0 - n1;

		dp[1][0] = n0;
		dp[1][1] = n1;
		dp[1][2] = n2;

		for(i = 2; i <= n; i++) {
			dp[i][0] = ((dp[i - 1][0] * n0) % mod + (dp[i - 1][1] * n2) % mod + (dp[i - 1][2] * n1) % mod) % mod;
			dp[i][1] = ((dp[i - 1][0] * n1) % mod + (dp[i - 1][1] * n0) % mod + (dp[i - 1][2] * n2) % mod) % mod;
			dp[i][2] = ((dp[i - 1][0] * n2) % mod + (dp[i - 1][1] * n1) % mod + (dp[i - 1][2] * n0) % mod) % mod;
		}	

		cout << dp[n][0] << endl;

		return 0;
	}