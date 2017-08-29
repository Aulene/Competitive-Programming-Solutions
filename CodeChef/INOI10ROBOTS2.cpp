#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
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

lli a[2507][2507], b[2507][2507];
lli dp1[2507][2507];
int n;

lli recur1(int x, int y)
{
	if(x<1 || x>n || y<1 || y>n)
		return -100000007;
	
	if(x==n && y==n)
		return dp1[x][y]=a[x][y];

	if(dp1[x][y]!=-1)
		return dp1[x][y];

	lli ans1=0, ans2=0, ans;
	ans1=recur1(x+1, y);
	ans2=recur1(x, y+1);
	ans=max(ans1, ans2);

	return dp1[x][y]=a[x][y]+ans;
}

void rotateMatrix()
{
    for (int x = 0; x < n / 2; x++)
		{
		    for (int y = x; y < n-x-1; y++)
		    {
		        int temp = b[x][y];
		        b[x][y] = b[y][n-1-x];
		        b[y][n-1-x] = b[n-1-x][n-1-y];
		        b[n-1-x][n-1-y] = b[n-1-y][x];
		        b[n-1-y][x] = temp;
		    }
		}
}

int main()
	{
		int i, j;
		lli ans=-1000000007;

		cin >> n;

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				{
					cin >> a[i][j];
					b[i][j]=a[i][j];
				}
		cout << endl << endl;

		rotateMatrix();
		
		for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
					cout << b[i][j] << " ";
				cout << endl;
			}
		

		for(i=0; i<2507; i++)
			for(j=0; j<2507; j++)
				dp1[i][j]=-1;

		ans=recur1(1, 1);
		cout << ans << endl;
		return 0;
	}