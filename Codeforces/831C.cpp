#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[2007], b[2007], prefix[2007];
unordered_map <int, int> m;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, k, ans = 0, num;
		unordered_map <int, int> :: iterator it;

		cin >> n >> k;
		
		for(i = 1; i <= n; i++)
			{
				cin >> a[i];
				prefix[i] = prefix[i - 1] + a[i];
			}

		for(i = 1; i <= k; i++)
			cin >> b[i];

		for(i = 1; i <= k; i++)
			{
				unordered_map <int, int> mx;

				for(j = 1; j <= n; j++)
					{
						num = b[i] - prefix[j];

						if(mx.find(num) == mx.end())
							{
								m[num]++;
								mx[num]++;
							}
					}
			}
		
		for(it = m.begin(); it != m.end(); it++)
			if(it->second == k)
				ans++;

		cout << ans << endl;

		return 0;
	}
