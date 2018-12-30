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

const int N = 100007;

int c[N], dp[N][7];

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
        
        int n, m, i, j, u, v, ans = LLONG_MAX;
        string s, hard = ".hard";
        
        cin >> n >> s;
        s = "." + s;

        for(i = 1; i < N; i++)
            for(j = 1; j < 7; j++) dp[i][j] = LLONG_MAX;

        for(i = 1; i <= n; i++) cin >> c[i];

        dp[1][1] = 0;

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= 4; j++) {
                if(dp[i][j] == LLONG_MAX) continue;

                if(s[i] == hard[j]) {
                    dp[i + 1][j] = min(dp[i][j] + c[i], dp[i + 1][j]);
                    if(j < 4) 
                        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]); 
                }
                else dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            } 
        }

        for(i = 1; i <= 4; i++) ans = min(ans, dp[n + 1][i]);

        cout << ans << endl;

        return 0;
    }