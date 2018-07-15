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

int a[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, x, i, j, ans = 0;

		cin >> n >> x;

		for(i = 0; i < n; i++)
			{
				cin >> j;
				a[j]++;
			}


		for(i = 0; i <= x; i++)
			{
				if(i == x)
					{
						if(a[i] > 0) ans++;
						break;
					}
					
				if(a[i] == 0 && i != x)
					ans++;
			}

		cout << ans << endl;

		return 0;
	}