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
#define pi pair <int, int>
#define vvi vector < vector <int> >
#define vpi vector < pair <int, int> >
#define ppi pair < pair <int, int>, int>
#define vvpi vector < vector < pair <int, int> > >
#define zp mp(0, 0)

const int N = 1000007;

int a[N], dp[N];

signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n, m, i, j, u, v, ans = 0;

        cin >> n;

        for(i = 0; i < n; i++) cin >> a[i];

        for(i = n - 1; i >= 0; i--) {
            for(j = 1; a[i] * j < N; j++)
                dp[a[i]] = max(dp[a[i]], dp[a[i] * j] + 1);
            ans = max(ans, dp[a[i]]);
        }

        cout << ans << endl;
        
        return 0;
    }