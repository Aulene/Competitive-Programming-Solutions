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

int a[507], ansx[507];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j, ans = 0;

		cin >> n >> k;

		for(i = 0; i < n; i++) cin >> a[i];

		if(k > n)
			{
				for(i = 0; i < n; i++) ans = max(ans, a[i]);
				cout << ans << endl;
			}
		else
			{
				pair <int, int> ansp = mp(0, 0);
				int u, v;

				for(i = 0; i < n; i++) ans = max(ans, a[i]);

				for(i = 0; i < n; i++)
					{
						u = a[i], v = ansx[i];

						// cout << i << " " << u << " " << v << endl;
						for(j = i + 1; j <= min(i + k, n); j++)
							if(u > a[j]) v++;
							else { ansx[j]++; i = j - 1; break;}
						// cout << v << endl;	

						if(v > ansp.s) ansp = mp(u, v);
						if(v >= k) break; 
					}

				// cout << ansp.f << " " << ansp.s << endl;
				// cout << k << endl;

				if(ansp.s >= k) cout << ansp.f << endl;
				else cout << ans << endl;
			}
		return 0;
	}