#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 100000000
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int h[107][107][17], f[107][107][17];
int n1, n2, k1, k2;

int recur(int n1, int n2, int x)
{
	int ans = 0;

	if(x == 1)
		{
			if(f[n1][n2][x] != -1) 
				return f[n1][n2][x];

			for(int i = 1; i <= min(k2, n2); i++)
				f[n1][n2][i] = recur(n1, n2 - i, 2);
		}
	else
		{
			for(int i = 1; i <= min(k2, n2); i++)
				h[n1][n2][i] = recur(n1, n2 - i, 1);
		}

}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, k, u, v;

		cin >> n1 >> n2 >> k1 >> k2;

		for(i = 0; i < 107; i++)
			for(j = 0; j < 107; j++) 
				for(k = 0; k < 17; k++) h[i][j][k] = f[i][j][k] = -1;

		return 0;
	}