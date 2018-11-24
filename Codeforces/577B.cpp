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

const int N = 1000007;
const int M = 1007;

int a[N], pre[N];
int dp[M][M];

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
		bool ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i], a[i] %= m;
		
		if(n > m) ans = 1;
		else {

			for(i = 1; i <= n; i++) {
				dp[i + 1][a[i]] = 1;

				for(j = 0; j <= m; j++)
					if(dp[i][j]) {
						dp[i + 1][j] = 1;
						dp[i + 1][(j + a[i]) % m] = 1;
					}
			}

			if(dp[n + 1][0]) ans = 1;
		}

		(ans) ? cout << "YES" << endl : cout << "NO" << endl;

		return 0;
	}