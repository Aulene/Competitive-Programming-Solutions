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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, k;

		cin >> n >> k >> t;

		if(t <= k)
			{
				cout << t << endl;
			}
		else if(t > k && t <= n)
			{
				cout << k << endl;
			}
		else
			{
				cout << n + k - t << endl;
			}

		return 0;
	}