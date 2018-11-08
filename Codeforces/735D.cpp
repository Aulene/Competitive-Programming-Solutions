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

int powmod(int a, int b, int m) {
	int res = 1;
	while(b)
		if(b & 1) res = (res * 1ll * a) % m, --b;
		else a = (a * 1ll * a) % m,  b >>= 1;
	return res;
}


int miller_rabin(int n) {
	if(n == 1) return 0;

	int b = 2;
	for(int g; (g = gcd(n, b)) != 1; ++b)
		if(n > g) return 0;
	int p = 0, q = n - 1;
	while((q & 1) == 0)
		++p,  q >>= 1;
	int rem = powmod(b, q, n);
	if(rem == 1 || rem == n - 1) return 1;
	for(int i = 1; i < p; ++i) {
		rem = (rem * 1ll * rem) % n;
		if(rem == n - 1) return 1;
	}
	return 0;
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

		cin >> n;

		if(miller_rabin(n)) ans = 1;
		else if(n % 2 == 0) ans = 3;
		else ans = 2;
		
		cout << ans << endl;

		return 0;
	}