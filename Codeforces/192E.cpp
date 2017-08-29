#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

vector <int> g[100007];
map < pair <int, int> , int> m;
map < int, pair <int, int> > ids;

int main()
	{
		int i, j, u, v, q, n;

		cin >> n;

		for(i = 1; i <= n; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
				m[mp(u, v)] = 1;
				ids[i] = mp(u, v);
			}

		cin >> q;

		while(q--)
			{

			}

		return 0;
	}