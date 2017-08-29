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

char a[17][17];

int main()
	{
		int i, j;
		bool ans=0;

		for(i=0; i<17; i++)
			for(j=0; j<17; j++)
				a[i][j]='o';

		for(i=1; i<=4; i++)
			for(j=1; j<=4; j++)
				cin >> a[i][j];

		for(i=1; i<=4; i++)
			{
				for(j=1; j<=4; j++)
					if(a[i][j]=='.')
						{
							if(a[i+1][j]=='x' && a[i-1][j]=='x')
								ans=1;

							if(a[i+1][j]=='x' && a[i+2][j]=='x')
								ans=1;

							if(a[i-1][j]=='x' && a[i-2][j]=='x')
								ans=1;

							if(a[i+1][j+1]=='x' && a[i-1][j-1]=='x')
								ans=1;

							if(a[i+1][j-1]=='x' && a[i-1][j+1]=='x')
								ans=1;

							if(a[i][j-1]=='x' && a[i][j+1]=='x')
								ans=1;

							if(a[i][j-2]=='x' && a[i][j-1]=='x')
								ans=1;

							if(a[i][j+1]=='x' && a[i][j+2]=='x')
								ans=1;

							if(a[i+1][j-1]=='x' && a[i+2][j-2]=='x')
								ans=1;
							
							if(a[i+1][j+1]=='x' && a[i+2][j+2]=='x')
								ans=1;

							if(a[i-1][j-1]=='x' && a[i-2][j-2]=='x')
								ans=1;

							if(a[i+1][j-1]=='x' && a[i+2][j-2]=='x')
								ans=1;

							if(a[i-2][j+1]=='x' && a[i-2][j+2]=='x')
								ans=1;

							if(a[i-1][j+1]=='x' && a[i-2][j+2]=='x')
								ans=1;
						}
			}

		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}