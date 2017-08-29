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

struct peepz
{
	int idNo;
	int id[307];		
};

peepz p[307];
bool g[307][307];
bool visited[307];
int no;

int dfs(int index)
{
	if(visited[index])
		return 0;

	visited[index]=1;

	int ans=1, i;

	for(i=1; i<=no; i++)
		if(g[index][i])
			ans=1+dfs(i);

	return ans;
}

int lcs(int a[], int n, int b[], int m)
{
	int i, j, ans=0;
	
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			if(a[i] == b[j])
				{
					ans++;
					break;
				}

	return ans;
}

int main()
	{
		int n, k, i, j, x;
		int l, ans;

		cin >> n >> k;
		no=n;

		for(i=1; i<=n; i++)
			{
				cin >> p[i].idNo;

				for(j=1; j<=p[i].idNo; j++)
					cin >>p[i].id[j];
			}

		for(i=1; i<=n; i++)
			for(j=i+1; j<=n; j++)
				{
					l=lcs(p[i].id, p[i].idNo, p[j].id, p[j].idNo);
					//cout << i << " " << j << " " << l << endl;

					if(l>=k)
						{
							
							g[i][j]=1;
							g[j][i]=1;
						}
				}
		
		ans=dfs(1);

		cout << ans << endl;
		return 0;
	}