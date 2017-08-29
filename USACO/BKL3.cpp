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

lli s[6];

lli xorshift128plus(void) {
	lli x = s[0];
	lli const y = s[1];
	s[0] = y;
	x ^= x << 23; // a
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26); // b, c
	return s[1] + y;
}

int main()
	{
		lli ans, i;

		cin >> s[0] >> s[1];

		for(i=0; i<3; i++)
			{
				s[0]=xorshift128plus();
				cin >> s[1];
				//cout << s[0] << " " << s[1] << endl;
			}

		cout << s[0] << endl;


		return 0;
	}