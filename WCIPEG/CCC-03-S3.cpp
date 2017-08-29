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

char grid[37][37];
bool visited[37][37];
vector<int> a;
int r, c;

int recur(int x, int y)
{
	if(x>=r || y>=c || x<0 || y<0)
		return 0;

	if(grid[x][y]=='I' || visited[x][y])
		return 0;

	visited[x][y]=1;

	int ans=1;
	ans+=recur(x+1, y+1);
	ans+=recur(x, y+1);
	ans+=recur(x+1, y);
	ans+=recur(x-1, y);
	ans+=recur(x, y-1);

	return ans;
}

int main()
	{
		int n, i, j;
		int val, ans=0;
		int u;

		vector<int>::iterator it;

		cin >> n >> r >> c;

		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				cin >> grid[i][j];

		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				{
					val=recur(i, j);
					if(val>0)
						{
							//cout << i << " " << j << " " << val << endl;
							a.pb(val);
						}
				}

		sort(a.begin(), a.end(), greater<int>());

		for(it=a.begin(); it!=a.end(); it++)
			{
				u=*it;

				if(u<=n)
					{
						ans++;
						n-=u;
					}
				else
					break;
			}

		if(ans!=1)
			cout << ans << " rooms, " << n << " square metre(s) left over" << endl;
		else
			cout << ans << " room, " << n << " square metre(s) left over" << endl;
		return 0;
	}