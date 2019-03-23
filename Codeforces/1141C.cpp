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
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)

#define ld long double

const int N = 200007;
int a[N], p[N], found[N];

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
		
		int n, m, i, j, u, v = 0, sum = 0;

		cin >> n;

		for(i = 2; i <= n; i++) {
			cin >> p[i];
			p[i] += p[i - 1];
			v = min(v, p[i]);
		}

		u = 1 - v;

		for(i = 1; i <= n; i++) {
			p[i] += u;
			if(p[i] < 1 || p[i] > n || found[p[i]]) { cout << -1 << endl; return 0; }
			found[p[i]] = 1;
		}

		for(i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;
		return 0;
	}