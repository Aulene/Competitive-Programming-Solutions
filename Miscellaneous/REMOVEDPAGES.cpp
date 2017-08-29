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
map <int, bool> m;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, ans = 0, x;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> a[i];
				m[a[i]] = 1;
			}

		for(i = 0; i < n; i++)
			{
				if(a[i] % 2 == 0)
					{
						x = (a[i] - 2) / 2;
						x = 2 * x + 1;
						if(m[x] == 0)
							ans++;
					}
				else
					{
						x = (a[i] - 1) / 2;
						x = 2 * x + 2;
						if(m[x] == 0)
							ans++;						
					}
			}

		cout << ans << endl;
		return 0;
	}