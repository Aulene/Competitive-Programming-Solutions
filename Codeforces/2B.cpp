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
#define lli long long int
#define pli pair <lli, lli> 
const int N = 1002;
const pi zp = mp(0, 0);
const pi up = mp(-1, 0);
const pi lt = mp(0, -1);

pi a[N][N], par[N][N][2];
pli dp[N][N][2];

pli sum(pli a, pi b) { return mp(a.f + b.f, a.s + b.s); }

pi duck(int n) {
	pi ans = zp;
	while(n % 2 == 0) ans.f++, n /= 2;
	while(n % 5 == 0) ans.s++, n /= 5;
	return ans;
}

int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, k, u, v;

		scanf("%d", &n);

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++) {
				scanf("%d", &u);
				a[i][j] = duck(u);
			}

		for(i = 0; i <= n; i++)
			for(j = 0; j <= n; j++)
				for(k = 0; k < 2; k++) dp[i][j][k] = mp(mod, mod);

		for(i = 0; i < 2; i++) 
			dp[0][0][i] = dp[0][1][i] = dp[1][0][i] = zp;

		// for(i = 1; i <= n; i++)
		// 	{for(j = 1; j <= n; j++) cout << a[i][j].f << "," << a[i][j].s << " "; cout << endl; }

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				pli p1 = sum(dp[i - 1][j][0], a[i][j]);
				pli p2 = sum(dp[i][j - 1][0], a[i][j]);
				
				// cout << "i,j = " << i << "," << j << endl;
				// cout << "p1 = " << p1.f << "," << p1.s << endl;
				// cout << "p2 = " << p2.f << "," << p2.s << endl;
				
				if(p1.f < p2.f) {
					dp[i][j][0] = p1;
					par[i][j][0] = mp(-1, 0);
				}
				else {
					dp[i][j][0] = p2;
					par[i][j][0] = mp(0, -1);
				}
			}
		}
		
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				pli p1 = sum(dp[i - 1][j][1], a[i][j]);
				pli p2 = sum(dp[i][j - 1][1], a[i][j]);
				if(p1.s < p2.s) {
					dp[i][j][1] = p1;
					par[i][j][1] = mp(-1, 0);
				}
				else {
					dp[i][j][1] = p2;
					par[i][j][1] = mp(0, -1);
				}
			}
		}

		// cout << "TWOS" << endl;
		// for(i = 1; i <= n; i++)
		// 	{for(j = 1; j <= n; j++) cout << dp[i][j][0].f << "," << dp[i][j][0].s << " "; cout << endl; }
		// cout << "FIVES" << endl;
		// for(i = 1; i <= n; i++)
		// 	{for(j = 1; j <= n; j++) cout << dp[i][j][1].f << "," << dp[i][j][1].s << " "; cout << endl; }

		// cout << dp[n][n][0].f << " " << dp[n][n][0].s << endl;
		// cout << dp[n][n][1].f << " " << dp[n][n][1].s << endl;		
		
		lli twos = min(dp[n][n][0].f, dp[n][n][0].s);
		lli fives = min(dp[n][n][1].f, dp[n][n][1].s);
		lli ans = min(twos, fives);
		lli x = n, y = n;
		string s = "";

		if(twos < fives) {
			while(x != 1 || y != 1) {
				pi pr = par[x][y][0];
				if(pr == up) s += 'D';
				else s += 'R';
				x += pr.f, y += pr.s;
			}
		}
		else {
			while(x != 1 || y != 1) {
				pi pr = par[x][y][1];
				if(pr == up) s += 'D';
				else s += 'R';
				x += pr.f, y += pr.s;
			}
		}

		printf("%lld\n", ans);
		for(i = s.size() - 1; i >= 0; i--) printf("%c", s[i]);
		// printf("%lld\n", ans);
		// cout << s << endl;
		return 0;
	}