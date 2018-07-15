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

struct dish
{
	int sz;
	vector <int> a;	
};

dish d[7];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, n, i, j, ans, m;

		cin >> t;

		while(t--)
			{
				ans = 0;

				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> d[i].sz;
						d[i].a.resize(d[i].sz);

						for(j = 0; j < d[i].sz; j++) cin >> d[i].a[j];
					}

				for(i = 0; i < n; i++)
					sort(d[i].a.begin(), d[i].a.end());

				ans = max(abs(d[0].a[0] - d[1].a[d[1].sz - 1]), abs(d[0].a[d[0].sz - 1] - d[1].a[0]));

				cout << ans << endl;
			}
		return 0;
	}