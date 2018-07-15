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

#define fuck 2000000000
#define hell 2000000000000000000
#define ff first
#define ss second 
#define forn(i,n) for (int i=0;i<int(n);i++)
#define nfor(i,n) for (int i=int(n)-1;i>=0;i--)
#define N 100010
#define M 1000010
using namespace std;
const int MOD = 1000000007;
const double PI = acos(-1.0);
int gcd(int a,int b){return (b==0) ? a : gcd(b,a%b);}
 
int n;
int y[1005];
bool vis[1005]={};
int main(){
 
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&y[i]);
	}
	bool can = true;
	double m = -1.0;
	for (int i=3;i<n;i++){
		if (m==-1.0){
			m = (y[i]-y[i-1]-0.0)/(i-(i-1.0));
			continue;
		}
		if ((y[i]-y[i-1]-0.0)/(i-(i-1.0))!=m)
			can=false;
	}
	if(can){
		puts("Yes");
		return 0;
	}
	can=true;
	for (int i=2;i<=n;i++){
		can=true;
		memset(vis,0,sizeof vis);
		m=(y[i]-y[1]-0.0)/(i-1.0);
		vis[i]=true;
		vis[1]=true;
		int last=i;
		for (int j=i+1;j<=n;j++){
			if ((y[j]-y[last]-0.0)/(i-last)==m)
				vis[j]=true,last=j;
		}
		int base = -1;
		for (int j=i+1;j<=n;j++){
			if (!vis[j]&&base==-1)
				base=j;
			else if (!vis[j])
				if ((y[j]-y[base]-0.0)/(j-base)!=m){
					can=false;
					break;
				}
		}
		if (can){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}