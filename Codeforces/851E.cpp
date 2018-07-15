#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

map <int, vector <int> > M;
vector < pair <int, int> > vs;

signed main()
{
    int n, j, i, N, ans = 0;

    cin >> n;

    for(i = 0; i < n; i++) 
	    {
	        cin >> N;

	        vs.clear();
	        
	        for(j = 2; j * j <= N; j++) 
		        if(N % j == 0) 
		            {
		                vs.pb(mp(j, 0));

		                while(N % j == 0) 
			                {
			                    vs[vs.size() - 1].s++;
			                    N /= j;
			                }
		            }

	        if(N > 1) vs.pb(mp(N, 1));
	        for(auto it : vs) M[it.f].pb(it.s);
	    }
 
    for(auto it: M) 
	    {
	        j = it.s.size();
	        sort(it.s.begin(), it.s.end());
	        ans ^= it.s[0];
	        for(i = 1; i < j; i++) ans ^= it.s[i] - it.s[i - 1];
	    }
 
    if(ans) cout << "Mojtaba" << endl;
    else cout << "Arpa" << endl;
 
    return 0;
}