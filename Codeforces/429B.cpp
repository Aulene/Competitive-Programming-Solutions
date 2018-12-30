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

const int N = 1007;

int a[N][N];
int dp[N][N], dp2[N][N], dp3[N][N], dp4[N][N];

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
		
		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) 
			for(j = 1; j <= m; j++) cin >> a[i][j];

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		for(j = m; j >= 1; j--)
		    for(i = 1; i <= n; i++) dp2[i][j] = a[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
		for(i = n; i >= 1; i--)
		    for(j = 1; j <= m; j++) dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
		for(i = n; i >= 1; i--)
		    for(j = m; j >= 1; j--) dp4[i][j] = a[i][j] + max(dp4[i][j + 1], dp4[i + 1][j]);

		for(i = 2; i < n; i++)
			for(j = 2; j < m; j++) {
				ans = max(ans, dp[i - 1][j] + dp4[i + 1][j] + dp2[i][j + 1] + dp3[i][j - 1]);
				ans = max(ans, dp[i][j - 1] + dp4[i][j + 1] + dp2[i - 1][j] + dp3[i + 1][j]);
			}

		cout << ans << endl;
		return 0;
	}