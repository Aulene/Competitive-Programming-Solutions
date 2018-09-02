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

long double ans;

void binarySearch(int timePerCost, int time, int deadline)
{
	int low = 0, high = 1000000001, mid;
	long double ansx = -1;

	while(low <= high)
		{
			mid = (low + high) / 2;
			long double u = (double) time - timePerCost * mid;

			if(u <= deadline)
				{
					ansx = mid;
					high = mid - 1;
				}
			else low = mid + 1;
		}
	// cout << ans << endl;
	ans += ansx;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, n, i, j, u, v, w;
		double x, y, z;

		cin >> t;

		while(t--)
			{
				ans = 0;

				cin >> n;

				for(i = 0; i < n; i++) 
					{
						cin >> u >> v >> w;
						binarySearch(u, v, w);
					}

				printf("%.9Lf\n", ans);
			}

		return 0;
	}