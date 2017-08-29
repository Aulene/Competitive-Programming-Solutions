#include<iostream>
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
#define pb push_back

lli ans=INT_MAX;
lli a, b;

int main()
	{
		lli n, i;
		string s;

		cin >> n >> a >> b;
		cin >> s;

		a--;
		b--;
		
		if(s[a]==s[b])
			ans=0;
		else
			ans=1;

		cout << ans << endl;
		return 0;
	}