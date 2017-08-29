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

		int n, i, j;
		string s, s1, s2;
		bool ans = 1;

		cin >> s, n = s.size();

		for(i = 0; i < n; i++) if(s[i] == '@') break;

		if(i > 5) ans = 0;
		s1 = s.substr(i, s.size());
		// cout << s1 << endl;

		if(s1 != "@hogwarts.com") ans = 0;

		if(!ans) cout << "No\n";
		else cout << "Yes\n";
 		return 0;
	}