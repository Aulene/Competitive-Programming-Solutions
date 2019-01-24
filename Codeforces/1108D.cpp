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

int dp[N][7]; // R, B, G

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
		
		int n, m, i, j, u, v;
		string s;

		cin >> n >> s;

		if(s[0] == 'R') {
			dp[0][0] = 0;
			dp[0][1] = 1;
			dp[0][2] = 1;
		}
		else if(s[0] == 'B') {
			dp[0][0] = 1;
			dp[0][1] = 0;
			dp[0][2] = 1;
		}
		else {
			dp[0][0] = 1;
			dp[0][1] = 1;
			dp[0][2] = 0;
		}

		for(i = 1; i < n; i++) {
			if(s[i] == 'R') {
				dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
				dp[i][1] = 1 + min(dp[i - 1][0], dp[i - 1][2]);
				dp[i][2] = 1 + min(dp[i - 1][0], dp[i - 1][1]);
			}
			else if(s[i] == 'B') {
				dp[i][0] = 1 + min(dp[i - 1][1], dp[i - 1][2]);
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
				dp[i][2] = 1 + min(dp[i - 1][0], dp[i - 1][1]);
			}
			else {
				dp[i][0] = 1 + min(dp[i - 1][1], dp[i - 1][2]);
				dp[i][1] = 1 + min(dp[i - 1][0], dp[i - 1][2]);
				dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
			}
		}

		// for(j = 0; j < 3; j++) {
		// 	for(i = 0; i < n; i++) cout << dp[i][j] << " "; cout << endl;
		// }

		string sv = "", perm = "RBG";
		int ans = LLONG_MAX, mi;

		for(i = 0; i < 3; i++) {
			if(ans > dp[n - 1][i]) {
				ans = dp[n - 1][i];
				mi = i;
			}
		}

		sv += perm[mi];

		for(i = n - 2; i >= 0; i--) {

			int up = mi;
			int cost = INT_MAX;

			for(j = 0; j < 3; j++) {
				if((dp[i][j] < cost) && (up != j)) {
					cost = dp[i][j];
					mi = j;
				}
			}

			sv += perm[mi];
		}

		reverse(sv.begin(), sv.end());

		cout << ans << endl << sv << endl;

		return 0;
	}