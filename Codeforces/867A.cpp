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

		string s;
		int n, i, a = 0, b = 0;

		cin >> n >> s;

		for(i = 0; i < n; i++)
			if(s[i] == 'S' && s[i + 1] == 'F') a++;
			else if(s[i] == 'F' && s[i + 1] == 'S')b++;

		if(a > b) cout << "YES\n";
		else cout << "NO\n";

		return 0;
	}