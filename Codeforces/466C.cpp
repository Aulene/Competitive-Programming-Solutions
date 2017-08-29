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

lli a[500007];

int main()
	{
		lli n, i, ans=0;
		lli c=0;

		cin >> n;

		for(i=1; i<=n; i++)
			{
				cin >> a[i];
				a[i]+=a[i-1];
			}

		for(i=1; i<n; i++)
			{
				if(i>1 && 3*a[i]==2*a[n])
					ans+=c;

				if(3*a[i]==a[n])
					c++;
			}

		cout << ans << endl;	
		return 0;
	}