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

int a[27];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k = 0, i;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> a[i];
				k = max(a[i], k);
			}

		if(k > 25) cout << k - 25 << endl;
		else cout << 0 << endl;
		return 0;
	}