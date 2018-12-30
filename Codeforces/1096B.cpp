#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
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

const int N = 200007;
const int M = 37;

int pre[N][M], suf[N][M];
int a[N];

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
		
		int n, m, i, j, u = 0, v = 0, ans = 1;
		string s;

		cin >> n >> s;

		for(i = 1; i <= n; i++)
			a[i] = (int) (s[i - 1] - 'a');

		// for(i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;

		i = 1, j = n;
		while(a[i] == a[i + 1] && i <= n) { i++; }
		while(a[j] == a[j - 1] && j >= 1) { j--; }

		// cout << i << " " << j << endl;
		if(a[1] == a[n]) {
			if(i < j) ans = (ans + (i * (n - j + 1)) % mod) % mod;
			else {
				ans = (n * (n + 1)) % mod;
				ans = (ans * modInverse(2, mod)) % mod;
				cout << ans << endl;
				return 0;
			}
		}
		ans = (ans + (n - j + 1)) % mod;
		ans = (ans + i) % mod;

		// cout << i * (n - j + 1) << " " << n - j + 1 << " " << i << endl;

		cout << ans << endl;

		return 0;
	}