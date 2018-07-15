#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[507], ans[27], b[27][27];
vector <int> ax;
vector < vector <int> > ps;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, k;

		cin >> t;

		for(int i = 1; i <= 6; i++) ax.pb(i);

		do
		{
			bool l = 1;
			for(int i = 0; i < ax.size(); i++)
				if(ax[i] == i + 1)
					l = 0;

			if(l) ps.pb(ax);

		}while(next_permutation(ax.begin(), ax.end()));

		while(t--)
			{	
				bool ansx = 1, ansf = 1;

				for(i = 0; i < 17; i++)
					for(j = 0; j < 17; j++)
						b[i][j] = 0;

				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> a[i];

						if(i > 0)
							{
								b[a[i - 1]][a[i]] = 1;
								b[a[i]][a[i - 1]] = 1;
							}
					}

				for(i = 1; i < n; i++)
					if(a[i] == a[i - 1]) ansf = 0;

				for(j = 0; j < ps.size(); j++)
					{
						ax = ps[j];
						ansx = 1;

						if(!ansx) continue;

						int f = 1;

						for(i = 0; i < ax.size(); i++)
							{
								int u = ax[i];

								if(b[u][f])
									{
										ansx = 0;
										break;
									}
								f++;
							}

						if(ansx) break;

					}

				if(ansx && ansf) for(i = 0; i < ax.size(); i++) cout << ax[i] << " ";
				else cout << -1;

				cout << endl;
			}
		return 0;
	}