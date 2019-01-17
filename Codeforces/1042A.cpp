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

const int N = 107;
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
		
		int n, m, i, j, u = 0, v = INT_MAX;
		vi vs;

		cin >> n >> m;

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			vs.pb(a[i]);
			u = max(u, a[i]);
		}

		u = u + m;

		while(m--) {
			sort(vs.begin(), vs.end());
			vs[0]++;
		}

		sort(vs.begin(), vs.end());
		// for(auto it : vs) cout << it << " "; cout << endl;

		cout << vs[vs.size() - 1] << " " << u << endl;


		return 0;
	}