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

vector <int> v;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i;
		bool ans = 0;
		vector <int> :: iterator it;

		cin >> n;

		for(i = 1; (i * (i + 1)) / 2 <= n; i++)
			v.pb((i * (i + 1)) / 2);

		for(i = 0; i < v.size(); i++)
			if(v[i] <= n)
				{
					it = lower_bound(v.begin(), v.end(), n - v[i]);
					if(v[i] + *it == n) ans = 1;
				}
			else 
				break;

		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}