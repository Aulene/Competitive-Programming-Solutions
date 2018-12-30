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

const int N = 57;

int a[N][N], b[N][N];
bool vis[N][N], vis2[N][N];
int xx[] = {1, 0, -1, 0}; 
int yy[] = {0, 1, 0, -1};

void fill(int x, int y, int n, int m) {
	if(x < 1 || x > n || y < 1 || y > m) return;
	if(a[x][y]) return;
	if(vis[x][y]) return;
	vis[x][y] = 1;
	a[x][y] = 2;

	for(int i = 0; i < 4; i++)
		fill(x + xx[i], y + yy[i], n, m);
}


void fill2(int x, int y, int n, int m) {
	if(x < 1 || x > n || y < 1 || y > m) return;
	if(b[x][y]) return;
	if(vis2[x][y]) return;
	vis2[x][y] = 1;
	b[x][y] = 1;

	for(int i = 0; i < 4; i++)
		fill2(x + xx[i], y + yy[i], n, m);
}

int dfs(int x, int y, int n, int m) {
	if(x < 1 || x > n || y < 1 || y > m) return 0;
	if(a[x][y]) return 0;
	if(vis[x][y]) return 0;
	vis[x][y] = 1;

	int ans = 1;
	for(int i = 0; i < 4; i++)
		ans += dfs(x + xx[i], y + yy[i], n, m);

	return ans;
}

bool cmp(ppi a, ppi b) { return a.s < b.s; }

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
		
		int n, m, k, i, j, u, v, ans = 0;
		char c;
		vppi vs;

		cin >> n >> m >> k;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) {
				 cin >> c;
				 if(c == '*')
				 	a[i][j] = 1;
			}

		for(i = 1; i <= m; i++) 
			fill(1, i, n, m), fill(n, i, n, m);
		for(i = 1; i <= n; i++)
			fill(i, 1, n, m), fill(i, m, n, m);

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) {
				b[i][j] = a[i][j];
				vis2[i][j] = vis[i][j];
			}

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++)
				if(!a[i][j] && !vis[i][j])
				 vs.pb({{i, j}, dfs(i, j, n, m)});
		}		

		// for(auto it : vs) cout << it.f.f << " " << it.f.s << " " << it.s << endl;
		
		u = vs.size();
		sort(vs.begin(), vs.end(), cmp);

		for(auto it : vs) {
			if(u == k) break;
			ans += it.s;
			fill2(it.f.f, it.f.s, n, m);
			u--;
		}

		cout << ans << endl;

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) 
				if(b[i][j] == 1) cout << "*";
				else cout << ".";
			cout << endl;
		}

		return 0;
	}	