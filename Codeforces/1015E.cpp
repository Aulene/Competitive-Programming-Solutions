#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n, m;
int a[1007][1007], dp[1007][1007], dp2[1007][1007], dp3[1007][1007];
int pdown[1007][1007], pright[1007][1007];

vector < pair < pair <int, int>, int> > vs;

int check(int x, int y, int h)
{
	for(int i = 1; i <= h; i++)
		if(!a[x + i][y] || !a[x - i][y] || !a[x][y + i] || !a[x][y - i]) 
			return 0;
	return 1;

}

int check2(int x, int y, int h)
{
	if(x + h > n || x - h < 1 || y + h > m || y - h < 1) return 0;

	if(pright[x][y + h] - pright[x][y] != h) return 0;
	if(pright[x][y] - pright[x][y - h - 1] != h + 1) return 0;
	if(pdown[x + h][y] - pdown[x][y] != h) return 0;
	if(pdown[x][y] - pdown[x - h - 1][y] != h + 1) return 0;

	return 1;

}

int fill(int x, int y, int h)
{

	vs.pb(mp(mp(x, y), h));

	dp2[x + h + 1][y]--;
	dp2[x - h][y]++;
	dp3[x][y + h + 1]--;
	dp3[x][y - h]++;

	// for(int i = 0; i <= h; i++)
	// 	{
	// 		dp[x + i][y] = 1; 
	// 		dp[x - i][y] = 1;
	// 		dp[x][y + i] = 1;
	// 		dp[x][y - i] = 1;
	// 	}
	return 1;

}

int bsearch(int x, int y)
{
	int low = 1, high = 1001, mid, ans = 0;

	while(low <= high)
		{
			mid = (low + high) / 2;

			if(check2(x, y, mid)) {
				ans = mid;
				low = mid + 1;
			}
			else high = mid - 1;
		}

	if(ans) fill(x, y, ans);
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v;
		bool ans = 1;
		char x;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= m; j++)
					{
						cin >> x;
						if(x == '*') a[i][j] = 1;
					}
			}

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				pright[i][j] = pright[i][j - 1] + a[i][j];

		for(i = 1; i <= m; i++)
			for(j = 1; j <= n; j++)
				pdown[j][i] = pdown[j - 1][i] + a[j][i];
		

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				if(a[i][j])
					bsearch(i, j);

		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 1; j <= m; j++) 
		// 			if(a[i][j] && !dp[i][j]) ans = 0;
		// 	}

		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 1; j <= m; j++) cout << dp2[i][j] << " "; cout << endl;
		// 	}
		// cout << endl;
		
		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 1; j <= m; j++) cout << dp3[i][j] << " "; cout << endl;
		// 	}
		// cout << endl;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				dp3[i][j] = dp3[i][j - 1] + dp3[i][j];

		for(i = 1; i <= m; i++)
			for(j = 1; j <= n; j++)
				dp2[j][i] = dp2[j - 1][i] + dp2[j][i];

		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 1; j <= m; j++) cout << dp2[i][j] << " "; cout << endl;
		// 	}
		// cout << endl;
		
		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 1; j <= m; j++) cout << dp3[i][j] << " "; cout << endl;
		// 	}
		// cout << endl;

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= m; j++) 
					if(a[i][j] && !(dp2[i][j] || dp3[i][j])) ans = 0;
			}

		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 1; j <= m; j++) cout << dp[i][j] << " "; cout << endl;
		// 	}
		// cout << endl;

		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 1; j <= m; j++) cout << pright[i][j] << " "; cout << endl;
		// 	}
		// cout << endl;

		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 1; j <= m; j++) cout << pdown[i][j] << " "; cout << endl;
		// 	}

		if(!ans) {
			cout << -1 << endl;
			return 0;
		}

		cout << vs.size() << endl;
		for(i = 0; i < vs.size(); i++) cout << vs[i].f.f << " " << vs[i].f.s << " " << vs[i].s << endl;
		return 0;
	}