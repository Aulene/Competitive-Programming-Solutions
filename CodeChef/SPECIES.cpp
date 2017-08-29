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

char a[57][57];
bool vis[57][57];

int fill(lli n)
{
	lli i, j;

	for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
				{
					if(a[i][j-1]=='.' && a[i][j+1]=='.' && a[i-1][j]=='.' && a[i+1][j]=='.')
						a[i][j]='X';
					else
						{
							if(a[i][j-1]!=)
						}
				}
		}
}

int main()
	{
		lli t, i, j, n, ans;

		cin >> t;

		while(t--)
			{
				ans=1;

				cin >> n;

				for(i=1; i<=n; i++)
					for(j=1; j<=n; j++)
						{
							a[i][j]='.';
							vis[i][j]=0;
						}
				
				for(i=1; i<=n; i++)
					for(j=1; j<=n; j++)
						cin >> a[i][j];

				fill(n);

				for(i=1; i<=n; i++)
					{
						for(j=1; j<=n; j++)
							{
								if(a[i][j] == '?')
									{
										
											ans=(ans*3)%mod;

										if(a[i][j-1]!='.' )
									}
							}
					}
			}

		return 0;
	}