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
 
char a[7][10007];
 
int main()
	{
		lli t, n, i, j;
 
		cin >> t;
 
		while(t--)
			{
				lli ans=0, top = 0, bot = 0;
				bool mid = 0;
 
				cin >> n;
 
				for(i=0; i<2; i++)
					for(j=0; j<n; j++)
						{
							cin >> a[i][j];
 
							if(i==0 && a[i][j] == '*')
								top++;
							if(i==1 && a[i][j] == '*')
								bot++;
								
						}
 
				a[0][n]='.';
				a[1][n]='.';
 				
 				if(top && bot)
 					ans = 1;

				for(i=0; i<n; i++)
					{
						if(a[0][i] == '*')
							top--;
	
						if(a[0][i] == '*' && top)
							{
								if(bot > 1 && top == 1)
									continue;
								else
									ans++;
							}
						
						if(a[1][i] == '*')
							bot--;

						if(a[1][i] == '*' && bot)
							{
								if(top > 1 && bot == 1)
									continue;
								else
									ans++;
							}
					}
 
				cout << ans << endl;
			}
 
		return 0;
	} 