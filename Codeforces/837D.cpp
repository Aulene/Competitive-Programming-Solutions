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

const int N = 207;
const int M = 20007;

long long int a[N];
ppi vs[N];
int dp[7][N][M];

ppi fact(long long int n) {
	ppi pz = mp(zp, 0);
	while(n % 2 == 0) pz.f.f++, n /= 2;
	while(n % 5 == 0) pz.f.s++, n /= 5;
	int u = min(pz.f.f, pz.f.s);
	pz.s += u;
	pz.f.f -= u, pz.f.s -= u;
	return pz;
}

ppi sum(ppi a, ppi b) 
{ 
	int mv = min(a.f.f + b.f.f, a.f.s + b.f.s);
	return mp(mp(a.f.f + b.f.f - mv, a.f.s + b.f.s - mv), a.s + b.s + mv); 
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
		
		int n, m, i, j, k, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= n; i++) vs[i] = fact(a[i]);

		for(i = 1; i <= n; i++) {
			dp[1][0][vs[i].s] = max(dp[1][0][vs[i].s], vs[i].f);
			dp[1][0][vs[i].s] = max(dp[1][0][vs[i].s], dp[i][0][vs[i].s]);	
		}

		for(j = 2; j <= n; j++) {

			for(i = 1; i <= n; i++) {
				for(k = 1; k <= M; k++) {
					dp[1][j + 1][k + vs[i].s] = max(dp[1][j + 1][k + vs[i].s], dp[0][j][k] + vs[i].f);
					dp[1][j][k] = max(dp[1][j][k], dp[0][j][k]);
				}
			}

			for(i = 1; i <= n; i++)
		}

		cout << mx.s << endl;
		return 0;
	}