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

int a[300007], ans[300007];
priority_queue < pair <int, int> > pq;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j, ansx = 0;
		pair <int, int> m;
		
		cin >> n >> k;

		for(i = 1; i <= n + k; i++)
			{
				if(i <= n)
					{
						cin >> j;
						pq.p(mp(j, i));
					}

				if(i > k)
					{
						m = pq.top();
						pq.pop();
						ansx += (i - m.s) * m.f;
						ans[m.s] = i;
						
						// cout << i << " " << m.f << " " << m.s << endl;
					}
			}

		cout << ansx << endl;
		for(i = 1; i <= n; i++) cout << ans[i] << " ";


		return 0;
	}