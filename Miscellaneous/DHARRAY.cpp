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

int a[1007], pref[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j;
		cin >> t;

		while(t--)
			{
				bool ans = 1;
				cin >> n;

				for(i = 1; i <= n; i++) cin >> a[i], pref[i] = pref[i - 1] + a[i];

				for(i = 2; i <= n - 1; i++)
					for(j = i; j <= n - 1; j++)
						if(pref[i] > pref[n] - pref[j])
							ans = 0;

				if(ans)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		return 0;
	}