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

vector<int> a[107];
int e[107];
bool visited[107];
int ans=0;

int dfs(int index)
{
	int v;
	vector<int>::iterator it;

	for(it=a[index].begin(); it!=a[index].end(); it++)
		{
			v=*it;
			if(!visited[v])
				{
					visited[v]=1;
					dfs(v);

					if(e[v]%2==1 && e[index]%2==1)
						{
							e[v]--;
							e[index]--;
							ans++;
						}
				}
		}

	return 0;
}

int main()
	{
		int n, m, i, u, v;

		cin >> n >> m;

		while(m--)
			{
				cin >> u >> v;
				a[u].pb(v);
				a[v].pb(u);
				e[u]++;
				e[v]++;
			}

		for(i=1; i<=n; i++)
			visited[i]=1;

		dfs(1);

		cout << ans << endl;

		return 0;
	}