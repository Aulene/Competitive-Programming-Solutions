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

const int N = 10000007;

int good[N], fact[N];

int g(int n, int x, int y) {
	while(n) {
		int u = n % 10;
		if(u != x && u != y) return 0;
		n /= 10;
	}
	return 1;
}

int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        int q = a / m; 
        int t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
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
		
		int n, m, i, j, u, v, ans = 0;

		cin >> u >> v >> n;

		for(i = 1; i < N; i++)
			good[i] = g(i, u, v);
		
		fact[0] = 1;
		for(i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % mod;

		for(i = 0; i <= n; i++) {
			int sum = u * i + v * (n - i);

			if(good[sum]) {
				// cout << i << " " << sum << endl;

				int num = fact[n];
				int j = modInverse((fact[n - i] * fact[i]) % mod, mod);
				j = (num * j) % mod;

				ans = (ans + j) % mod;
			}
		}

		cout << ans << endl;
		return 0;
	}