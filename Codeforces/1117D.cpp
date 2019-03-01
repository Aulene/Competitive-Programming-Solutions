#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define mod 1000000007
#define int long long int
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

const int MAXN = 107;

struct matrix{
    int N = MAXN; // N <= MAXN
    int a[MAXN][MAXN]; 
    
    matrix(){
        memset(a, 0, sizeof(a));
    }
    matrix(int n){
        N = n;
        memset(a, 0, sizeof(a));
    }
    decltype(a[0]) operator[](int x){
        return a[x];
    }
    static matrix  I(int n){
        matrix m(n);
        for(int i = 0; i < n; i++) m[i][i] = 1;
        return m;
    }
    
    matrix friend operator*(matrix &a, matrix &b){
        matrix c;
        for(int i=0; i<a.N; i++){
            for(int j=0; j<a.N; j++){
                for(int k = 0; k<a.N; k++){
                    c[i][j] += 1LL * a[i][k] * b[k][j] % mod;
                    c[i][j] %= mod;
                }
            }
        }
        return c;
    }
    matrix friend operator^(matrix &a, int b){
        matrix ans = I(a.N);
        while(b){
            if(b%2!=0) ans = ans*a;
            a = a*a;
            b>>=1;
        }
        return ans;
    }
    
};

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
			
		int n, m, i, j, u, v;

		cin >> n >> m;

		matrix mxp(m);

		mxp[0][0] = mxp[0][m - 1] = 1;
		for(int i = 1; i < m; i++) mxp[i][i - 1] = 1;

		if(n > m - 1) {
			mxp = mxp ^ (n - m + 1);
			int ans = 0;
			for(i = 0; i < m; i++) ans = (ans + mxp[0][i]) % mod;
			cout << ans << endl;
		}
		else cout << 1 << endl;
		return 0;
	}