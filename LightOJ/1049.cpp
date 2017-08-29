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

vector < pair <int, int> > g[107];

int main()
	{
		int t, n, i, u, v;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i=0; i<n; i++)
					{
						cin >> u >> v >> wt;
						g[u].pb(mp(v, wt));
					}
			}

		return 0;
	}