#include <iostream>
using namespace std;

#define ll long long 
const int mod = 1e9+7;

int main(){
    int n, k;
    cin >> n >> k;
    
    ll nfactorial = 1, kfactorial = 1, nkfactorial = 1;
    
    for(int i = 1; i <= n; i++){
        nfactorial = ((nfactorial%mod) * (i%mod))%mod;
        
        if(i == n - k)
            nkfactorial = nfactorial;
        
        if(i == k)
            kfactorial = nfactorial;
    }
    
    ll d = ((kfactorial %mod) * (nkfactorial %mod)) % mod;

    cout << nfactorial/d << endl;
    return 0;
}