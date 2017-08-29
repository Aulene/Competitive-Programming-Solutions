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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

int tab[1037][1037];

int query(int l, int b, int r, int t)
{
	int i, j;
	int ans=0;

	for(i=l; i<=r; i++)
		for(j=b; j<=t; j++)
			ans+=tab[i][j];

	return ans;
}

int main()
	{
		int n=0, x, y, a, l, b, r, t, s;

		while(n!=3)
			{
				cin >> n;

				if(n==3)
					break;

				if(n==0)
					{
						cin >> s;
					}
				else if(n==1)
					{
						cin >> x >> y >> a;
						tab[x][y]+=a;
					}
				else if(n==2)
					{
						cin >> l >> b >> r >> t;
						cout << query(l, b, r, t) << endl;
					}
			}

		return 0;
	}