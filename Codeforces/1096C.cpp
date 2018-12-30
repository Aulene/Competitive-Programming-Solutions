#include <bits/stdc++.h>

using namespace std;

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
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

const long double ep = 1e-9;
const int N = 100007;

int a[N], b[N];

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
		
		int m, i, j, l, r, u = 0, v;
		double n, x, fx, y;

		vi ansv;

		cin >> m;

		while(m--) {
			int ansx = 0;

			cin >> n;
			x = (double) 180.0 / n;

			l = 2, r = 0;
			while(((int) round(x)) != x) {
				r++;
				x /= (double) r;
				x *= (double) l;
				l++;
				if (l >= N) {
					ansv.pb(-1);
					ansx = 1;
					break;
				}
			}

			if(ansx) continue;

			fx = 180 - n;
			y = x;

			while (fx <= 180 / x) x += y; y = x;
			while (x < 3) x += y;

			ansv.pb(x);
		}

		for(auto it : ansv) cout << it << endl;

		return 0;
	}