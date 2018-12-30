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
int a[N][N], b[N][N];
vpi ansv, ansv2;

void print(vpi vs) {
	cout << vs.size() << endl;
	for(auto it : vs) {
		if(it.f == 1) cout << "row " << it.s << endl;
		else cout << "col " << it.s << endl;
	}
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
		
		int n, m, i, j, u, v;
		int ansx = 1, ansx2 = 1;

		cin >> n >> m;

		for(i = 1; i <= n; i++) {
			v = INT_MAX;
			for(j = 1; j <= m; j++) cin >> a[i][j], b[i][j] = a[i][j], v = min(v, a[i][j]);
			if(v != INT_MAX) { for(j = 1; j <= m; j++) a[i][j] -= v; }
			if(v != INT_MAX)
				while(v > 0) ansv.pb({1, i}), v--;
		}

		for(i = 2; i <= n; i++) {
			for(j = 1; j <= m; j++)
				if(a[i][j] != a[i - 1][j]) ansx = 0;		
		}

		for(i = 1; i <= m; i++)
			if(a[1][i] > 0) while(a[1][i] > 0) ansv.pb({2, i}), a[1][i]--;

		for(i = 1; i <= m; i++) {
			v = INT_MAX;
			for(j = 1; j <= n; j++) v = min(v, b[j][i]);
			if(v != INT_MAX) { for(j = 1; j <= n; j++) b[j][i] -= v; }
			if(v != INT_MAX) while(v > 0) ansv2.pb({2, i}), v--;
		}

		for(i = 2; i <= m; i++)
			for(j = 1; j <= n; j++)
				if(b[j][i] != b[j][i - 1]) ansx2 = 0;

		for(i = 1; i <= n; i++)
			if(b[i][1] > 0) while(b[i][1] > 0) ansv2.pb({1, i}), b[i][1]--;

		// for(i = 1; i <= n; i++) {
		// 	for(j = 1; j <= m; j++) cout << a[i][j] << " "; cout << endl;
		// }

		if(!ansx && !ansx2) cout << -1 << endl;
		else {
			if(ansx && ansx2) {
				if(ansv.size() < ansv2.size()) print(ansv);
				else print(ansv2);
			}
			else if(ansx) print(ansv);
			else print(ansv2);
		}
		return 0;
	}