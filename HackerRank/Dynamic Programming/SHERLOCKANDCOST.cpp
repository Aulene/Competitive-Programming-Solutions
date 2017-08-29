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

lli a[100007];
	
int main()
	{
		lli t, n, i;

		cin >> t;

		while(t--)
			{
				lli ans=0, cur;

				cin >> n;

				for(i=0; i<n; i++)
					cin >> a[i];

				for(i=1; i<n; i++)
					{	
						cur=abs(a[i]-1);
						cur=max(cur, abs(a[i-1]-1));
						ans+=cur;
					}

				cout << ans << endl;
			}

		return 0;
	}