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
bool vis[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, d, ans, sum, val, N;

		cin >> t;

		while(t--)
			{
				memset(vis, 0, sizeof vis);
				
				bool ansex = 1;
				ans = sum = 0;

				cin >> n >> d;

				for(i = 0; i < n; i++) cin >> a[i], sum += a[i];

				if(sum % n != 0) ansex = 0;
				else val = sum / n;

				for(i = 0; i < n; i++)
					if(!vis[i])
						{
							sum = 0, N = 0;

							for(j = i; j < n; j += d)
								vis[j] = 1, sum += a[j], N++;

							if((sum % N != 0) || (sum / N != val)) ansex = 0;
						}
				
				

				for(i = 0; i + d < n; i++)
					{
						if(a[i] < val)
							{
								j = val - a[i];
								a[i] += j;
								a[i + d] -= j;
								ans += j;
							}
						else if(a[i] > val)
							{
								j = a[i] - val;
								a[i + d] += j;
								a[i] -= j;
								ans += j;
							}
					}

				if(!ansex) cout << -1 << endl;
				else cout << ans << endl;
			}
		return 0;
	}