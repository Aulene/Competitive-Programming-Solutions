/*
 ID: aussyle1
 PROG: stamps
 LANG: C++
 */

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

const int N = 57;
const int M = 2000007;
int a[N], dp[M];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		ifstream cin ("stamps.in");
		ofstream cout ("stamps.out");
		
		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 1; i < M; i++) dp[i] = 100007;
		for(i = 1; i <= m; i++) cin >> a[i], dp[a[i]] = 1;

		for(i = 1; i < M; i++) {
			if(dp[i] != 100007) {

				if(dp[i] > n) break;
				for(j = 1; j <= m; j++) 
					dp[i + a[j]] = min(dp[i + a[j]], 1 + dp[i]);
			} 
			else break;
		}

		for(i = 1; i < M; i++) {
			if(dp[i] <= n) ans++;
			else break;
		}

		cout << ans << endl;

		return 0;
	}