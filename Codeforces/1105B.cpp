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
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

string s;
int n, k;
map <char, vector<int> > runs;

signed main() 
{
    ios::sync_with_stdio(false);

    cin >> n >> k >> s;
    s.push_back(' ');
    int last = 0;
   	for(int i = 1; i <= n; i++) {
    	if(s[i] != s[last]) {
    		if(i-last >= k) runs[s[last]].push_back(i-last);
    		last = i;
    	}
    }
    int ans = 0;
    for(auto& pr : runs) {
    	int cur = 0;
    	vector<int>& v = pr.second;
    	for(int run : v) cur += run/k;
    	ans = max(ans, cur);
    }
   
    cout << ans << endl;

    return 0;
}
