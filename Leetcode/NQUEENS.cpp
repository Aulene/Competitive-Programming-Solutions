#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

void place(int a[][1007], int row, int col, int n)
{
	int u = row, v = col;

	a[row][col]++;

	for(int i = 1; i <= n; i++)
		{
			u = row + i, v = col + i;
			if(u >= 1 && u <= n && v >= 1 && v <= n) a[u][v]++;
			u = row + i, v = col - i;
			if(u >= 1 && u <= n && v >= 1 && v <= n) a[u][v]++;
			u = row - i, v = col + i;
			if(u >= 1 && u <= n && v >= 1 && v <= n) a[u][v]++;
			u = row - i, v = col - i;
			if(u >= 1 && u <= n && v >= 1 && v <= n) a[u][v]++;
		}

	for(int i = 1; i <= n; i++)
		a[row][i]++;

	for(int i = 1; i <= n; i++)
		a[i][col]++;
	
}

void unplace(int a[][1007], int row, int col, int n)
{
	int u = row, v = col;

	a[row][col]--;

	for(int i = 1; i <= n; i++)
		{
			u = row + i, v = col + i;
			if(u >= 1 && u <= n && v >= 1 && v <= n) a[u][v]--;
			u = row + i, v = col - i;
			if(u >= 1 && u <= n && v >= 1 && v <= n) a[u][v]--;
			u = row - i, v = col + i;
			if(u >= 1 && u <= n && v >= 1 && v <= n) a[u][v]--;
			u = row - i, v = col - i;
			if(u >= 1 && u <= n && v >= 1 && v <= n) a[u][v]--;
		}

	for(int i = 1; i <= n; i++)
		a[row][i]--;

	for(int i = 1; i <= n; i++)
		a[i][col]--;
	
}

int recur(int a[][1007], int row, int n)
{
	if(row > n) return 1;

	int ans = 0;

	for(int i = 1; i <= n; i++) 
		{
			if(!a[row][i])
				{
					place(a, row, i, n);
					ans += recur(a, row + 1, n);
					unplace(a, row, i, n);
				}
		}
	return ans;
}

int totalNQueens(int n)
{
	int a[1007][1007];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) a[i][j] = 0;

	int ans = recur(a, 1, n);
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n;
		cout << totalNQueens(n) << endl;

		return 0;
	}