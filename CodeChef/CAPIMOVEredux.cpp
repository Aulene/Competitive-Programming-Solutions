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

bool visited[500007];
vector<lli> g[500007];
lli a[500007];

int main()
{
	lli t, n, i, j, u, v, ans, ansval;
	vector<lli>::iterator it;

	cin >> t;

	while(t--)
		{
			scanf("%lld", &n);

			for(i=1; i<=n; i++)
				scanf("%lld", &a[i]);

			for(i=0; i<n-1; i++)
				{
					scanf("%lld %lld", &u, &v);
					g[u].pb(v);
					g[v].pb(u);
				}

			for(i=1; i<=n; i++)
				g[i].clear();
		}

	return 0;
} 