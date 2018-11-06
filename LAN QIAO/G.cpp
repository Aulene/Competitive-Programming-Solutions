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
int t[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int T, n, m, i, j, u, v, w, lx;

		cin >> T;

		while(T--) {
			bool ans = 1;
			int res = 0, maxwar;
			lx = 0;

			for(i = 0; i < N; i++) t[i] = 0;
			for(i = 0; i < N; i++)
				for(j = 0; j < N; j++) dp[i][j] = 0;
			for(i = 0; i < N; i++)
				for(j = 0; j <= i; j++) dp[i][j] = -5007;

			cin >> n;

			while(n--) {
				cin >> u >> v;
				t[u] = v;
				lx = max(lx, u);
			}

			dp[1][0] = dp[1][1] = -t[1];

			for(i = 1; i <= lx; i++) cout << t[i] << " "; cout << endl;

			for(i = 1; i <= lx; i++) {
				int ducked = -5008;

				for(j = 0; j <= i; j++) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + j - t[i]);
					ducked = max(ducked, dp[i][j]);
				}

				if(t[i] != 0) {
					
					if(ducked < 0) {
						ans = 0;
						break;
					}
					else {
						res++;
						maxwar = ducked;
					}
				}
			}

			for(i = 1; i <= lx; i++) {
				for(j = 0; j <= i; j++) cout << dp[i][j] << " "; cout << endl;
			}

			if(!ans) {
				cout << "Defeat" << endl;
				cout << "Max level: " << res << endl;
			}
			else {
				cout << "Victory" << endl;
				cout << "Max warship: " << maxwar << endl;
			}

		}

		return 0;
	}