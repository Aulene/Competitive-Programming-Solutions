#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

int dp[1007][2007][2][2]; // dp[i][j][x][y] = number of sequences of length i with k colorings ending with [x][y]
int n, m;

int recur(int idx, int mx, int x, int y)
{
	if(idx > n)
		{
			if(x == y) return 1;
			return 2;
		}

	int ans = 0;

	if(x == y)
		{
			ans = (1 + recur(i + 1, j + 1, !x, !y)) + recur(i + 1, j + 1, x, y);
		}

} 

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int i, j, u, v;

		cin >> n >> m;


		return 0;
	}