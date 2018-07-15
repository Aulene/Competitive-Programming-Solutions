#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[107][107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, k, u, v;

		cin >> n >> k;

		if(k <= n - 2)
			{
				for(i = 1; i <= k / 2; i++) 
					a[1][n / 2 - i] = a[1][n / 2 + i] = 1;
				if(k & 1) 
					a[1][n / 2] = 1;
			}
		else
			{
				for(i = 1; i < n - 1; i++) 
					a[1][i] = 1;
				k -= n - 2;
				
				for(i = 1; i <= k / 2; i++) 
					a[2][n / 2 - i] = a[2][n / 2 + i] = 1;
				if(k & 1) 
					a[2][n / 2] = 1;
			}
		
		cout << "YES" << endl;
			
		for(i = 0; i < 4; i++)
			{
				for(j = 0; j < n; j++) 
					{
						if(a[i][j] == 1) cout << "#";
						else cout << ".";
					}
				cout << endl;
			}

		return 0;
	}