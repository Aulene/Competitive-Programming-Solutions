#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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

int a[N], pal[N][N], dp[N][N];

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
		int n, m, i, j, u, v;

		cin >> s;
		n = s.size();
		s = '.' + s;

		for(i = 1; i <= n; i++)
			a[i] = (int) (s[i] - 'a') + 1;

		for(i = 1; i <= n; i++) pal[i][i] = 1;
		for(i = 1; i < n; i++)
			if(a[i] == a[i + 1]) pal[i][i + 1] = pal[i + 1][i] = 1;

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++)
				if(j + i <= n && s[j] == s[j + i] && pal[j + 1][j + i - 1])
					pal[j][j + i] = pal[j + i][j] = 1;
		}

		for(i = 1; i <= n; i++) dp[i][i] = pal[i][i];
		for(i = 1; i < n; i++)
			dp[i][i + 1] = dp[i + 1][i] = 2 + pal[i][i + 1];

		for(i = 2; i <= n; i++) {
			for(j = 1; j <= n; j++)
				if(j + i <= n)
				dp[j][j + i] = dp[j + i][j] = pal[j][j + i] + dp[j][j + i - 1] + dp[j + 1][j + i] - dp[j + 1][j + i - 1];
		}

		// for(i = 1; i <= n; i++) {
		// 	for(j = 1; j <= n; j++) cout << pal[i][j] << " "; cout << endl;
		// } cout << endl;

		// for(i = 1; i <= n; i++) {
		// 	for(j = 1; j <= n; j++) cout << dp[i][j] << " "; cout << endl;
		// }

		cin >> m;
		
		while(m--) {
			cin >> u >> v;
			cout << dp[u][v] << endl;
		}	
		return 0;
	}