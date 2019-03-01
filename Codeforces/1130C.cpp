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

const int N = 57;

int grid[N][N], sp[N][N], sp2[N][N];

int xm[] = {1, 0, -1, 0};
int ym[] = {0, 1, 0, -1};

void bfs(int sp[][N], int r2, int c2, int n) {

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) sp[i][j] = INT_MAX;
	sp[r2][c2] = 0;
	
	queue < pi > q;
	q.p({r2, c2});

	while(!q.empty()) {
		pi pz = q.front(); q.pop();
		int x = pz.f, y = pz.s;	

		for(int i = 0; i < 4; i++) {
			int nx = x + xm[i], ny = y + ym[i];

			if(grid[nx][ny] != 1 && nx <= n && nx >= 1 && ny <= n && ny >= 1 && (sp[nx][ny] > 1 + sp[x][y])) {
				sp[nx][ny] = 1 + sp[x][y];
				q.p({nx, ny});
			}
		}

	}
}

int compCost(int x1, int y1, int x2, int y2) {
	int x = abs(x1 - x2);
	int y = abs(y1 - y2);
	int ans = x * x + y * y;
	return ans;
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
		
		int n, m, i, j, k, l, u, v, r1, c1, r2, c2, ans = LLONG_MAX;
		char c;

		cin >> n >> r1 >> c1 >> r2 >> c2;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++) {
				cin >> c;
				grid[i][j] = c - '0';
			}

		bfs(sp, r2, c2, n);
		bfs(sp2, r1, c1, n);
		
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {

				if(sp2[i][j] < INT_MAX) {

					for(k = 1; k <= n; k++) {
						for(l = 1; l <= n; l++) {

							if(sp[k][l] < INT_MAX) {
								int sum = compCost(i, j, k, l);
								// printf("(%lld, %lld) (%lld, %lld) %lld\n", i, j, k, l, sum);
								// printf("%lld %lld %lld\n", sp2[i][j], compCost(i, j, k, l), sp[k][l]);
								ans = min(ans, sum);
							}
							
						}
					}
				}

			}
		}


		cout << ans << endl;
		return 0;
	}