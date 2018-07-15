#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int f(int x, int n, int m){
    int res = 0;
    --x;
    for(int i=1;i<=n;++i) res+=min((int)m, x/i);
    return res;
}

signed main(){
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
    
    int n, m;
    
    cin>>n>>m;
    
    int k;
    
    cin>>k;
    
    
    int l = 1, r = 1LL*n*m+1;
    
    while(l<r){
        int x = (l+r)>>1;
        
        if(f(x,n,m)<k) l = x+1; else r = x;
    }
    
    cout<<l-1<<endl;
    
    return 0;
}