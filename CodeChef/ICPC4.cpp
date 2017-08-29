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
lli prefix[100007];

int main()
	{
		int t, n, i;

		cin >> t;

		while(t--)
			{
				cin >> sum >> n >> x;

				for(i=0; i<n; i++)
					cin >> a[i];

				sum+=a[0];

			}

		return 0;
	}