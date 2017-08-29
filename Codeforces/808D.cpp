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

int a[100007], p[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, k;
		bool ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i], p[i] = p[i - 1] + a[i];

		for(i = 1; i <= n; i++)
			{
				j = p[i], k = p[n] - p[i];
				if(j == k) ans = 1;
				j = p[i + 1] - a[i], k = p[n] - p[i + 1] + a[i];
				if(j == k) ans = 1;
 			}

 		if(ans) cout << "YES\n";
 		else cout << "NO\n";
		return 0;
	}