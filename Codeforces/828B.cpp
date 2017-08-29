#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

char a[107][107];

signed main()
	{
		int n, m, i, j;
		int white = 0, black = 0;
	
		int maxm, ans, size, h, w;

		cin >> n >> m;
		
			int maxi = 0, mini = n - 1, maxj = 0, minj = m - 1;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				{
					cin >> a[i][j];

					if(a[i][j] == 'B')
						black++;
				}

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				if(a[i][j] == 'B')
					{
						maxi = max(maxi, i);
						mini = min(mini, i);
						minj = min(minj, j);
						maxj = max(maxj, j);
					}

		h = maxi - mini + 1, w = maxj - minj + 1;
		// cout << maxi << " " << mini << " " << maxj << " " << minj << endl;
		// cout << h << " " << w << endl;

		if(black == 1)
			ans = 0;
		else if(!black)
			ans = 1;
		else if (w > n || h > m)
			ans = -1;
		else
			{
				size = max(h, w);
				ans = size*size- black;
			}

		cout << ans << endl;
		return 0;
	}