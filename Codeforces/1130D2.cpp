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

int set(int x, int n, int v) {
	if(v == 0) return x & !(1 << n);
	return x | (1 << n);
}

const int N = 5007;
const int M = 200007;

int ini_station[M], fin_station[M];
vi ansv;
vvi stations(N);
int n;

int compute(int source, int ini, int fin, int num) {
	int d1 = (ini - source + n) % n;
	int d2 = (fin - ini + n) % n;
	int d3 = n * (num - 1);
	return d1 + d2 + d3;
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
		
		int m, i, j, u, v;

		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> ini_station[i] >> fin_station[i];
			ini_station[i]--, fin_station[i]--;
			stations[ini_station[i]].pb(fin_station[i]);
		}

		for(i = 0; i < n; i++) {
			int ans = 0;
			for(j = 0; j < m; j++)
				ans = max(ans, compute(i, ini_station[j], fin_station[j], stations[ini_station[j]].size()));
			ansv.pb(ans);
		}

		for(auto it : ansv) cout << it << " "; cout << endl;

		return 0;
	}