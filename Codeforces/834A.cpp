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

		char x, y;
		int n, i, lol = 0;
		int ans = 0, a1, a2;

		vector <char> vs;
		vector <char> :: iterator it, it1;

		vs.pb('v');
		vs.pb('<');
		vs.pb('^');
		vs.pb('>');
		vs.pb('v');
		vs.pb('<');
		vs.pb('^');
		vs.pb('>');
		vs.pb('v');
		vs.pb('<');
		vs.pb('^');
		vs.pb('>');

		cin >> x >> y >> n;

		it = find(vs.begin(), vs.end(), x);

		for(it1 = it; *it != y; it1--)
			lol = 0;

		a1 = it - it1;

		if(a1 == n)
			ans = 1;

		for(it1 = it; *it != y; it1++)
			lol = 0;
		
		a2 = it1 - it;

		if(a2 == n)
			ans = 2;

		if(ans == 1) cout << "cw" << endl;
		else if(ans == 2) cout << "ccw" << endl;
		else cout << "undefined" << endl;

		return 0;
	}