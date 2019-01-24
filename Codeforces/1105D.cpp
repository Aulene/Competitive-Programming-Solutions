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

struct player 
{ 
	int x, y, num; 

	player(int xp, int yp, int nump) {
		x = xp, y = yp, num = nump;
	}
};

const int M = 17;
const int N = 1007;

int s[M], ans[M];
int vis[N][N];

queue <player> q[17];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isok(int x, int y, int n, int m) {
	if(vis[x][y]) return false;
	if(x < 1 || x > n || y < 1 || y > m) return false;
	return true;
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
		
		int n, m, p, i, j, u, v;
		char x;

		cin >> n >> m >> p;

		for(i = 1; i <= p; i++) cin >> s[i];

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) {
				
				cin >> x;

				if(x != '.') vis[i][j] = 1;
				if(x == '#' || x == '.') continue;

				int num = (int) x - '0';
				player np(i, j, 0);

				// cout << num << " " << np.x << " " << np.y << " " << np.num << endl;
				q[num].p(np);
				ans[num]++;
			}

		int cnum = 1;

		while(true) {

			bool verif = 0;

			for(i = 1; i <= p; i++) {

				while(!q[i].empty() && q[i].front().num < cnum * s[i]) {

					player tp = q[i].front(); q[i].pop();

					for(j = 0; j < 4; j++) {
						player np(tp.x + dx[j], tp.y + dy[j], 1 + tp.num);

						if(isok(np.x, np.y, n, m)) {
							ans[i]++;
							q[i].push(np);
							vis[np.x][np.y] = 1;

							verif = 1;
						}

					}

				}

			}

			if(!verif) break;
			cnum++;
		}

		for(i = 1; i <= p; i++) cout << ans[i] << " "; cout << endl;
		return 0;
	}