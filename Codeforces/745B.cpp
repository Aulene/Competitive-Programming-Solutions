#include<iostream>
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

char a[507][507];

int main()
	{
		int r, c, i, j;
		int minX, minY, maxX, maxY;
		bool f=0, ans=1;

		cin >> r >> c;

		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				cin >> a[i][j];

		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				if(a[i][j]=='X')
					{
						if(!f)
							{
								minX=i;
								minY=j;
							}
						else
							{
								maxX=i;
								maxY=j;
							}
					}

		for(i=minX; i<=maxX; i++)
			for(j=minY; j<=maxY; j++)
				if(a[i][j]!='X')
					ans=0;
		
		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		return 0;
	}