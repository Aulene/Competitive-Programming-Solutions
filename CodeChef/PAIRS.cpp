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

int a[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j;

		cin >> t;

		while(t--)
			{
				int ans = 0;
				cin >> n;

				for(i = 0; i < n; i++)
					cin >> a[i];

				for(i = 1; i < n; i++)
					{
						while(a[0] != a[i])
							{
								j = a[0] % a[i];
								if(!j) { j = a[i]; break; }
								a[0] = a[i];
								a[i] = j;
							}
					}

				cout << a[0] << endl;
			}
		return 0;
	}