#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <map>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i=0; i<n; i++)
#define FOR(i, a, b) for(ll i = a; i<=b; i++)
#define FORD(i, a, b) for(ll i = a; i>=b; i--)
#define DEBUG(x) cout<<#x<<" > "<<x<<endl;

const ll MX = 5*1e3 + 2;
const ll MOD = 1e9 + 7;

ll n, a, b, k;
ll dp[MX][MX]; // DP[i][j] = No. of ways to reach floor i after j moves.
ll ps[MX]; //ps[i] = Sum of moves to reach floors 1->i after j-1 moves

int main()
{
        int i, j;

        cin>>n>>a>>b>>k;
        ll l, r;
        dp[a][0]=1;
        FOR(i, 1, k)
        {
                FOR(j, 1, n)
                {
                        ps[j] = (ps[j-1]  + dp[j][i-1] ) ;
                }
                FOR(j, 1, n)
                {
                        if(j==b)
                                continue;
                        if(j<b)
                        {
                                l = 1;
                                r = (j+b-1)/2;
                        }
                        else
                        {
                                l = (j+b)/2+1;
                                r = n;
                        }
                       // DEBUG(i);
                       // DEBUG(l);
                       // DEBUG(r);
                        
                        dp[j][i] += (ps[r]-ps[l-1])%MOD;
                        dp[j][i] -= dp[j][i-1];
                        dp[j][i] += MOD;
                        dp[j][i] %= MOD;
                }
        }
            
        for(i=1; i<=k; i++)
            {
                for(j=1; j<=n; j++)
                    cout << dp[j][i] << " ";
                cout << endl;   
            }
        ll ans=0;
        FOR(i, 1, n)
        {
                ans+=dp[i][k];
                ans%=MOD;
        }
        
        cout<<ans<<endl;
}