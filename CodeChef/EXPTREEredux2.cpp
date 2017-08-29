// Modular Multiplicative Inverse from https://comeoncodeon.wordpress.com/2011/10/09/modular-multiplicative-inverse/

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
 
#define int long long int
#define mod 1000000007
#define mod2 1000000009
#define p push
#define pb push_back
#define mp make_pair
 
int gcd(int a, int b)
{
	if (a == 0)
	    return b;
	return gcd(b % a, a);
}
 
int pow(int a, int b, int MOD) 
{
	int x = 1, y = a;
    while(b > 0) 
	    {
	        if(b % 2) 
		        {
		            x = (x * y);
		            if(x > MOD) 
		            	x %= MOD;
		        }
	        y = (y * y);

	        if(y > MOD)
	        	y %= MOD;

	        b /= 2;
	    }

    return x;
}
 
int modInverse(int a, int m) {
    return pow(a, m - 2, m);
}
 
signed main()
{
	int n, t;
	int num1, denom1, num2, denom2, gcdd, gcdd2;
	int ans1, ans2;
	int x, y;
 
	cin >> t;	
 
	while(t--)
		{
			cin >> n;
 
			num1 = ((n % mod + (mod - 1) % mod) % mod * (n % mod + (mod - 1) % mod) % mod * n % mod) % mod;
			denom1 = ((((2 * (n % mod)) % mod + (mod - 3) % mod) % mod) * (((2 % mod * n % mod) % mod + (mod - 2) % mod) %mod)) % mod;
 
			num2 = ((n % mod2 + (mod2 - 1) % mod2) % mod2 * (n % mod2 + (mod2 - 1) % mod2) % mod2 * n % mod2) % mod2;
			denom2 = ((((2 * (n % mod2)) % mod2 + (mod2 - 3) % mod2) % mod2) * (((2 % mod2 * n % mod2) % mod2 + (mod2 - 2) % mod2) %mod2)) % mod2;

 
			gcdd = gcd(num1, denom1);
			gcdd2 = gcd(num2, denom2);
 
			if(gcdd)
				{
					num1 /= gcdd;
					denom1 /= gcdd;
				}
 
			if(gcdd2)
				{
					num2 /= gcdd2;
					denom2 /= gcdd2;
				}
 
			x = modInverse(denom1, mod);
			y = modInverse(denom2, mod2);
 
			ans1 = (x % mod * num1 % mod) % mod;
			ans2 = (y % mod2 * num2 % mod2) % mod2;
			// cout << num << " " << denom << endl;
			if(ans1 < 0)
				ans1 += mod;
			if(ans2 < 0)
				ans2 += mod2;
			
			cout << ans1 % mod << " " << ans2 % mod2 << endl;
 
		}
 
	return 0;
} 
 