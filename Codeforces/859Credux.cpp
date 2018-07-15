#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;
 
int n,dp[55][3],ar[55],sum=0;

int calc(int idx,int who){
	if (idx==n)
		return 0;
	int &tmp = dp[idx][who];
	if (tmp!=-1)
		return tmp;
	tmp=0;
	if (who==1)
		tmp=max(ar[idx]+calc(idx+1,2),calc(idx+1,1));
	else 
		tmp=min(ar[idx]+calc(idx+1,2),calc(idx+1,1));
	return tmp;
}
 
int main() {
 
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&ar[i]),sum+=ar[i];
	int ans=calc(0,1);
	printf("%d %d",sum-ans,ans);
 
	return 0;
}
