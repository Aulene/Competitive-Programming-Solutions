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

int a[100007], sex[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, m, i, j, u, v = 0, idx;

		cin >> n >> k >> m;

		for(i = 0; i < n; i++)
			{
				cin >> u;
				a[i] = u;
				u %= m;
				sex[u]++;
			}

		for(i = 0; i < m; i++)
			if(sex[i] >= k)
				{
					idx = i;
					break;
				}

		if(i == m) cout << "No\n";
		else
			{
				cout << "Yes\n";

				for(i = 0; i < n; i++)
					{
						if(a[i] % m == idx)
							{
								cout << a[i] << " ";
								v++;
							}

						if(v == k) break; 
					}
			}
		return 0;
	}