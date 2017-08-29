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
int best[100007];

int main()
	{
		int n, i;

		cin >> n;

		for(i=0; i<n; i++)
			cin >> a[i];

		for(i=0; i<n; i++)
			best[i]=max(a[i], a[i]+best[i-1]);

		for(i=0; i<n; i++)
			cout << best[i] << " ";
		cout << endl;
		
		return 0;
	}