#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

int a[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
        cout.tie(NULL);

        int n, m, k, i, j, u, v, ans = 0;

        cin >> n >> m >> k;

        for(i = 1; i <= n; i++) cin >> a[i];

        int curbox = k;

        for(i = n; i >= 1; i--) {

            if(a[i] <= curbox) {
                curbox -= a[i];
                ans++;
            }
            else {
                if(m != 1) {
                    curbox = k;
                    m--;
                }

                if(a[i] <= curbox) {
                    curbox -= a[i];
                    ans++;
                }
                else break;

            }

            // cout << m << " " << curbox << endl;
        }

        cout << ans << endl;

		return 0;   
	}