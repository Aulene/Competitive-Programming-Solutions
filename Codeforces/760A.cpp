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

int a[107][107];

int main()
	{
		int m, d, i, j;
		int days, ans=1, x=1;

		cin >> m >> d;

		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			{
				days=31;
			}
		else if(m==2)
			{
				days=28;
			}
		else
			{
				days=30;
			}

		for(j=d; j<=7; j++)
			{
				a[j][1]=x;
				x++;
			}

		for(i=2; i<=10; i++)
			{
				for(j=1; j<=7; j++)
					{
						a[j][i]=x++;

						if(x>days)
							break;
					}

				if(x>days)
					break;
			}

		ans=i;
		
		cout << ans << endl;

		return 0;
	}