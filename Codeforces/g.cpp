#include<bits/stdc++.h>
	#define fs first
#define se second
#define mp make_pair
#define pb push_back
#define precise(n,k) fixed<<setprecision(k)<<
using namespace std;
typedef long long ll;
typedef long double lf;
ll n;
string s;
map<ll,ll> m;
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>s;
	ll turn=(n-11)/2;
//	ll flag=q;
	ll cnt=0;
	for(ll i=0;i<n;i++)
	{
		if(s[i] == '8')
		{
		cnt++;
		m[cnt]=i;
		}
	}
	if(cnt<=turn)
	{
		cout<<"NO";
		return 0;
	}
	if(m[turn+1]-(turn)<=turn)
	{
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
		return 0;
	return 0;
}