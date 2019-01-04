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
int a[N], pre[N];
int dp[N][N];

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
		
		int n, m, k, i, j, u, v;

		cin >> n >> m >> k;

		for(i = 1; i <= n; i++) 
			cin >> a[i], pre[i] = pre[i - 1] + a[i];

		for(i = 1; i <= k; i++)
			for(j = 1; j <= n; j++)
				dp[j][i] = max(dp[max(0LL, j - m)][i - 1] + pre[j] - pre[max(0LL, j - m)], dp[j - 1][i]);

		cout << dp[n][k] << endl;

		return 0;
	}