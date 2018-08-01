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
int a[1007][1007], dp[1007][1007], DPRight[1007][1007], DPDown[1007][1007];
int PrefixDown[1007][1007], PrefixRight[1007][1007];
vector < pair < pair <int, int>, int> > ansv;


int check(int x, int y, int h)
{
	if(x + h > n || x - h < 1 || y + h > m || y - h < 1) return 0;

	if(PrefixRight[x][y + h] - PrefixRight[x][y] != h) return 0;
	if(PrefixRight[x][y] - PrefixRight[x][y - h - 1] != h + 1) return 0;
	if(PrefixDown[x + h][y] - PrefixDown[x][y] != h) return 0;
	if(PrefixDown[x][y] - PrefixDown[x - h - 1][y] != h + 1) return 0;

	return 1;

}

int fill(int x, int y, int h)
{

	ansv.pb(mp(mp(x, y), h));

	DPRight[x + h + 1][y]--;
	DPRight[x - h][y]++;
	DPDown[x][y + h + 1]--;
	DPDown[x][y - h]++;

	return 1;

}

int bsearch(int x, int y)
{
	int low = 1, high = 1001, mid, ans = 0;

	while(low <= high)
		{
			mid = (low + high) / 2;

			if(check(x, y, mid)) {
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
				PrefixRight[i][j] = PrefixRight[i][j - 1] + a[i][j];

		for(i = 1; i <= m; i++)
			for(j = 1; j <= n; j++)
				PrefixDown[j][i] = PrefixDown[j - 1][i] + a[j][i];
		

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				if(a[i][j])
					bsearch(i, j);


		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				DPDown[i][j] = DPDown[i][j - 1] + DPDown[i][j];

		for(i = 1; i <= m; i++)
			for(j = 1; j <= n; j++)
				DPRight[j][i] = DPRight[j - 1][i] + DPRight[j][i];


		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= m; j++) 
					if(a[i][j] && !(DPRight[i][j] || DPDown[i][j])) ans = 0;
			}

		if(!ans) {
			cout << -1 << endl;
			return 0;
		}

		cout << ansv.size() << endl;
		for(i = 0; i < ansv.size(); i++) cout << ansv[i].f.f << " " << ansv[i].f.s << " " << ansv[i].s << endl;
		return 0;
	}