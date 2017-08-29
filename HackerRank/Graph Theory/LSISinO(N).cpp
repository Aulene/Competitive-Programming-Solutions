#include <iostream>
using namespace std;

int main(){
#define int long long
    int n, k;
    cin >> n >> k;
    
    int nfactorial = 1, kfactorial = 1, nkfactorial = 1;
    
    for(int i = 1; i <= n; i++){
        nfactorial *= i;
        if(i == k)
            kfactorial = nfactorial;
        if(i == n - k)
            nkfactorial = nfactorial;
    }
    
    cout << nfactorial/(kfactorial * nkfactorial) << endl;
    return 0;
}