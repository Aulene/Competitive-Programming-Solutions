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
#define pb push_back

int tab[5007][5007];
char s[5007], rev[5007];

int lcs(int n)
{
	int i, j, k, ans=1;
	int x=0;

	for(i=n-1; i>=0; i--)
		{
			rev[x]=s[i];
			x++;
		}

	for(i=0; i<=n; i++)
		{
			for(j=0; j<=n; j++)
				{
					if(i==0 || j==0)
						tab[i][j]=0;
					else if(s[i-1]==rev[j-1])
						{
							tab[i][j]=tab[i-1][j-1]+1;
							ans=max(ans, tab[i][j]);
						}
					else
						tab[i][j]=0;
				}
		}
	
	return ans;
}

int main()
	{
		int n, i;
		cin >> n;

		for(i=0; i<n; i++)
			{
				cin >> s[i];
			}
		//cout << "1" << endl;
		cout << n-lcs(n) << endl;
		return 0;
	}