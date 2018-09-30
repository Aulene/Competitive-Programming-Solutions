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

int inv(int a, int b)
{ return 1 < a ? b - inv(b % a, a) * b / a : 1; }

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");


		int t, n, m, i, j, k, u, v, w, x, y, ans;

		cin >> t;

		for(int T = 1; T <= t; T++)
			{
				cin >> n >> m;
				ans = 0;
				u = min(n, m);

				v = u - 1;
				w = (2 * u - 1 + mod) % mod;
				
				ans = 0;

				x = 6 * ((m * n) % mod);
				ans = (ans + x) % mod;
				cout << x << endl;

				x = (3 * ((v * ((u * m) % mod)) % mod)) % mod;
				ans = ((ans - x + mod) % mod);
				cout << x << endl;

				x = (3 * ((v * ((u * n) % mod)) % mod)) % mod;
				ans = ((ans - x + mod) % mod);
				cout << x << endl;

				x = (u * v) % mod;
				x = (x * w) % mod;
				cout << x << endl;

				ans = (ans + x) % mod;

				v = inv(6, mod);
				ans = (ans * v) % mod;

				cout << "Case #" << T << ": " << ans << endl;
			}
		return 0;
	}