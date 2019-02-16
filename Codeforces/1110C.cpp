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
		
		int n, m, q, i, j, u, v;

		cin >> q;

		while(q--) {
			cin >> n;

			m = 0;

			// cout << (int)(log2l(n)) << endl;
			// for(i = (int)(log2l(n)); i >= 0; i--) 
			// 	cout << ((n & (1 << i)) ? 1 : 0); cout << endl;

			for(i = 0; i < (int)(log2l(n)) + 1; i++)
				if((n & (1 << i)) == 0) m = m | (1 << i);
			
			if(m == 0) {
				m = 1;
				for(i = 2; i <= sqrt(n); i++) {
					if(n % i == 0) {
						m = max(m, max(n / i, i));
						break;
					}
				}
			}
			// cout << n << " " << m << endl;
			// cout << m << endl;

			int ans = gcd(n ^ m, n & m);
			cout << ans << endl;
		}	
		return 0;
	}