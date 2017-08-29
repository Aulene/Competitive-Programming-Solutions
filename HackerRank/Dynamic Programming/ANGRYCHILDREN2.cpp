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
		lli n, k, i, startIndex, endIndex, minDiff=LLONG_MAX, diff;
		lli ans=0;
		lli m1, m2;

		cin >> n >> k;

		for(i=0; i<n; i++)
			cin >> a[i];

		sort(a, a+n);

		/*
		for(i=0; i<n; i++)
			cout << a[i] << " ";
		cout << endl;
		*/
		
		m1=k-1;
		m2=0;

		for(i=k; i<=n; i++)
			{
				diff=a[i-1]-a[i-k];
				if(diff<minDiff)
					{
						minDiff=diff;
						startIndex=i-k;
						endIndex=i-1;
					}
			}
		
		//cout << startIndex << " " << endIndex << endl;

		for(i=startIndex; i<=endIndex; i++)
			{
				ans=ans-(a[i]*m1)+a[i]*m2;
				m2++;
				m1--;
			}

		cout << ans << endl;
		return 0;
	}