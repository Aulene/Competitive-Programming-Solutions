#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define rep(i,s,e) for(i=s;i<=e;i++)
#define reprev(i,s,e) for(i=s;i>=e;i--)
#define reps(b,e,g,str) for(b=str,e=&str[g-1];b<=e;b++) 
#define mem(arr,val) memset(arr,val,sizeof(arr))

ll a[100010],b[100010];

int main()
{
	ll n,i,s,ptr,cnt,res=0;
	cin>>n;
	rep(i,0,n-1)
		cin>>a[i];
	sort(a,a+n);
	ptr=0;
	for(i=n-1;i>=1;i--)
	{
		if(a[i]-a[i-1]<=1)
		{
			b[ptr]=a[i-1];
			ptr++;
			i--;
		}
	}
	for(i=0;i<=ptr-2;i+=2)
	{
		res += b[i] * b[i + 1];
	}
	cout<<res<<endl;
	return 0;
}
