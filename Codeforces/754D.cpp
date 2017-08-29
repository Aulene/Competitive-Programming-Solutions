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

struct segment
{
	lli x, y;	
};

segment s[300007];

int main()
	{
		int n, k, i;

		cin >> n >> k;

		for(i=0; i<n; i++)
			cin > s[i].x >> s[i].y;
		
		

		return 0;
	}