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

bool a[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, x, peopleleft, i, u, v;

		cin >> n >> k >> x;

		for(i = 0; i <= n; i++)
			a[i] = 1;

		u = x;

		while(u % k >= peopleleft)
			{
				v = u % k;
				peopleleft -= v;
				u = (u + v) % n;
			}

		cout << u << endl;
		return 0;
	}