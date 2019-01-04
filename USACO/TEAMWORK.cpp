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

const int N = 10007;

int dp[N], a[N];
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		ifstream cin ("teamwork.in");
		ofstream cout ("teamwork.out");
		
		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++) {
			int mx = a[i]; dp[i] = dp[i - 1] + a[i];

			for(j = i - 1; j >= max(1LL, i - m + 1); j--) {
				mx = max(mx, a[j]);
				dp[i] = max(dp[i], dp[j - 1] + mx * (i - j + 1));
			}
		}

		cout << dp[n] << endl;

		return 0;
	}