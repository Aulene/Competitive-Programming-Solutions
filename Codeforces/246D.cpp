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

int c[100007];
unordered_map <int, bool> m[100007];
vector <int> colors;
bool psd[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, M, i, j, u, v, ans = 0, x, ansc;
		unordered_map <int, bool> :: iterator it;

		cin >> n >> M;

		for(i = 1; i <= n; i++)
			{cin >> c[i]; if(!psd[c[i]]) psd[c[i]] = 1, colors.pb(c[i]);}

		sort(colors.begin(), colors.end());
		
		while(M--)
			{
				cin >> u >> v;
				if(c[u] != c[v])
					{
						m[c[u]][c[v]] = 1;
						m[c[v]][c[u]] = 1;
					}
			}

		for(i = 0; i < colors.size(); i++)
			{
				u = colors[i], x = 0;

				for(it = m[u].begin(); it != m[u].end(); it++)
					if(m[u][it -> first]) x++;
				
				// cout << u << " " << x << endl;
				if(x > ans)
					{
						ans = x;
						ansc = u;
					}
				else if(x == ans)
					ansc = min(ansc, u);
			}

		cout << ansc << endl;
		return 0;
	}