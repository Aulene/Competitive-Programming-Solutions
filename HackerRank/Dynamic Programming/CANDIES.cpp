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

int a[100007];
int dp[100007];
int n;

int recur(int index)
{
	if(index>=n)
		return 1;

	int ans;

	if(a[index]>a[index]+1)
		ans=2+recur(index+1);
	else
		ans=1+recur(index+1);

	return ans;
}

int main()
	{
		int i;

		cin >> n;

		for(i=0; i<n; i++)
			cin >> a[i];

		cout << recur(0) << endl;
		return 0;
	}