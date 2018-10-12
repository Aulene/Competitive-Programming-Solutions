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

int pos[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
        cout.tie(NULL);

        int t, n, i, j, u, v;
        char op;

        int lidx = -1, ridx = 1;

        cin >> t;

        for(int T = 1; T <= t; T++) {
            cin >> op >> n;

            if(T == 1) {
                pos[n] = 0;
                continue;
            }

            if(op == 'L') {
                pos[n] = lidx;
                lidx--;
            }
            else if(op == 'R') {
                pos[n] = ridx;
                ridx++;
            }
            else {
                // cout << n << " " << pos[n] << " " << lidx << " " << ridx << endl;
                int ans1 = lidx - pos[n];
                ans1 = abs(ans1);
                int ans2 = ridx - pos[n];
                int ans = min(ans1, ans2) - 1;

                cout << ans << endl; 
            }
        }

		return 0;   
	}