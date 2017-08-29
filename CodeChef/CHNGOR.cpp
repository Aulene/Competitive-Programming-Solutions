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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, t, i, x;
		int ans;

		cin >> t;

		while(t--)
			{
				cin >> n >> ans;

				for(i = 1; i < n; i++)
					{
						cin >> x;
						ans = ans | x;
						// cout << ans << endl;
						
					}

				cout << ans << endl;
			}
		return 0;
	}