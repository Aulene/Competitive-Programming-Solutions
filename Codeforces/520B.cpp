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

lli m;
bool visited[100007];
lli dp[100007];

lli recur(int n)
{
	if(n<1)
		return 100007;

	if(n==m)
		return 0;

	if(visited[n])
		return dp[n];

	visited[n]=1;

	lli ans1, ans2=100007;

	ans1=recur(n-1);
	if(n<m)
		ans2=recur(n*2);

	return dp[n]=1+min(ans1, ans2);
}

int main()
	{
		lli n;
		cin >> n >> m;
		cout << recur(n) << endl;
		return 0;
	}