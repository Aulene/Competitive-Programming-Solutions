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
#define zp mp(0, 0)

const int N = 200007;

int a[N];
map <int, int> dp, par, pv;
vi vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, ans = 0, ansidx;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++) {

			pv[a[i]] = i;

			if(dp[a[i]] < 1 + dp[a[i] - 1])
				dp[a[i]] = 1 + dp[a[i] - 1];

			if(ans < dp[a[i]]) {
				ans = dp[a[i]];
				ansidx = a[i];
			}

		}

		// for(auto it : dp) cout << "Num = " << it.f << " Ans = " << it.s << endl;
	
		for(i = n; i >= 1; i--) {
			if(a[i] == ansidx && ans > 0) {
				vs.pb(i);
				ansidx--; ans--;
			}
		}		

		reverse(vs.begin(), vs.end());

		cout << vs.size() << endl;
		for(auto it : vs) cout << it << " "; cout << endl;

		return 0;
	}