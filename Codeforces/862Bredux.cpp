#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;
vector <int> krawedzie[100007];
int czerwo=0;
int niebo=0;
int vis[100007];
int DFS(int x)
{
	for(int i=0;i<krawedzie[x].size();i++)
	{
		if(vis[krawedzie[x][i]]==0)
		{
			if(vis[x]==1)
			{
				vis[krawedzie[x][i]]=2;
				niebo++;
			}
			else
			{
				vis[krawedzie[x][i]]=1;
				czerwo++;
			}
			DFS(krawedzie[x][i]);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		krawedzie[a].push_back(b);
		krawedzie[b].push_back(a);
	}
	vis[1]=1;
	czerwo++;
	DFS(1);
	int wynik=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			wynik+=(niebo-krawedzie[i].size());
		}
	}
	printf("%d",wynik);
}