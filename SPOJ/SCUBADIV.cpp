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

struct box
{
	int oxy;
	int nit;
	int wt;	
};

int dp[1007][37][87];
box b[1007];
int n;

int recur(int index, int ox, int nit)
{
	if(ox<=0 && nit<=0)
		return 0;

	if(index>=n)
		return 10000001;

	if(dp[index][ox][nit]!=-1)
		return dp[index][ox][nit];

	int ans=10000001;
	ans=min(ans, recur(index+1, max(ox-b[index].oxy, 0), max(nit-b[index].nit, 0)))+b[index].wt;
	ans=min(ans, recur(index+1, ox, nit));
	return dp[index][ox][nit]=ans;
}

int main()
	{
		int t, i, j, k, oxygen, nitrogen, ans;

		cin >> t;

		while(t--)
			{
				for(i=0; i<1007; i++)
					for(j=0; j<37; j++)
						for(k=0; k<87; k++)
							dp[i][j][k]=-1;

				cin >> oxygen >> nitrogen >> n;

				for(i=0; i<n; i++)
					cin >> b[i].oxy >> b[i].nit >> b[i].wt;
				
				ans=recur(0, oxygen, nitrogen);
				cout << ans << endl;
			}

		return 0;
	}