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

char a[507][507];
int cracked[507][507], vis[507][507];
int xa[] = {1, 0, -1, 0}, ya[] = {0, 1, 0, -1};
bool ans = 0;
int r2, c2, n, m;

int bfs(int r1, int c1) {
	queue < pi > q;
	q.p({r1, c1});

	while(!q.empty()) {
		pi pz = q.front(); q.pop();

		int r = pz.f, c = pz.s;

		if(vis[r][c]) continue;
		vis[r][c] = 1;

		for(int i = 0; i < 4; i++) 
			q.p({r + xa[i], c + ya[i]});
	}

	if(vis[r2][c2]) return 1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, r1, c1;

 		cin >> n >> m;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) 
				{
					cin >> a[i][j];
					if(a[i][j] == 'X') cracked[i][j] = 1;
				}

		cin >> r1 >> c1 >> r2 >> c2;

		cracked[r1][c1] = 0;

		ans = bfs(r1, c1);

		if(ans) cout << "YES\n";
		else cout << "NO\n";
		return 0;
	}