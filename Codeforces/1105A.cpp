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

int a[N];

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
		
		int n, m, i, j, u, v, a1 = 0, a2 = LLONG_MAX;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];
			
		for(i = 1000; i >= 1; i--) {

			u = 0;

			for(j = 1; j <= n; j++) {

				v = 1001;
				v = min(v, abs(a[j] - i));
				v = min(v, abs(a[j] - (i + 1)));
				v = min(v, abs(a[j] - (i - 1)));

				u += v;
			}

			if(u < a2) {
				a2 = u;
				a1 = i;
			}
		}

		cout << a1 << " " << a2 << endl;

		return 0;
	}