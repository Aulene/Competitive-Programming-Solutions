#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

class MyCalendarThree {
public:
	map <int, int> s;

    MyCalendarThree() {
    	
    }
    
    int book(int start, int end) {
    	int ans = 0, act = 0, u = start, v = end;;

    	s[u]++, s[v]--;

        for(map <int, int> :: iterator it = s.begin(); it != s.end(); it++)
        	{
        		act += it -> second;
        		ans = max(ans, act);
        	}
        	
		return ans;
    }
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, u, v;
		// set < pair <int, int> > s;
		map <int, int> s;
		cin >> n;

		for(int i = 0; i < n; i++) {
			cin >> u >> v;
			// s.insert(mp(u, v));

			int ans = 0, act = 0;

	    	s[u]++, s[v]--;

	        for(map <int, int> :: iterator it = s.begin(); it != s.end(); it++)
	        	{
	        		cout << it -> first << " " << it -> second << endl;

	        		act += it -> second;
	        		ans = max(ans, act);
	        	}
				// cout << it -> first << " " << it -> second << endl;
			
				
			cout << ans << endl;
		}

		return 0;
	}