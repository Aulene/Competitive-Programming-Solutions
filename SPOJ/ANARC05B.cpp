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

int a[100007], b[100007];
int prefixA[100007], prefixB[100007];
int n, m;
vector < pair < pair <int, int>, pair <int, int> > > vs;
vector < pair < pair <int, int>, pair <int, int> > > :: iterator it;

int binarySearch(int num)
{
	int low = 1, hi = m, mid;

	while(low <= hi)
		{
			mid = (low + hi) / 2;

			if(b[mid] < num)
				low = mid + 1;
			else if(b[mid] > num)
				hi = mid - 1;
			else
				return mid;
		}
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int vsz, ans, i, sum;
		int u, v, x, y;

		while(true)
			{
				vs.clear();

				ans = vsz = 0;

				cin >> n;

				if(n == 0)
					break;

				for(i = 1; i <= n; i++)
					cin >> a[i], prefixA[i] = prefixA[i - 1] + a[i];

				cin >> m;

				for(i = 1; i <= m; i++)
					cin >> b[i], prefixB[i] = prefixB[i - 1] + b[i];

				for(i = 1; i <= n; i++)
					{
						x = binarySearch(a[i]);

						if(x)	
							{
								if(vsz)
									{
										vs[vsz - 1].s.f = i;
										vs[vsz - 1].s.s = x;
										// cout << vs[vsz - 1].f.f << " " << vs[vsz - 1].f.s << " " << vs[vsz - 1].s.f << " " << vs[vsz - 1].s.s << endl;
									}
								else
									{
										vs.pb(mp(mp(0, 0), mp(i, x)));
										vsz++;
									}
								vs.pb(mp(mp(i, x), mp(-1, -1)));
								vsz++;
							}

					}

				if(vsz)
					{
						vs[vsz - 1].s.f = n;
						vs[vsz - 1].s.s = m;
					}
				// cout << vs[vsz - 1].f.f << " " << vs[vsz - 1].f.s << " " << vs[vsz - 1].s.f << " " << vs[vsz - 1].s.s << endl;

				if(vsz == 0)
					ans = max(prefixA[n] - prefixA[0], prefixB[m] - prefixB[0]);
				else
					{
						vsz = 0;

						for(it = vs.begin(); it != vs.end(); it++)
							{
								u = it->f.f, v = it->f.s, x = it->s.f, y = it->s.s;
								// cout << it->f.f << " " << it->f.s << " " << it->s.f << " " << it->s.s << endl;

								sum = max(prefixA[x] - prefixA[u], prefixB[y] - prefixB[v]);

								ans += sum;
								vsz++;
							}	
					}
		
				cout << ans << endl;
			}
		return 0;
	}