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

lli wealth[100007];
vector<int> g[100007];
lli ans=INT_MIN;

lli dfs(int index, lli maxval)
{
	maxval=max(maxval, wealth[index]);
	ans=max(ans, abs(wealth[index]-maxval));

	vector<int>::iterator i;

	for(i=g[index].begin(); i!=g[index].end(); i++)
		dfs(*i, maxval);

	return 0;
}

int main()
	{
		int n, i, u, root;

		cin >> n;

		for(i=1; i<=n; i++)
			cin >> wealth[i];

		for(i=1; i<=n; i++)
			{
				cin >> u;

				if(u==-1)
					{
						root=i;
						continue;
					}

				g[u].pb(i);
			}

		dfs(root, wealth[root]);
		cout << ans << endl;

		return 0;
	}