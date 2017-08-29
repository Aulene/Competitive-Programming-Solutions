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

int a[100007];

int main()
	{
		int n, i;
		int p1=0, p2;

		cin >> n;

		for(i=0; i<n; i++)
			cin >> a[i];

		int current=1, ans=1;

		for(i=1; i<n; i++)
			{
				if(a[i]<=a[i-1])
					{
						if(!p1)
							{
								p1=i;
								continue;
							}

						
					}
			}
		return 0;
	}