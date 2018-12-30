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

const int N = 100007;
int dp[N][7];

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
		string s;

		cin >> s;
		n = s.size();

		s = '.' + s;

		// for(i = 1; i <= n; i++) 
		// 	if(s[i] == 'a') ans++;

		for(i = 1; i <= n; i++) 
			if(s[i] == 'a') {
				dp[i][0] = 1;
				dp[i][1] = 0;
				dp[i][2] = 0;
				break;
			}

		for(i = i; i <= n; i++) {
			if(s[i] == 'a') {
				dp[i][0] = (1 + dp[i - 1][0] + dp[i - 1][1]) % mod;
				dp[i][1] = dp[i - 1][1];
				dp[i][2] = 0;
				// dp[i][0] = dp[i - 1][0];
				// dp[i][1] = dp[i - 1][1];
				// dp[i][2] = (1 + dp[i - 1][2]) % mod;
			}
			else if(s[i] == 'b') {
				
				if(dp[i - 1][2] == 0) {
					dp[i][0] = dp[i - 1][0];
					dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
					dp[i][2] = 1;
				}
				else {
					dp[i][0] = dp[i - 1][0];
					dp[i][1] = dp[i - 1][1];
					dp[i][2] = dp[i - 1][2];
				}
				
				// dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
				// dp[i][1] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
				// dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
			}
			else {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][1];
				dp[i][2] = dp[i - 1][2];
			}
		}

		for(i = 0; i <= 1; i++)
			{for(j = 1; j <= n; j++) cout << dp[j][i] << " "; cout << endl;}

		cout << dp[n][0] << endl;

		return 0;
	}