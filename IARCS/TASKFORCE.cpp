//AULENE LOVES KILLING NEWBORN PUPPIES :-D
#include<iostream>
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
#define pb push_back

vector<int> a[3007];
int hate[3007];
bool removed[3007];
int k;

int bfs(int start)
{	
	int i, v, u;
	vector<int>::iterator it;
	queue<int> q;

	q.push(start);
	hate[start]--;
	removed[start]=1;

	while(!q.empty())
		{
			v=q.front();
			q.pop();

			for(it=a[v].begin(); it!=a[v].end(); it++)
				{
					u=*it;
					hate[u]--;

					if(hate[u]<k && !removed[u])
						{
							q.push(u);
							removed[u]=1;
						}
				}
		}

	return 0;
}

int main()
	{
		int n, e, i;
		int u, v;
		int ans=0;

		cin >> n >> e >> k;

		for(i=0; i<e; i++)
			{
				scanf("%d %d", &u, &v);

				a[u].pb(v);
				a[v].pb(u);

				hate[u]++;
				hate[v]++;
			}

		for(i=1; i<=n; i++)
			if(hate[i]<k && !removed[i])
				bfs(i);

		for(i=1; i<=n; i++)
			if(!removed[i])
				ans++;

		if(ans==0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl << ans << endl;
		
		return 0;
	}