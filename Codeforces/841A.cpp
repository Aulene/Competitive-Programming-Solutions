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

int a[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k;
		string s;
		bool ans = 1;

		cin >> n >> k >> s;
		for(int i = 0; i < n; i++)
			{
				a[s[i]]++;
				if(a[s[i]] > k) ans = 0;
			}

		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}