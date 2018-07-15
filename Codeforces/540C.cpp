#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

char a[507][507];
int cracked[507][507], vis[507][507];
int xa[] = {1, 0, -1, 0}, ya[] = {0, 1, 0, -1};
bool ans = 0;
int r2, c2, n, m;

int recur(int x, int y)
{
	if(x < 1 || x > n || y < 1 || y > m) 
		return 0;

	if(x == r2 && y == c2 && cracked[x][y]) 
		ans = 1;

	if(vis[x][y]) return 0;

	if(ans) 
		return 0;

	if(cracked[x][y]) 
		return 0;

	cracked[x][y] = 1;

	for(int i = 0; i < 4; i++)
			recur(x + xa[i], y + ya[i]);

	cracked[x][y] = 0;
	vis[x][y] = 1;

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

		recur(r1, c1);

		if(ans) cout << "YES\n";
		else cout << "NO\n";
		return 0;
	}