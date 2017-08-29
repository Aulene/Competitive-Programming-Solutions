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

int a[5007];

int recur(int index, int dir)
{
	int ans1, ans2, ans;

	if(dir==0)
		{
			if(index==1)
				{
					ans=1+recur(index+1)
				}
		}
}
int main()
	{
		int n, i;

		cin >> n;

		for(i=1; i<=n; i++)
			cin >> a[i];


		return 0;
	}