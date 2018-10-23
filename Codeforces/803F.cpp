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

const int N = 100007;
int mu[N], a[N], d[N], f[N];
vvi vs(N);

int powmod(int a, int b, int m) {
	int res = 1;
	while(b)
		if(b & 1) res = (res * 1ll * a) % m, --b;
		else a = (a * 1ll * a) % m,  b >>= 1;
	return res;
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
		
		int n, m, i, j, u, v, ans = 0;

		mu[1] = 1;

		for(i = 1; i < N; i++) {
			vs[i].pb(i);
			for(j = 2 * i; j < N; j += i) {
				vs[j].pb(i);
				mu[j] -= mu[i];	
			}
		}

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++)
			for(j = 0; j < vs[a[i]].size(); j++) d[vs[a[i]][j]]++;

		for(i = 1; i < N; i++) 
			f[i] = powmod(2, d[i], mod) - 1; 

		for(i = 1; i < N; i++)
			ans = (ans + (f[i] * mu[i] + mod) % mod + mod) % mod;

		cout << ans << endl;
		return 0;
	}