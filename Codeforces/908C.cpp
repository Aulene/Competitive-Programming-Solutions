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
#define ld long double

const int N = 100007;

ld a[N];

vector < pair <ld, ld> > vs;

void solve(ld x, ld r) {
	ld ans = 1.0 * r;
	
	for(auto it : vs) {
		ld x1 = it.f, y1 = it.s;
		
		// cout << x1 << " " << y1 << endl;

		if(abs(x1 - x) <= ((ld) (2.0 * r)))
			ans = max(ans, (ld) y1 + ((ld) sqrt((ld) (((ld) ((ld) 4.0 * r * r)) - ((ld) (abs((ld) (x - x1)) * abs((ld) (x - x1))))))));
	}

	// cout << pz.f << " " << pz.s << endl;

	vs.pb({x, ans});
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
		
		ld n, m, j, u, v;
		int i;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];
		vs.pb({a[1] * 1.0, m * 1.0});
		for(i = 2; i <= n; i++) solve(a[i], m);

		for(auto it : vs) printf("%0.16Lf ", it.s);
		return 0;
	}