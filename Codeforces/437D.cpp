#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

int a[100007];
vector < pair<int, int> > g[100007];

signed main()
	{
		int n, m, i, j;
		int u, v;
		double ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		for(i = 0; i < m; i++)
			cin >> u >> v;
		
		sort(a + 1, a + n);

		for(i = 1; i <= n; i++) {
			ans = ans + n - i 
		}

		ans /= n * (n - 1);
		cout << ans << endl;
		
		return 0;
	}