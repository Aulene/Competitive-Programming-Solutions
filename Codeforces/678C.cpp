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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, a, b, p, q, i, j, u, v, w, ans = 0;	

		cin >> n >> a >> b >> p >> q;

		if(q > p) {
			swap(a, b);
			swap(p, q);
		}

		u = (n / a) * p;
		v = (n / b) * q;

		int lcm = (a * b) / (gcd(a, b));

		// cout << u << " " << v << " " << lcm << endl;

		ans = u + v - ((n / lcm) * q);

		cout << ans << endl;

		return 0;
	}