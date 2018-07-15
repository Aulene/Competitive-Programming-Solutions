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

int a[300007];
bool sex[300007];

vector <int> ans;
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n;
		u = n;

		for(i = 1; i <= n; i++) cin >> a[i];

		ans.pb(1);
		for(i = 1; i <= n; i++)
			{
				if(u == a[i] || sex[u])
					{
						u--, i--;
						continue;
					}

				sex[a[i]] = 1;
				ans.pb(1 + i - n + u);
			}

		for(i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		return 0;
	}