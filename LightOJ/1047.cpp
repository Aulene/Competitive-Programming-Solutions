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

struct house
{
	int r, g, b;
};

house p[27];
int n;
lli dp[27][27];

// 1=red, 2=green, 3=blue
lli recur(int index, int color)
{
	if(index>=n)
		return 0;

	lli ans1, ans2, ans;

	if(dp[index][color]!=-1)
		return dp[index][color];

	if(color==1)
		{
			ans1=p[index].g+recur(index+1, 2);
			ans2=p[index].b+recur(index+1, 3);
		}
	else if(color==2)
		{
			ans1=p[index].r+recur(index+1, 1);
			ans2=p[index].b+recur(index+1, 3);
		}
	else
		{
			ans1=p[index].r+recur(index+1, 1);
			ans2=p[index].g+recur(index+1, 2);
		}

	ans=min(ans1, ans2);
	return dp[index][color]=ans;
}

int main()
	{
		int t=1, T, i, j;
		lli ans;

		cin >> T;

		while(T--)
			{
				for(i=0; i<27; i++)
					for(j=0; j<27; j++)
						dp[i][j]=-1;

				cin >> n;

				for(i=0; i<n; i++)
					cin >> p[i].r >> p[i].g >> p[i].b;

				ans=recur(1, 1)+p[0].r;
				ans=min(ans, recur(1, 2)+p[0].g);
				ans=min(ans, recur(1, 3)+p[0].b);
				printf("Case %d: %lld\n", t++, ans);
			}

		return 0;
	}