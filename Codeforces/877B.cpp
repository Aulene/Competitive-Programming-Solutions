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

int a[5007], b[5007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		int n, i, j, ans = 0;

		cin >> s;
		n = s.size();

		for(i = 1; i <= n; i++)
			{
				if(s[i - 1] == 'a')
					{
						a[i] = a[i - 1] + 1;
						b[i] = b[i - 1];
					}
				else
					{
						a[i] = a[i - 1];
						b[i] = b[i - 1] + 1;
					}
				// cout << a[i] << " " << b[i] << endl;
			}

		for(i = 0; i <= n; i++)
			for(j = i; j <= n; j++)
				{
					int u = a[n] - a[j] + b[j] - b[i] + a[i];
					// cout << i << " " << j << " " << u << endl;
					ans = max(ans, u);
				}

		cout << ans << endl;
		// cout << n - ans << endl;
		return 0;
	}