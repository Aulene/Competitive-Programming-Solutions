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

int a[N], c[N][N];
int dp[N][N][N], dp2[N][N][N], dp3[N][N][N];

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
		
		int n, m, K, k, i, j, l, u, v, ans = LLONG_MAX;

		for(i = 1; i < N; i++)
			for(j = 0; j < N; j++)
				for(k = 0; k < N; k++) 
					dp[i][j][k] = 1e16;

		dp[0][0][0] = 0;


		cin >> n >> m >> K;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) c[i][j] = 1e16;
			for(j = 1; j <= m; j++) cin >> c[i][j];
			if(a[i]) {
				for(j = 1; j <= m; j++) c[i][j] = 1e16;
				c[i][a[i]] = 0;
			}
		}

		for(i = 1; i <= n; i++) {
			// printf("I = %lld\n", i);

			for(j = 1; j <= m; j++) {
				for(k = 1; k <= min(i, K); k++) {

					dp[i][j][k] = min(dp[i][j][k], c[i][j] + dp[i - 1][j][k]);
					
					// printf("(%lld,%lld,%lld) ", j, k, dp[i][j][k]);
					
					for(l = 1; l <= m; l++)
						if(l != j) {
							// printf("(%lld,%lld,%lld,%lld) ", l, k, c[i][j], dp[i - 1][l][k - 1]);
							dp[i][j][k] = min(dp[i][j][k], c[i][j] + dp[i - 1][l][k - 1]);
						}

					// printf("(%lld,%lld,%lld)\n", j, k, dp[i][j][k]);
				} 

				// cout << endl;
			}
		}

		// for(i = 1; i <= n; i++) {
		// 	cout << "I = " << i << endl;
		// 	for(j = 1; j <= m; j++) {
		// 		for(k = 1; k <= K; k++) printf("(%lld,%lld,%lld) ", j, k, dp[i][j][k]); cout << endl;
		// 	}
		// }

		for(i = 1; i <= m; i++) ans = min(ans, dp[n][i][K]);

		if(ans == 1e16) ans = -1;

		cout << ans << endl;


		return 0;
	}