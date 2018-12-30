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

const int N = 100007;
int a[N], dp[N];
multiset <int> mx;
// POWMOD - Computing a^b % m
int powmod(int a, int b, int m) {
	int res = 1;
	while(b)
		if(b & 1) res = (res * 1ll * a) % m, --b;
		else a = (a * 1ll * a) % m,  b >>= 1;
	return res;
}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v, sum = 0, num = 0, denom = 0;

		cin >> n >> m;
		for(i = 1; i <= n; i++) cin >> a[i], sum += a[i];

		for(i = 1; i <= n; i++) {
			dp[i] = sum - a[i];
			mx.insert(dp[i]);
		}

		denom = sum;

		// for(auto it : mx) cout << it << " "; cout << endl; 

		while(true) {
			u = *mx.begin();
			v = mx.count(u);
			mx.erase(u);
			// num = num + u;	

			// cout << "u, v, num = " << u << " " << v << " " << num << endl;

			if(v % m == 0) {
				v /= m;
				// int u1 = mx.count(v);
				// mx.erase(u1);
				// u1++;
				while(v--) mx.insert(u + 1);
			}
			else {
				num = u;
				break;
			}
		}

		// cout << num << " " << denom << endl;
		
		j = min(num, denom);
		int ans = powmod(m, j, mod);

		cout << ans << endl;

		return 0;
	}