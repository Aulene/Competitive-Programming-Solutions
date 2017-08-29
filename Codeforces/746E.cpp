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

lli a[200007];
map<lli, int> occ;

int main()
	{
		int n;
		lli m, i, noOdd=0, noEven=0;
		lli avOdd=0, avEven=0;
		lli useEven=2, useOdd=1;
		lli ans=0;

		cin >> n >> m;

		for(i=0; i<n; i++)
			{
				cin >> a[i];	

				occ[a[i]]++;
				if(a[i]%2==1)
					noOdd++;
				else
					noEven++;
			}

		if(m%2==0)
			{
				avOdd=m/2;
				avEven=m/2;
			}
		else
			{
				avOdd=m/2+1;
				avEven=m/2;
			}

		//cout << avEven << " " << avOdd << endl;

		i=0;
		while((noEven != noOdd || occ[a[i]]>1)&& i<n)
			{
				if(occ[a[i]]>1)
					{
						occ[a[i]]--;

						if(a[i]%2==1)
							{
								a[i]=useEven;
								occ[a[i]]++;
								useEven+=2;
							}
						else
							{
								a[i]=useOdd;
								occ[a[i]]++;
								useOdd+=2;
							}
						continue;
					}

				if(a[i]%2==0 && useOdd<=m && noEven>noOdd)
					{
						occ[a[i]]--;
						a[i]=useOdd;
						occ[a[i]]++;
						useOdd+=2;
						noOdd++;
						noEven--;
						ans++;
					}

				if(a[i]%2==1 && useEven<=m && noOdd>noEven)
					{
						occ[a[i]]--;
						a[i]=useEven;
						occ[a[i]]++;
						useEven+=2;
						noEven++;
						noOdd--;
						ans++;
					}
				i++;
			}

		bool x=1;
		for(i=0; i<n; i++)
			if(occ[a[i]]>1)
				{
					x=0;
					break;
				}

		if(noOdd==noEven && x)
			{
				cout << ans << endl;
				for(i=0; i<n; i++)
					cout << a[i] << " ";
				cout << endl;	 
			}
		else
			cout << "-1" << endl;
		return 0;
	}