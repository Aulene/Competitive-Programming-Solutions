#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int unsigned long long int
#define ull int
#define mod 10000000000ULL
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

inline int modMul(const int x, const int y) {
	if (x > (1<<30) && y > (1 << 30))
		return ((x >> 30) * ((y << 30) % mod) + y * (x & ((1 << 30) - 1))) % mod;
	int z = x * y;
	if (z >= mod)
		z %= mod;
	return z;
}

int powmod(int a, int b, int m) {
	int res = 1;
	while(b)
		if(b & 1) res = (modMul(res, a)) % m, --b;
		else a = (modMul(a, a)) % m,  b >>= 1;
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n;
		cin >> n;
		int sum = 0;

		for(int i = 1; i <= n; i++) {
			int val = powmod(i, i, mod);
			sum = (sum + val) % mod;
		}

		cout << sum << endl;

		return 0;
	}