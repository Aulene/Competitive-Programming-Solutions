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

unordered_map <string, bool> m;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s, s1;
		int n, i;

		while(cin >> s)
			{
				n = s.size();

				s1 = s;
				for(i = 0; i < n; i++) if(s1[i] >= 'A' && s1[i] <= 'Z') s1[i] += 'a' - 'A';

				if(m[s1]) cout << ". ";
				else cout << s << " ";
				
				m[s1] = 1;
			}
		return 0;
	}