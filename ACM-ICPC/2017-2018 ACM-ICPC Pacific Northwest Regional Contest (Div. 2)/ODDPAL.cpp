#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

        string s, s1, s2;
        int n, m, i, j, u, v;
        bool ans = 1;

        cin >> s; n = s.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s1 = s.substr(i, j);
                s2 = s1;
                reverse(s1.begin(), s1.end());

                if(s2.size() == 0) continue;

                if(s1 == s2) {
                    // cout << s1 << " " << s2 << " " << s2.size() << endl;
                    if(s2.size() % 2 == 0) ans = 0;
                }
            }
        }

        if(ans) cout << "Odd.\n";
        else cout << "Or not.\n";
		return 0;
	}