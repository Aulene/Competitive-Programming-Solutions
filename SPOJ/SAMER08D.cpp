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

string s1, s2;
int l[1007][1007];
int cont[1007][1007];
int k;

int lcs()
{
	int i, j, x, n, m; 
	n=s1.size(); 
	m=s2.size();
	
	int ans=0;

	for(i=0; i<1007; i++)
		for(j=0; j<1007; j++)
			l[i][j]=0;

	for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
				{
					l[i][j]=max(l[i-1][j], l[i][j-1]);

					if(s1[i-1]==s2[j-1])
						cont[i][j]=cont[i-1][j-1]+1;
					else
						cont[i][j]=0;

					if(cont[i][j]>=k)
						{
							for(x=k; x<=cont[i][j]; x++)
								l[i][j]=max(l[i][j], l[i-x][j-x]+x);
						}
				}
		}	

	return l[m][n];
}

int main()
	{
		int i, j;
		
		while(1)
			{
				for(i=0; i<1007; i++)
					for(j=0; j<1007; j++)
						{
							l[i][j]=0;
							cont[i][j]=0;
						}

				cin >> k;

				if(!k)
					break;

				cin >> s1 >> s2;
				lcs();
				cout << l[s1.size()][s2.size()] << endl;
			}

		return 0;
	}