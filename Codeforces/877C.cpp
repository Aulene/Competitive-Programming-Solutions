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

vector <int> ans;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;

		cin >> n;

		for(i = 2; i <= n; i+=2) ans.pb(i);
		for(i = 1; i <= n; i+=2) ans.pb(i);
		for(i = 2; i <= n; i+=2) ans.pb(i);
				
		cout << ans.size() << endl;
		for(i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		return 0;
	}