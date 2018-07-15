#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl "\n"
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define boost ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n"; 
#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define int long long int

// typedef long long int int;
typedef pair<int,int> pii;
typedef priority_queue< pii , vector< pii > , greater< pii > > pq;
const int N=1e5+10;
 
int n,m,k,last[500];
string s[600];
int dp[505][505][505][2];
 
int fun(int i, int j, int rem, int start)
{
	if(dp[i][j][rem][start]!=-1)
		return dp[i][j][rem][start];
 
	if(i>=n)
		return dp[i][j][rem][start]=0;
 
	if(j>last[i])
		return dp[i][j][rem][start]=fun(i+1,0,rem,0);
 
 
	int ans;
	if(s[i][j]=='0'){
		if(start==0){
			if(j!=m-1){
				ans=fun(i,j+1,rem,0);
			}
			else{
				ans=fun(i+1,0,rem,0);
			}
		}
		else{
			if(j!=m-1){
				ans=1+fun(i,j+1,rem,1);
			}
			else{
				ans=1+fun(i+1,0,rem,0);
			}	
		}
	}
 
	else{
 
		if(start==1){
			if(j!=m-1){
				ans=1+fun(i,j+1,rem,1);
			}
			else{
				ans=1+fun(i+1,0,rem,0);
			}
 
			if(rem>=(last[i]+1-j))
				ans=min(ans,fun(i+1,0,rem-(last[i]+1-j),0));
 
		}
 
		else{
			if(j!=m-1){
				ans=1+fun(i,j+1,rem,1);
			}
			else{
				ans=1+fun(i+1,0,rem,0);
			}
			if(rem>0){
				if(j!=m-1)
					ans=min(ans,fun(i,j+1,rem-1,0));
				else
					ans=min(ans,fun(i+1,0,rem-1,0));
			}
		}
	}
 
	return dp[i][j][rem][start]=ans;
}
 
signed main(){
	boost;
	int i, j, l;

	for(i = 0; i < 507; i++)
		last[i] = 0;

	for(i = 0; i < 507; i++)
		for(j = 0; j < 507; j++)
			for(l = 0; l < 507; l++) dp[i][j][l][0] = dp[i][j][l][1] = -1;
	cin>>n>>m>>k;

	for(i=0;i<n;i++)
		cin>>s[i];
 
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(s[i][j]=='1')
				last[i]=max(last[i],j);
		}
	}
 
	int ans=fun(0,0,k,0);
	cout<<ans<<endl;
	return 0;
}