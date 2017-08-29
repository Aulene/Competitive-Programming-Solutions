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

char a[1007][1007];

int main()
	{
		int t, n, m, i, j;

		cin >> t;

		while(t--)
			{
				bool ans=1;

				cin >> n >> m;

				for(i=0; i<1007; i++)
					for(j=0; j<1007; j++)
						a[i][j]='A';

				for(i=1; i<=n; i++)
					for(j=1; j<=m; j++)
						cin >> a[i][j];

				for(i=n; i>=1; i--)
					{

						for(j=1; j<=m; j++)
							if(a[i][j]=='B' && i!=n)
								{
									if(a[i+1][j]!='B')
										ans=0;
								}
							else if(a[i][j]=='W')
								{
									if(a[i][j+1]=='A' || a[i][j-1]=='A' || a[i+1][j]=='A')
										ans=0;
								}
					}

				if(ans)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}

		return 0;
	}