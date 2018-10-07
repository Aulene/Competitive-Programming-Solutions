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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, q, u, v, i, j, x, y, ans;
        
        cin >> t;

        while(t--)
            {
                bool ans = 1;

                cin >> u >> v;
                x = u - v;
                y = u + v;
                
                for(int i = 2; i <= sqrt(y); i++) {
                    if(y % i == 0) ans = 0;
                }

                if(x == 1 && ans) cout << "YES\n";
                else cout << "NO\n";  
            }
		return 0;
	}