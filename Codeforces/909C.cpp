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

const int N = 5007;

int dp[N][N];
vi vs(N);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v = 0, ans = 0;
		char x;

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> x;
			(x == 's') ? vs[i] = 0 : vs[i] = 1;
		}

		vs[0] = 1;
		for(i = 1; i <= n; i++) cout << vs[i] << " "; cout << endl;

		dp[0][0] = 1;

		for(i = 1; i <= n; i++) {

			if(vs[i] == 1) v++;
			else if(v > 0) v--;

			if(vs[i - 1] == 1)  {
				for(j = 0; j <= v; j++) 
					dp[i][j] = dp[i - 1][j];

				if(vs[i] == 1) dp[i][v] = (dp[i][v] + dp[i - 1][v - 1]) % mod;

				continue;
			}

			// dp[i][0] = dp[i - 1][0];
			for(j = 1; j <= v; j++) 
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
		}

		for(i = 0; i <= n; i++) {
			for(j = 0; j <= v; j++) cout << dp[i][j] << " ";
				cout << endl;
		}

		for(i = 0; i <= v; i++) ans = (ans + dp[n][i]) % mod;

		cout << ans << endl;



		return 0;
	}