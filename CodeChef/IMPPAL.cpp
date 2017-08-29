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

map < pair <char, char>, bool > M;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, N, i, j, k, x;
		char u, v;
		string s;

		cin >> t;

		while(t--)
			{
				bool ans1 = 1, ans2 = 1;
				M.clear();

				cin >> n >> m;
				cin >> s;

				for(i = 0; i < m; i++)
					{
						cin >> x;
						vector <char> vs;

						for(j = 0; j < x; j++)
							cin >> u, vs.pb(u);
					
						for(j = 0; j < vs.size(); j++)
							{
								for(k = 0; k < vs.size(); k++)
									M[mp(vs[j], vs[k])] = 1;
							}
					}

				x = n - 1;
				for(i = 0; i <= x; i++)
					{
						if(!(s[i] == s[x]))
							ans1 = 0;
						x--;
					}

				x = n - 1;
				for(i = 0; i <= x; i++)
					{
						if(!(M[mp(s[i], s[x])] || s[i] == s[x]))
							{
								// cout << i << " " << x << endl;
								ans2 = 0;
							}
						x--;
					}

				if(ans1)
					cout << "Not Impersonating" << endl;
				else if(ans2)
					cout << "Impersonating" << endl;
				else
					cout << "Not Impersonating" << endl;
			}
		return 0;
	}