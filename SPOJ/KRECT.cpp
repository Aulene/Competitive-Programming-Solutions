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

int a[107][107];
int dp[107][107][107];

int recur(int x, int y)
{
	if(x == 0 || y == 0) return 0;

	for(i = 1; i <= 26; i++)
		dp[x][y][i] = dp[x][y - 1][i] + dp[x - 1][y][i] - dp[x - 1][y - 1][i];

}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, k, i, j, u, v;
		char x;

		cin >> n >> m >> k;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++) cin >> x, a[i][j] = x - 'A' + 1;
		

		return 0;
	}