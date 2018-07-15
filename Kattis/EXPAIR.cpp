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

int a[100007], num[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans = 0, cnt = 0;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];

		i = 1, j = 1;
		num[a[i]]++;

		while(j < n)
			{
				j++;
				num[a[j]]++;

				if(num[a[j]] == 1) cnt++;

				while(num[a[j]] > 2)
					{
						num[a[i]]--;
						i++;
					}

				if(cnt == 0) ans = max(ans, i - j);
 			}

 		cout << ans << endl;

		return 0;
	}