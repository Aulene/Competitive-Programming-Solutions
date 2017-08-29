#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

lli n, k;
lli ans=-1;

vector< pair <lli, lli> > a[1000007];
bool visited[1000007];

lli dfs(lli index, lli num, lli highways)
{
	if(highways>ans && ans!=-1)
		return 0;

	if(num>k || visited[index])
		return 0;

	visited[index]=1;

	if(num==k)
		{
			if(ans==-1)
				ans=highways;
			else
				ans=min(ans, highways);

			return 0;
		}

	vector<pair <lli, lli> >::iterator i;
	lli u, v;
	lli ansHere;

	for(i=a[index].begin(); i!=a[index].end(); i++)
		{
			u=i->first;
			v=i->second;

			dfs(u, num+v, highways+1);
		}

	return 0;
}

int main()
	{
		lli i, j;
		lli u, v, wt;
		
		vector<pair <lli, lli> >::iterator it;

		cin >> n >> k;

		for(i=1; i<n; i++)
			{
				cin >> u >> v >> wt;

				a[u].pb(make_pair(v, wt));
				a[v].pb(make_pair(u, wt));
			}

		/*
		for(i=0; i<n; i++)
			{
				cout << "Node " << i << endl;

				for(it=a[i].begin(); it!=a[i].end(); it++)
					{
						u=it->first;
						v=it->second;

						cout << "is connected to " << u << " with weight " << v << endl;
					}
			}
		*/

		for(i=0; i<n; i++)
			{
				for (j=0; j<n; j++)
					visited[j]=0;

				dfs(i, 0, 0);
			}

		cout << ans << endl;
		return 0;
	}