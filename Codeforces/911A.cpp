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
vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, x = 100000000007, ans = 100000007;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i], x = min(x, a[i]);;
		for(i = 0; i < n; i++)
			if(x == a[i])
				vs.pb(i);

		for(i = 1; i < vs.size(); i++)
			ans = min(ans, vs[i] - vs[i - 1]);
		cout << ans << endl;
		
		return 0;
	}