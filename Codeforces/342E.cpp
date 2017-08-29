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

vector<int> g[100007], centroidTree[100007];
int subtrees[100007], decompositions[100007];
bool vis[100007];
int centroid, n;

int findCentroid(int u)
{
	subtrees[u] = 1;
	vis[u] = 1;
	int left = 0;

	for(vector <int> :: iterator it = g[u].begin(); it != g[u].end(); it++)
		if(!vis[*it])
			{
				findCentroid(*it);
				subtrees[u] += subtrees[*it];
				left = max(left, subtrees[*it]);
			}

	left = max(left, n - subtrees[u]);

	if(left <= n/2)
		centroid = u;

	return 0;
}

int decompose(int root)
{
	for(vector <int> :: iterator it = g[centroid].begin(); it != g[centroid].end(); it++)
		{
				
		}
}

int main()
	{
		int u, v, i, j, m;

		cin >> n >> m;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		findCentroid(1);

		for(i = 1; i <= n; i++)
			cout << subtrees[i] << " ";
		cout << endl << centroid << endl;

		for(i = 1; i <= n; i++)
			vis[i] = 0;

		decompose(centroid);

		for(i = 1; i <= n; i++)
			cout << decompositions[i] << " ";
		cout << endl;
		return 0;
	}