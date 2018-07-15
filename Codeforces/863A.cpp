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

		string s, s1;
		int n, i, j, l = 0, r = n - 1;
		bool ans = 1;

		cin >> s; n = s.size();

		for(i = 0; i < n; i++)
			if(s[i] != '0') { l = i; break; }

		for(i = n - 1; i >= 0; i--)
			if(s[i] != '0') { r = i; break; }

		while(l <= r)
			{
				if(s[l] != s[r]) ans = 0;
				l++, r--;
			}

		if(ans) cout << "YES\n";
		else cout << "NO\n";

		return 0;
	}