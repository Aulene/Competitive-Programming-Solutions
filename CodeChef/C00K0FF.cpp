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

unordered_map <string, int> m;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j;
		string s;

		cin >> t;

		while(t--)
			{
				m.clear();
				bool ans = 1;

				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> s;
						m[s]++;
					}

				if(!m["cakewalk"]) ans = 0;
				if(!m["simple"]) ans = 0;
				if(!m["easy"]) ans = 0;
				if(!m["easy-medium"] && !m["medium"]) ans = 0;
				if(!m["medium-hard"] && !m["hard"]) ans = 0;
				
				if(ans) cout << "Yes\n";
				else cout << "No\n";
			}

		return 0;
	}