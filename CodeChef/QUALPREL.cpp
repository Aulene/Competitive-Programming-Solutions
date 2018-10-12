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
#define vi vector <int> 

vi vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
        cout.tie(NULL);

        int t, n, m, i, j, u, v;

        cin >> t;

        while(t--) {
            vs.clear();

            cin >> n >> m;
            
            for(i = 0; i < n; i++) cin >> u, vs.pb(u);
            
            sort(vs.begin(), vs.end(), greater <int>());

            u = vs[m - 1];
            int ans = 0;

            for(i = 0; i < vs.size(); i++)
                if(vs[i] >= u) ans++;

            cout << ans << endl;
        }
		return 0;   
	}