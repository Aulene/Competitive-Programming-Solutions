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

char grid[57][57];
int flood[57][57];
int dp[57][57][3007];

int r, c;

int makeFlood()
{
	int i, j, t;
	bool floodCreated;

	for(t=1; t<=1000; t++)
		{
			floodCreated=0;

			for(i=0; i<r; i++)
				for(j=0; j<c; j++)
					if(flood[i][j]==t)
						{
							if(i>0 && grid[i-1][j]!='X' && grid[i-1][j]!='D' && flood[i][j]+1<flood[i-1][j])
								{
									flood[i-1][j]=1+flood[i][j];
									floodCreated=1;
								}

							if(i<r && grid[i+1][j]!='X' && grid[i+1][j]!='D' && flood[i][j]+1<flood[i+1][j])
								{
									flood[i+1][j]=1+flood[i][j];
									floodCreated=1;
								}

							if(j>0 && grid[i][j-1]!='X' && grid[i][j-1]!='D' && flood[i][j]+1<flood[i][j-1])
								{
									flood[i][j-1]=1+flood[i][j];
									floodCreated=1;
								}

							if(j<c && grid[i][j+1]!='X' && grid[i][j+1]!='D' && flood[i][j]+1<flood[i][j+1])
								{
									flood[i][j+1]=1+flood[i][j];
									floodCreated=1;
								}
						}

			if(!floodCreated)
				return 0;
		}

	return 0;
}

int recur(int x, int y, int time)
{
	if(x<0 || x>=r || y<0 || y>=c || grid[x][y]=='X')
		return 10000001;

	if(flood[x][y]<=time)
		return 10000001;

	if(dp[x][y][time]!=-1)
		return dp[x][y][time];

	if(grid[x][y]=='D')
		return dp[x][y][time]=0;

	int ans1, ans2, ans3, ans4, ans;

	ans1=recur(x+1, y, time+1);
	ans2=recur(x-1, y, time+1);
	ans3=recur(x, y+1, time+1);
	ans4=recur(x, y-1, time+1);

	ans=min(ans1, ans2);
	ans=min(ans, ans3);
	ans=min(ans, ans4);

	return dp[x][y][time]=1+ans;
}

int main()
	{
		int i, j, k;
		int startX, startY;

		cin >> r >> c;

		for(i=0; i<57; i++)	
			for(j=0; j<57; j++)
				flood[i][j]=100001;

		for(i=0; i<57; i++)
			for(j=0; j<57; j++)
				for(k=0; k<3007; k++)
					dp[i][j][k]=-1;

		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				{
					cin >> grid[i][j];

					if(grid[i][j]=='S')
						{
							startX=i;
							startY=j;
						}

					if(grid[i][j]=='*')
						flood[i][j]=1;
				}

		makeFlood();

		int ans=recur(startX, startY, 1);

		if(ans>=1000001)
			cout << "KAKTUS" << endl;
		else
			cout << ans << endl;
		return 0;
	}