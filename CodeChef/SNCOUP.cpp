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
				lli ans=0, top = 0, bot = 0, edge = 0;
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

				ans = max(top, bot) - 1;
				if(top && bot)
					 ans++;
					
				cout << ans << endl;
			}

		return 0;
	}
