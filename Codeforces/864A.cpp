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

		int n, i, j, u = 0, v = 0, num = 0;
		bool ans = 1;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> j;

				if(a[j] == 0) num++;

				a[j]++;
			}

		j = 0;

		if(num == 2)
			{
				for(i = 1; i <= 100; i++)
					{
						if(a[i])
							{
								if(u == 0) u = i;
								else v = i;
							}
					}
			}
		else ans = 0;
		
		if(ans == 0) cout << "NO\n";
		else if (a[u] == a[v]) cout << "YES\n" << u << " " << v << endl; 
		else cout << "NO\n";
		return 0;
	}