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

int a[207];
int n;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, ans, sum = 0, x = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i], x += a[i];

		for(i = 1; i <= n; i += 2) sum += a[i];

		if(sum > x - sum) cout << sum << " " << x - sum << endl;
		else cout << x - sum << " " << sum << endl;

		return 0;
	}