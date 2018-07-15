#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[57][57];
int prow[57], pcol[57];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string r, c;
		int n, m, i, j, fuck = 0, anus;
		bool ansx = 1;

		cin >> r >> c;
		n = r.size(), m = c.size();
		
		for(i = 0; i < 57; i++)
			for(j = 0; j < 57; j++) a[i][j] = 1;

		for(i = 0; i < n; i++)
			{
				for(j = fuck; j < m; j++)
					{
						if(r[i] == '1' && c[j] == '1')
							{
								a[i][j] = 0;
								fuck = j + 1;
								break;
							}
					}
			}
			
		for(i = 0; i < n; i++)
			{
				for(j = 0; j < m; j++) prow[i] += a[i][j];

				anus = prow[i] % 2;
				if(!((r[i] == '1' && anus == 1) || (r[i] == '0' && anus == 0))) ansx = 0;
			}

		for(i = 0; i < m; i++)
			{
				for(j = 0; j < n; j++) pcol[i] += a[j][i];

				anus = pcol[i] % 2;
				if(!((c[i] == '1' && anus == 1) || (c[i] == '0' && anus == 0))) ansx = 0;
			}

		if(!ansx) cout << -1 << endl;
		else
			{
				for(i = 0; i < n; i++)
					{
						for(j = 0; j < m; j++) cout << a[i][j]; cout << endl;
					}
			}
		return 0;
	}