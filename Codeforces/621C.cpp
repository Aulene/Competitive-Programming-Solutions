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
#define ld long double

const int N = 100007;
vi vs;

int a[N], cnt[N];

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
		
		int n, m, i, j;
		ld sum = 0.0, denom = 1;
		int u, v;

		cin >> n >> m;

		for(i = 0; i < n; i++) {
			cin >> u >> v;
			a[i] = v - u + 1;
			cnt[i] = (v / m) - ((u - 1) / m);
		}

		// for(i = 0; i < n; i++) cout << cnt[i] << " "; cout << endl;
		// for(i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
			
		for(i = 0; i < n; i++) denom *= a[i];

		for(i = 0; i < n; i++) {
			int n1 = (i) % n;
			int n2 = (i + 1 + n) % n;

			ld v = (cnt[n1] * a[n2]) + (cnt[n2] * a[n1]) - (cnt[n1] * cnt[n2]);
			ld u = a[n1] * a[n2];

			// cout << n1 << " " << n2 << endl;
			// cout << u << " " << v << endl;

			sum += ((ld) v / u);
		}

		printf("%.16Lf\n", 2000.0 * sum);

		return 0;
	}