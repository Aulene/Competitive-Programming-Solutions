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

int dp[100007];
int inst[100007];
int a[100007];

int main()
	{
		int n, m, i, j;
		int count=0;

		cin >> n >> m;

		for(i=1; i<=n; i++)
			cin >> a[i];

		for(i=n; i>=1; i--)
			{
				inst[a[i]]++;

				if(inst[a[i]]==1)
					count++;

				dp[i]=count;
			}

		while(m--)
			{
				cin >> n;
				cout << dp[n] << endl;
			}
		return 0;
	}