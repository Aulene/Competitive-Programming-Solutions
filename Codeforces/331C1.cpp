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

int dp[1000007];

int recur(int n) {

	if(n < 0) return INT_MAX;
	if(n == 0) return 0;
	if(dp[n] != -1) return dp[n];

	// cout << n << endl;

	int x = n;

	int ans = INT_MAX;

	while(x) {
		int digit = x % 10;
		x /= 10;
		if(!digit) continue;
		ans = min(ans, recur(n - digit));
	}

	return dp[n] = 1 + ans;
}

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

		cin >> n;

		for(i = 0; i < 1000007; i++) dp[i] = -1;

		int ans = recur(n);
		cout << ans << endl;


		return 0;
	}