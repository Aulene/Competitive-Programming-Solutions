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

const int N = 5007;

int a[N], dp[N][N];

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
		
		string s;
		int n, m, i, j, u, v, ans = 0;

		cin >> s;
		n = s.size();

		for(i = 1; i <= n; i++)
			if(s[i - 1] == '(') a[i] = 1;
			else if(s[i - 1] == ')') a[i] = -1;

		for(i = 1; i <= n - 1; i++) 
			if((a[i] == 1 && a[i + 1] == 0) ||
				(a[i] == 0 && a[i + 1] == 0) || 
				(a[i] == 0 && a[i + 1] == -1) ||
				(a[i] == 1 && a[i + 1] == -1)) dp[i][i + 1] = 1;

		for(j = 4; j <= n; j += 2) {

			for(i = 1; i <= n; i++) 
				if(i + j - 1 <= n) {
					if(((a[i] == 1 && a[i + j - 1] == 0) ||
					    (a[i] == 0 && a[i + j - 1] == 0) || 
					    (a[i] == 0 && a[i + j - 1] == -1) || 
					    (a[i] == 1 && a[i + j - 1] == -1)) && dp[i + 1][i + j - 2]) {
							dp[i][i + j - 1] = 1;
					}
			}

			if(j % 4 == 0) {
				for(i = 1; i <= n; i++) 
					if(i + j - 1 <= n) {
						if(((dp[i][(2 * i + j - 1) / 2] && dp[(2 * i + j - 1) / 2 + 1][(i + j - 1)])))
							dp[i][i + j - 1] = 1;
					}
			}

		}

		for(j = 4; j <= n; j += 4) {
			for(i = 1; i <= n; i++) 
				if(i + j - 1 <= n) {
					if(((dp[i][(2 * i + j - 1) / 2] && dp[(2 * i + j - 1) / 2 + 1][(i + j - 1)])))
						dp[i][i + j - 1] = 1;
				}
		}

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) cout << dp[i][j] << " "; cout << endl;
		}

		for(i = 1; i <= n; i++)
			for(j = i + 1; j <= n; j++) 
				if(dp[i][j]) ans++;

		cout << ans << endl;

		return 0;
	}