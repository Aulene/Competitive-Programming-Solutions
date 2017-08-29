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

lli a[57][57];
lli dp[57][57][57][57];
lli tab[57][57];

lli build(lli x, lli y)
{
	if(x==0 || y==0)
		return 0;

	if(tab[x][y]!=-1)
		return tab[x][y];

	lli ans=a[x][y]+build(x-1, y)+build(x, y-1)-build(x-1, y-1);
	return tab[x][y]=ans;
}

lli calc(lli x1, lli y1, lli x2, lli y2)
{
	lli ans;
	ans=tab[x2][y2]-tab[x2][y1-1]-tab[x1-1][y2]+tab[x1-1][y1-1];
	return ans;
}

lli recur(lli xL, lli yD, lli xR, lli yU)
{
	if(dp[xL][yD][xR][yU]!=-1)
		return dp[xL][yD][xR][yU];

	if(xR==xL && yD==yU)
		return 0;

	lli i, j, ans1=1e12, ans2=1e12, ans;
	lli sum=calc(xL, yD, xR, yU);

	for(i=xL; i<xR; i++)
		ans1=min(ans1, recur(xL, yD, i, yU)+recur(i+1, yD, xR, yU));

	for(i=yD; i<yU; i++)
		ans2=min(ans2, recur(xL, yD, xR, i)+recur(xL, i+1, xR, yU));

	ans=min(ans1, ans2)+sum;
	return dp[xL][yD][xR][yU]=ans;
}

int main()
	{
		lli n, m, i, j, k, l, ans;
		lli x1, x2, y1, y2;

		cin >> n >> m;

		for(i=0; i<57; i++)
			for(j=0; j<57; j++)
				for(k=0; k<57; k++)
					for(l=0; l<57; l++)
						dp[i][j][k][l]=-1;

		for(i=1; i<57; i++)
			for(j=1; j<57; j++)
				tab[i][j]=-1;

		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				cin >> a[i][j];

		build(n, m);
		ans=recur(1, 1, n, m);

		cout << ans << endl;
		return 0;
	}