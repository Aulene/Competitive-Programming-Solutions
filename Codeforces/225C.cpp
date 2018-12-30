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

const int N = 1007;

int a[N][N], dp1[N], dp2[N];
int w[N], b[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, x, y, i, j, u, v;
		char c;

		cin >> n >> m >> x >> y;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) {
				cin >> c;
				if(c == '#') a[i][j] = 1;
			}

		for(j = 1; j <= m; j++) {
			for(i = 1; i <= n; i++)
				if(a[i][j] == 0) w[j]++;
				else b[j]++;
		}

		for(i = 1; i <= m; i++) w[i] = w[i - 1] + w[i];
		for(i = 1; i <= m; i++) b[i] = b[i - 1] + b[i];

		for(i = 1; i <= m; i++) dp1[i] = dp2[i] = INT_MAX;

		for(i = 1; i <= m; i++) {
			
			// for(j = max(0LL, i - y); j <= i - x; j++)
			// 	dp1[i] = min(dp1[i], dp2[j] + (w[i] - w[j - 1]));
			
			for(j = x; j <= y; j++)
				if(i - j >= 0) dp1[i] = min(dp1[i], dp2[i - j] + (w[i] - w[i - j]));
			
			// for(j = max(0LL, i - y); j <= i - x; j++)
			// 	dp2[i] = min(dp2[i], dp1[j] + (b[i] - b[j - 1]));

			for(j = x; j <= y; j++)
				if(i - j >= 0) dp2[i] = min(dp2[i], dp1[i - j] + (b[i] - b[i - j]));
		}

		// cout << "W = "; for(i = 1; i <= m; i++) cout << w[i] << " "; cout << endl;
		// cout << "B = "; for(i = 1; i <= m; i++) cout << b[i] << " "; cout << endl;
		// cout << "DP1 = "; for(i = 1; i <= m; i++) cout << dp1[i] << " "; cout << endl;
		// cout << "DP2 = "; for(i = 1; i <= m; i++) cout << dp2[i] << " "; cout << endl;
		
		int ans = min(dp1[m], dp2[m]);

		cout << ans << endl;
		return 0;
	}

	// for(j = x; j <= y; j++)
	// 			if(i - j >= 0) dp1[i] = min(dp1[i], dp2[i - j] + (w[i] - w[i - j - 1]));