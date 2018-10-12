#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
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
#define N 300007
#define MAX 1000007

int a[N];
int prime[MAX], divs[MAX];
vi primes;

int mulmod(int a, int b, int c) { return (__int128) a * b % c; }

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

int factorize(int num)
{
	int ans = 1;
	int ini = num;
	// cout << "wtf\n";

	for(int i = 0; i < primes.size(); i++) {
		
		int v = primes[i];
		// cout << num << " " << v << endl;

		if(v * v * v > num)
			break;

		int ct = 1;
		while(num % v == 0) {
			num /= v;
			ct++;
			// cout << "ugh" << endl;
		}

		ans = ans * ct;
	}

	// cout << "anus " << num << endl;
	int u = sqrt(num);
	// cout << "sqrt " << u << endl;

	if(miller_rabin(num)) ans = ans * 2;
	else if(u * u == num && miller_rabin(u)) ans = ans * 3;
	else if(num != 1) ans = ans * 4;

	// cout << ini << " " << ans << endl;
	// cout << "outwtf\n";
	return ans;
}

void sieve()
{
	for(int i = 2; i < MAX; i++) prime[i] = i;

	for(int i = 2; i < MAX; i++) 
		if(prime[i] == i) { 
			primes.pb(i);
			for(int j = i * i; j < MAX; j += i)
				if(prime[j] == j) prime[j] = i;
		}

	// for(int i = 0; i < primes.size(); i++) cout << primes[i] << endl;
	// cout << primes.size() << endl;

	for(int i = 2; i < MAX; i++) divs[i] = factorize(i);
}

signed main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		sieve();

		int n, m, i, j, q, u, v;

		// for(i = 2; i < 12; i++) cout << i << " " << prime[i] << endl;
		// for(i = 2; i < 12; i++) cout << i << " " << divs[i] << endl;
		// for(i = 2; i <= 15; i++) cout << i << " " << miller_rabin(i) << endl;

		cin >> n >> m;

		for(i = 0; i < n - 1; i++) cin >> a[i];

		while(m--)
			{
				cin >> q >> u >> v;
			}	
		return 0;
	}