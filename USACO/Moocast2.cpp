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
#define pb push_back
#define p push

struct point 
{
	int x, y;
};

point ax[1007];
vector< pair<int, int> > g[1007];
bool visited[1007];
queue<int> q;
int a[1001007];
int n;

int dist(int p1, int p2)
{
	return pow(abs(ax[p1].y-ax[p2].y), 2)+pow(abs(ax[p1].x-ax[p2].x), 2);
}

int bfs(int dist)
{
	int v, u, wt, i;
	bool ans=1;
	memset(visited, 0, sizeof(visited));
	vector< pair<int, int> >::iterator it;

	visited[1]=1;
	q.push(1);

	while(!q.empty())
		{
			v=q.front();
			q.pop();

			for(it=g[v].begin(); it!=g[v].end(); it++)
				{
					u=it->first;
					wt=it->second;

					if(wt<=dist && !visited[u])
						{
							q.p(u);
							visited[u]=1;
						}
				}
		}

	for(i=1; i<=n; i++)
		if(!visited[i])
			ans=0;

	return ans;
}

int binarySearch(int low, int high)
{
	int ans=10000001;
	int mid;

	while(low<=high)
		{
			mid=(low+high)/2;

			//cout << mid << " " << a[mid] << " " << bfs(a[mid]) << endl;

			if(bfs(a[mid]))
				{
					ans=a[mid];
					high=mid-1;
				}
			else
				low=mid+1;

			//cout << low << " " << high << endl;

		}

	return ans;
}

int main()
	{
		ifstream fin ("moocast.in");
		ofstream fout ("moocast.out");

		int i, j;
		int u, v, wt, x=0;

		cin >> n;

		for(i=1; i<=n; i++)
			cin >> ax[i].x >> ax[i].y;

		for(i=1; i<=n; i++)
			for(j=i+1; j<=n; j++)
				{
					wt=dist(i, j);
					g[i].pb(make_pair(j, wt));
					g[j].pb(make_pair(i, wt));
					a[x]=wt;
					x++;
				}

		sort(a, a+x);
		int ans=binarySearch(1, x);
		cout << ans << endl;

		return 0;
	}