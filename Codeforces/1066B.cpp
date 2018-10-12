#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

int a[1007], cover[1007];
vector < pair <int, int> > vs;

void covers(int l, int r) {
    for(int i = l; i <= r; i++) cover[i] = 1;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
        cout.tie(NULL);

        int n, m, r, i, j, u, v, ans = 0;
        bool ansx = 1;

        cin >> n >> r;

        for(i = 1; i <= n; i++) cin >> a[i];

        for(i = 1; i <= n; i++) {
            if(a[i] == 1) {
                vs.pb({i - r + 1, i + r - 1});
            }
        }
        
            // for(i = 0; i < vs.size(); i++) {
            //     cout << vs[i].f << " " << vs[i].s << endl;
            // }

        for(i = 1; i <= n; i++) {
            if(!cover[i]) {
                u = -1;

                for(j = 0; j < vs.size(); j++) {
                    if(vs[j].f <= i && vs[j].s >= i) u = j;
                }

                if(u == -1) ansx = 0;
                else {
                    covers(vs[u].f, vs[u].s);
                    ans++;
                }
            }
        }

        if(ansx == 0) ans = -1;

        cout << ans << endl;

		return 0;   
	}