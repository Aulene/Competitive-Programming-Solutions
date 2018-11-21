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

const int N = 200007;

vpi pts;
vi men, menx;
int vs[N];

void compute(pi pt, int l) {
    int a = pt.f, b = pt.s;

    int lt = b - l + a;
    int rt = l - b + a;
    // lt = max(lt, 0LL);
    if(lt > rt) swap(lt, rt);

    cout << lt << " " << rt << endl;

    int idx;
    idx = upper_bound(men.begin(), men.end(), lt - 1) - men.begin();
    cout << idx << " ";
    vs[idx]++;
    idx = upper_bound(men.begin(), men.end(), rt) - men.begin();
    vs[idx]--; cout << idx << endl << endl;
}

signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n, m, l, i, j, u, v;

        cin >> n >> m >> l;

        for(i = 0; i < n; i++) {
            cin >> u >> v;
            pts.pb({u, v});
        }

        for(i = 0; i < m; i++) {
            cin >> u;
            men.pb(u); menx.pb(u);
        }

        sort(men.begin(), men.end());

        for(auto it : pts) compute(it, l);

        for(i = 1; i <= 10; i++) cout << vs[i] << " "; cout << endl;

        for(i = 0; i < N; i++) vs[i] = vs[i] + vs[i - 1];
        
        for(i = 1; i <= 10; i++) cout << vs[i] << " "; cout << endl;
        
        for(i = 0; i < m; i++) cout << vs[menx[i]] << endl;
        return 0;
    }