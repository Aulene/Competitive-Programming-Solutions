#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
 
using namespace std;
 
 
 
int main()
{
    ll n, m, rem, fol, ses, k, col;
    cin >> n >> m;
    cin >> k;
 
    if(k<n)
    {
        cout << k+1 << " 1\n"; return 0;
    }
    if(k==n) 
    {
        cout << n << " 2\n"; return 0;
    }
    rem=k-(n);
    fol=rem/(m-1);
    ses=rem%(m-1);
    //cout << fol << " " << ses << endl;
    if((fol&1)==0)
    {
        if(ses==0) col=2;
        else col=2+ses;
    }
    else
    {
        if(ses==0) col=m;
        else col=m-ses;
    }
    cout << n-fol << " " << col << endl;
 
    return 0;
 
 
}