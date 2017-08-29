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

lli dp[1007][1007];
lli sex[10007];

int main()
	{
		int t, i, j, n;
		string s;

		cin >> t;

		while(t--)
			{
				cin >> s;
				n = s.size();

				for(i=0; i<1007; i++)
					for(j=0; j<1007; j++)
						dp[i][j] = 0;

				for(i=0; i<n; i++)
					dp[1][s[i] - 'A' + 1] = 1;


			}

		return 0;
	}