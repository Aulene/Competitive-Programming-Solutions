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

const int N = 1007;
int c[N], a[N];
vi vs;

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
		
		int n, m, i, j, u = 0, v = 0;
		vi vs;

		cin >> n;
		for(i = 1; i <= n; i++) {
			cin >> a[i];
			(a[i] < 0) ? v++ : v;
		}

		for(i = 1; i <= n; i++) {
			if(a[i] > 0) {
				for(j = i + 1; j <= n; j++) {
					if(!c[j] && a[i] == -a[j]) {
						c[j] = 1;
						break;
					}
				}
			}
		}

		for(i = 1; i <= n; i++)
			if(a[i] == 0) {
				for(j = i + 1; j <= n; j++) {
					if(!c[j] && a[j] < 0) {
						vs.pb(-a[j]);
						c[j] = 1;
						break;
					}
				}

				if(j == n + 1) vs.pb(1);
			}

		// for(i = 1; i <= n; i++) cout << c[i] << " "; cout << endl;


		for(i = 1; i <= n; i++) 
			if(c[i]) u++;

		// cout << u << " " << v << endl;

		if(u == v) {
			cout << "Yes\n";
			for(auto it : vs) cout << it << " "; cout << endl;
		}
		else cout << "No" << endl;

		return 0;
	}