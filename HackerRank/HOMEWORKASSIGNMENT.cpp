#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<bitset>
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

int a[27][27];
int n;
//int m[27][100007];
int countMask[27];
int dp[1048577];

/*
lli recur(int index, int mask)
{
	if(index>=n)
		return 1;

	if(m[index][mask])
		return m[index][mask];

	lli i, j, ans=0;
	//bitset<16> x, y; 
	int s;

	for(i=0; i<n; i++)
		if(a[index][i] && !((mask >> i)&1))
			{
				s = mask | (1 << i);
				//x=mask;
				//y=s;
				cout << s << endl;
				//cout << x << " " << i << " " << y << endl;
				ans+=recur(index+1, s);
			}

	return m[index][mask]=ans;
}
*/

int recur(int mask)
{
	if(mask==1)

}

int main()
	{
		int t, i, j;
		lli ans;

		cin >> t;

		while(t--)
			{
				cin >> n;
				int s=0;

				//cout << s << endl;

				for(i=0; i<n; i++)
					for(j=0; j<n; j++)
						{
							scanf("%d", &a[i][j]);
							countMask[j]++;
						}

				ans=recur(0, s);
				printf("%lld\n", ans);
				
				for(i=0; i<n; i++)
					for(j=0; j<1000007; j++)
						m[i][j]=0;
			}

		return 0;
	}