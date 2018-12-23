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

const int N = 100007;

int a[N], dp[N][7];
vector <string> vs(N), rev(N);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, ans;
		string s, s1, s2;

		cin >> n;

		int ansx = 1;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= n; i++) {
			cin >> vs[i];
			rev[i] = vs[i];
			reverse(rev[i].begin(), rev[i].end());
		}

		for(i = 0; i <= n; i++) dp[i][0] = dp[i][1] = LLONG_MAX;
		dp[1][0] = 0, dp[1][1] = a[1];

		for(i = 2; i <= n; i++) {

			if(vs[i] >= vs[i - 1] && dp[i - 1][0] != LLONG_MAX) dp[i][0] = dp[i - 1][0];
			if(vs[i] >= rev[i - 1] && dp[i - 1][1] != LLONG_MAX) dp[i][0] = min(dp[i][0], dp[i - 1][1]);

			if(rev[i] >= vs[i - 1] && dp[i - 1][0] != LLONG_MAX) dp[i][1] = a[i] + dp[i - 1][0];
			if(rev[i] >= rev[i - 1] && dp[i - 1][1] != LLONG_MAX) 
				dp[i][1] = min(dp[i][1], a[i] + dp[i - 1][1]);

			if(dp[i][0] == LLONG_MAX && dp[i][1] == LLONG_MAX) ansx = 0;
		}

		// for(j = 0; j <= 1; j++) {
		// 	for(i = 1; i <= n; i++) cout << dp[i][j] << " "; 
		// 	cout << endl;
		// }

		if(!ansx) ans = -1;
		else ans = min(dp[n][0], dp[n][1]);

		cout << ans << endl;


		return 0;
	}