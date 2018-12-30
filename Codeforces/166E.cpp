#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

const int K = 4;

vvi mul(vvi a, vvi b) {

    vvi ans(K + 1, vi(K + 1));

    for(int i = 1; i <= K; i++)
        for(int j = 1; j <= K; j++)
            for(int k = 1; k <= K; k++)
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;

    return ans;
}

vvi pow(vvi a, int n) {

    if(n == 1) return a;
    if(n % 2)
        return mul(a, pow(a, n - 1));
    vvi b = pow(a, n / 2);
    return mul(b, b);
}

signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        // ifstream cin ("/Users/Aulene/Desktop/input.txt");
        // ofstream cout ("/Users/Aulene/Desktop/output.txt");

        // ifstream cin ("input.txt");
        // ofstream cout ("output.txt");
        
        // ifstream cin ("usaco.in");
        // ofstream cout ("usaco.out");
        
        int n, m, i, j, k, u, v, ans = 0;

        cin >> n;  

        if(n == 1) {
            cout << 0 << endl;
            return 0;
        }

        vvi a(K + 1, vi(K + 1));

        for(i = 1; i <= K; i++)
            for(j = 1; j <= K; j++) a[i][j] = 1;
        for(i = 1; i <= K; i++) a[i][i] = 0;

        a = pow(a, n - 1);

        for(i = 2; i <= K; i++) ans = (ans + a[1][i]) % mod;
        cout << ans << endl;

        return 0;
    }