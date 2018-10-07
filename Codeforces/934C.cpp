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

vector <int> vs1;

int dp[2007][2007];
int pre1s[2007], post2s[2007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, ans = 0;

		cin >> n;

		for(i = 0; i < n; i++) cin >> u, vs1.pb(u);

		for(i = 0; i < n; i++)
			pre1s[i + 1] = (vs1[i] == 1 ? 1 : 0) + pre1s[i];
		for(i = n - 1; i >= 0; i--)
			post2s[i + 1] = (vs1[i] == 2 ? 1 : 0) + post2s[i + 2];

		ans = max(pre1s[n], post2s[1]);

		for(i = n - 1; i >= 0; i--) {
			multiset <int> vs;
			for(j = i; j >= 0; j--) {
				vs.insert(vs1[j]);
				multiset <int> :: iterator it = vs.upper_bound(vs1[j]);
				if(it != vs.end()) vs.erase(it);
				dp[j + 1][i + 1] = vs.size();
			}
		}

		// for(i = 1; i <= n; i++) {
		// 	for(j = 1; j <= n; j++) if(i < j)
		// 		cout << "DP[" << i << "][" << j << "] = " << dp[i][j] << endl;
		// }

		for(i = 1; i <= n; i++) {
			for(j = i; j <= n; j++) {
				if(ans < pre1s[i - 1] + dp[i][j] + post2s[j + 1]) {
					ans = max(ans, pre1s[i - 1] + dp[i][j] + post2s[j + 1]);
					// cout << i << " " << j << " " << ans << endl;
				}
			}
		}

		cout << ans << endl;

		return 0;
	}