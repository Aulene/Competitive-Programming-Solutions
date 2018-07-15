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
		int n, i, j, o = 0, z = 0;

		bool ansx = 0;

		cin >> s;
		n = s.size();

		for(i = n - 1; i >= 0; i--)
			{
				if(s[i] == '0')
					{
						z++;
					}
				else
					{
						if(z >= 6) ansx = 1;
					}
			}

		if(ansx) cout << "yes\n";
		else cout << "no\n";
		return 0;
	}