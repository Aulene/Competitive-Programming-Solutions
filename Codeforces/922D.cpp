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

vector <string> vs;

bool cmp(string a, string b)
{
    string ok = a + b, rev = b + a;
    int okn = 0, revn = 0;

    for(int i = 0; i < ok.size(); i++)
    {
        if(ok[i] == 's')
            okn += i;
        if(rev[i] == 's')
            revn += i;
    }
    return okn < revn;
}
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans = 0;
		string s;

		cin >> n;

		for(i = 0; i < n; i++) cin >> s, vs.pb(s);

		sort(vs.begin(), vs.end(), cmp);

		s = "";
		for(i = 0; i < vs.size(); i++) s += vs[i];

		j = 0;

		for(i = 0; i < s.size(); i++)
			{
				if(s[i] == 's') j++;
				else ans += j;
			}

		cout << ans << endl;
		return 0;
	}