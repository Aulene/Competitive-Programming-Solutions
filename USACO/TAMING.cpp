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

const int N = 107;

int a[N], dp[N][N], c[N][N], pre[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		ifstream cin ("taming.in");
		ofstream cout ("taming.out");
		
		int n, m = 1, i, j, k, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++)
			if(a[i] != i - 1) pre[i] = pre[i - 1] + 1;
			else pre[i] = pre[i - 1];

		for(i = 1; i <= n; i++) c[1][i] = pre[i];

		for(i = 2; i <= n; i++)
			for(j = i; j <= n; j++)
				if(j - i != a[j]) c[i][j] = 1 + c[i][j - 1];
				else c[i][j] = c[i][j - 1];


		// for(i = 1; i <= n; i++) {
		// 	for(j = 1; j <= n; j++) cout << c[i][j] << " "; cout << endl;
 	// 	} cout << endl;

		while(m <= n) {

			if(m == 1) {
				cout << pre[n] << endl;
				m++;
				continue;
			}

			int ans = LLONG_MAX;

			for(i = 1; i <= n; i++)
				for(j = 1; j <= m; j++) dp[i][j] = INT_MAX;

			for(i = 1; i <= n; i++) dp[i][1] = pre[i];
			// dp[1][1] = pre[1];

			for(j = 2; j <= m; j++) {
				for(i = j; i <= n; i++) {
					for(k = j - 1; k < i; k++)
						if(j != 2) dp[i][j] = min(dp[i][j], dp[k][j - 1] + c[k][i - 1]);
						else dp[i][j] = c[1][i - 1];
				}
			}

			// for(j = 1; j <= m; j++) {
			// 	for(i = 1; i <= n; i++) cout << dp[i][j] << " "; cout << endl;
	 	// 	} cout << endl;

			for(i = 1; i <= n; i++)
				dp[i][m] = dp[i][m] + c[i][n];

			// for(j = 1; j <= m; j++) {
			// 	for(i = 1; i <= n; i++) cout << dp[i][j] << " "; cout << endl;
	 	// 	} cout << endl;

			for(i = m; i <= n; i++) ans = min(ans, dp[i][m]);

			cout << ans << endl;

			m++;
		}

		return 0;
	}