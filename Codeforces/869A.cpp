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

int a[2007], b[2007];
set <int> m;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans = 0;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i], m.insert(a[i]);
		for(i = 0; i < n; i++) cin >> b[i], m.insert(b[i]);

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				{
					int u = a[i] ^ b[j];
					if(m.count(u)) ans++; 
				}

		if(ans % 2 == 0) cout << "Karen";
		else cout << "Koyomi";
		return 0;
	}