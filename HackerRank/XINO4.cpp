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

int a[100007], prefix[100007], suffix[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, ans = -10000000007;

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		prefix[1] = a[1];
		suffix[n] = a[n];

		for(i = 2; i <= n; i++)
			prefix[i] = prefix[i - 1] ^ a[i];

		for(i = n - 1; i >= 1; i--)
			suffix[i] = suffix[i + 1] ^ a[i];

		for(i = 1; i <= n; i++)
			cout << prefix[i] << " ";
		cout << endl;

		for(i = 1; i <= n; i++)
			cout << suffix[i] << " ";
		cout << endl;
		

		for(i = 0; i <= n + 1; i++)	
			ans = max(ans, prefix[i] ^ suffix[i + 1]);
		cout << ans << endl;
		return 0;
	}