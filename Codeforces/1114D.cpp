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

vi vs, vs2;
int dp[N], dpPrev[N];

int lcs(vi vs, vi vs2, int n)
{
	int i, j, k, ans = 1;
	int x = 0;

	for(i = 1; i <= n; i++) {

		for(j = 1; j <= n; j++) {
			if(vs[i - 1] == vs2[j - 1]) dp[j] = dpPrev[j - 1] + 1;
			else dp[j] = max(dpPrev[j], dp[j - 1]);	
		}

		for(j = 1; j <= n; j++)
			dpPrev[j] = dp[j], dp[j] = 0;
	}

	return dpPrev[n];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		int n, m, i, j, u, v;

		cin >> n >> v;
		vs.pb(v);

		for(i = 2; i <= n; i++) {
			cin >> u;
			if(u != v) vs.pb(u), v = u;
		}

		vs2 = vs;
		reverse(vs2.begin(), vs2.end());
		n = ((int) vs2.size());

		int ans = lcs(vs, vs2, n);

		cout << n - (ans + 1) / 2 << endl;
		return 0;
	}