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

#define lli unsigned long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

lli factorials[1000007];
lli m;

lli fact(lli a)	
{
	if(factorials[a])
		return factorials[a];
	else
		{
			factorials[a] = (a * fact(a-1)) % m;
			return factorials[a];
		}
}

lli perform(lli a, lli b)
{
	if(a % b == 0)
		{
			lli t = a / b;
			cout << t << " 1" << endl;
		}
	else
		{
			lli t = a / b;
			lli n = t + 1;
			lli x = (t + 1)*b - a;
			lli r1 = fact(n+x-1);
			r1 /= fact(x);
			r1 /= fact(n-1);
			lli ans = r1 % m;

			cout << n << " " << ans << endl;
		}

	return 0;
}

int main()
	{
		lli t, i, a, b, c;

		factorials[0]=1;
		
		cin>>t;

		for(i = 0; i < t; i++)
	    	{
	    		cin >> a >> b >> m;
	    		perform(a, b);
	    	}

	    return 0;
	}
