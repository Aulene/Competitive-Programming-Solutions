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

const int N = 1000007;

int a[N], dp[N];
vi pv;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
			

		int n, i, j, u, v, it, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		dp[0] = 1;

		for(i = 1; i <= n; i++) {

			pv.clear();

			for(j = 1; j <= sqrt(a[i]); j++) {
				if(a[i] % j == 0) {
					pv.pb(j);
					if(j != sqrt(a[i])) pv.pb(a[i] / j);
				}
			}

			sort(pv.begin(), pv.end());

			for(j = pv.size() - 1; j >= 0; j--) {
				it = pv[j];
				dp[it] = (dp[it] + dp[it - 1]) % mod;
			}
 		}

		for(i = 1; i < N; i++) ans = (ans + dp[i]) % mod;

		cout << ans << endl;

		return 0;
	}