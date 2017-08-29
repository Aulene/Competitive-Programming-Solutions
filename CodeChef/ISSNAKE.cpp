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

char a[507][507];
bool vis[507][507];
bool ans;
int n;

int dfs(int i, int j)
{
	if(i<1 || i>2 || j<1 || j>n)
		return 0;

	if(a[i][j] == '.')
		return 0;

	if(vis[i][j])
		return 0;

	vis[i][j] = 1;

	if(!vis[i+1][j])
		return dfs(i+1, j);

	if(!vis[i][j+1])
		return dfs(i, j+1);
	
	if(!vis[i-1][j])
		return dfs(i-1, j);
	
	if(!vis[i][j-1])
		return dfs(i, j-1);
	
	return 0;
}

int main()
	{
		lli t, i, j;

		cin >> t;

		while(t--)
			{
				bool start = 1;
				ans = 1;

				cin >> n;

				for(i=1; i<=2; i++)
					for(j=1; j<=n; j++)
						{
							cin >> a[i][j];
							vis[i][j] = 0;
						}

				for(i=1; i<=2; i++)
					for(j=1; j<=n; j++)
						if(a[i][j] == '1' && !vis[i][j])
							{
								if(!start)
									ans = 0;
								else
									{				
										dfs(i, j);
										start = 0;
									}
							}
				
				if(ans)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}

		return 0;
	}