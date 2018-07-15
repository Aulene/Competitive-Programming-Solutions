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

		int n, t, i, j;
		bool x = 0, y = 0;

		cin >> s >> t;

		while(t--)
			{
				cin >> s1;
				if(s == s1) {x = 1, y = 1;}

				if(s[1] == s1[0]) x = 1;
				if(s[0] == s1[1]) y = 1;
			}

		if(x && y) cout <<"YES\n";
		else cout << "NO\n";
		return 0;
	}