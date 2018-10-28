#include <bits/stdc++.h>
#include <unordered_map>

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
#define vpi vector < pair <int, int> > 
#define pi pair <int, int>

const int N = 200007;

int a[N], inc[N], d[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
        int n, m, i, j, u, v, w, h, sum = 0, ans = 0;

        cin >> n >> m;

        for(i = 0; i < n; i++) cin >> a[i], sum += a[i];

        int low = 0, high = INT_MAX;
        int cad = 0;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(sum * mid <= m) {
                cad = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }  

        ans += cad * n;
        m -= cad * sum;

        i = 0;
        
        while(m) {
            if(a[i] <= m) {
                ans++;
                m -= a[i];
            }
            i = (i + 1) % n;
        }

        cout << ans << endl;

		return 0;
	}