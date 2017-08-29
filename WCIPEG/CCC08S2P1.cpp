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

struct c
{
	string name;
	int s, e;
};

c a[107];

int main()
	{
		int n, i;

		cin >> n;

		for(i=0; i<n; i++)
			cin >> a[i].name >> a[i].s >> a[i].e;

		
		return 0;
	}