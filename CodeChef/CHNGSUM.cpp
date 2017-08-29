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

int a[1000007], prefix[1000007], prefixKaPrefix[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i];
		
		sort(a + 1, a + n);

		for(i = 1; i <= n; i++)
			prefix[i] = prefix[i - 1] + a[i], prefixKaPrefix[i] = prefixKaPrefix[i - 1] + prefix[i];	


		for(i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;

		for(i = 1; i <= n; i++)
			cout << prefix[i] << " ";
		cout << endl;

		for(i = 1; i <= n; i++)
			cout << prefixKaPrefix[i] << " ";
		cout << endl;
		

		for(i = 1; i < n; i++)
			{
				cout << "OPEN " << i << endl;
 				cout << a[i] * (prefix[n] - prefix[i]) + a[i] * prefix[i] << endl;
 				cout << "CLOSE" << endl;
				ans += a[i] * (prefix[n] - prefix[i]) + a[i] * (prefix[i]);
			}

		cout << ans << endl;
		return 0;
	}