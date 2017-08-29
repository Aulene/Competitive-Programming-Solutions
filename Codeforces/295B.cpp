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

lli graph[507][507];
bool removed[507];
lli n;

lli floyd()
{
	lli ans=0, i, j, k;
	lli dist[507][507];

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			dist[i][j]=graph[i][j];

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			for(k=0; k<n; k++)
				dist[j][k]=min(dist[j][k], dist[j][i]+dist[i][k]);
					
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(!removed[i] && !removed[j])
				ans+=dist[i][j];

	return ans;
}

int main()
	{
		int i, j, no;

		cin >> n;

		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				cin >> graph[i][j];

		no=n;

		while(no--)
			{
				cout << floyd() << endl;

				cin >> j;

				removed[j]=1;
				
				for(i=0; i<n; i++)
					{
						graph[i][j]=INT_MAX;
						graph[j][i]=INT_MAX;
					}
			}
		return 0;
	}