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

int a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		int t, n, q, i, j, u, v;
		bool ans;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 100007; i++) a[i] = -1007;
				ans = 1;

				cin >> n >> q;

				while(q--)
					{
						cin >> u >> v >> j;

						if(u == v)
							{
								if(j) ans = 0;
							}
						if(a[u] != -1007 && a[v] != -1007)
							{
								if(j != abs(a[u] - a[v])) ans = 0;
							}
						if(j)
							{
								if(a[u] == -1007 && a[v] == -1007) a[u] = 0, a[v] = 1;
								else if(a[u] != -1007 && a[v] == -1007)
									{
										if(!a[u]) a[v] = 1;
										else a[v] = 0;
									}
								else if(a[u] == -1007 && a[v] != -1007)
									{
										if(!a[v]) a[u] = 1;
										else a[u] = 0;
									}
							}
						else
							{
								if(a[u] == -1007 && a[v] == -1007) a[u] = 0, a[v] = 1;
								else if(a[u] != -1007 && a[v] == -1007)
									{
										if(!a[u]) a[v] = 0;
										else a[v] = 1;
									}
								else if(a[u] == -1007 && a[v] != -1007)
									{
										if(!a[v]) a[u] = 0;
										else a[u] = 1;
									}
							}
					}

				if(ans) printf("yes\n");
				else printf("no\n");
			}
		return 0;
	}