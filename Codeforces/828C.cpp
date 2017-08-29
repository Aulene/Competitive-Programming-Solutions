#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define F first
#define S second

char ans[2000007];
 
int main() 
{
    int n, i, j, k, x, len = 0, l;
    string s;

    cin >> n;

    for (i = 0; i < 2000007; i++)
        ans[i] = 'a';

    for(i = 0; i < n; ++i) 
	    {
	        cin >> s >> k;

	        for(j = 0; j < k; j++) 
		        {
		            cin >> x;
		            x--;
		            x += s.size();

		            len = max(len, x);

		            x -= s.size();

		            for(l = 0; l < s.size(); l++)
		                ans[l + x] = s[l];
		        }
	    }

    for (i = 0; i < len; ++i)
        cout << ans[i];
    cout << endl;
	return 0;
}