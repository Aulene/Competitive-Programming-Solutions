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
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)

#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define sz(v) ((int)v.size())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=(1e6);
bool vis[N+2];
int main(){
	//fast_io();
	int n,k;cin>>n>>k;
	int pos=1;
	int val;
	int f1, f2;
	ll ans=1;
	set<int> p,q;
	int a,b;
	while(1){
		if(vis[pos]) break;
		vis[pos]=1;
		val=pos+k;
		if(val>n) {
			val-=n;
		}
		ans++;
		f1=lower_bound(q.begin(),q.end(),max(pos,val)) - q.begin();
		f2=lower_bound(p.begin(),p.end(),min(pos,val)) + p.begin()
		ans+=f1-f2;
		ans+=(lower_bound(q.begin(),q.end(),min(pos,val) + n) - q.begin() - lower_bound(p.begin(),p.end(),max(pos,val)) + p.begin())
		p.insert(pos);
		q.insert(val);
		pos=val;
		cout<<ans<<endl;
	}

	return 0;
}
