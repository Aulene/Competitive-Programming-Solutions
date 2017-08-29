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


int startnode, ans, v;
int a[100007];
int ansExists[100007];
bool flag;

int dfs1(int index)
{
	if(!a[index])
		{
			ansExists[index]=0;
			return 0;
		}

	if(index==startnode)
		{
			if(!flag)
				{
					ansExists[index]=1;
					return 1;
				}
			else
				flag=0;
		}

	int ans, x;
	x=dfs1(a[index]);
	flag=0;

	if(x)
		ansExists[index]=1;
	
	if(ansExists[index])
		return 1;
	return 0;
}

int dfs2(int index)
{
	if(index==v)
		return 0;

	int ans;
	ans=1+dfs2(a[index]);
	return ans;
}

int main()
	{
		int n, i, u;

		memset(ansExists, -1, sizeof(ansExists));

		cin >> n;

		for(i=0; i<n; i++)
			{
				cin >> u >> v;
				a[u]=v;
			}

		while(cin >> startnode >> v)
			{
				if(startnode==0 && v==0)
					break;

				flag=1;
				if(ansExists[startnode]==-1)
					dfs1(startnode);

				if(ansExists[startnode])
					{
						//ans=dfs2(startnode);
						cout << "Yes " << ans << endl;
					}
				else
					cout << "No" << endl; 
			}

		for(i=0; i<=100; i++)
			if(ansExists[i]!=-1)
			cout << a[i] << " " << ansExists[i] << endl;

		cout << endl;
  		return 0;
	}