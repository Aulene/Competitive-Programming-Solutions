// Modular Multiplicative Inverse from https://discuss.codechef.com/questions/1440/algorithm-to-find-inverse-modulo-m
 
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
 
void EE(int a, int b, int &x, int &y)
{
    if(!(a % b))
	    {
	        x=0;
	        y=1;
	        return;
	    }
 
    EE(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - y * (a / b);
}
 
int inverse(int a, int m)
{
    int x, y;
    EE(a, m, x, y);
    
    if(x < 0) 
    	x += m;
 
    return x;
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
 
				num1 = ((n % mod - 1 % mod) % mod * (n % mod - 1 % mod) % mod * n % mod) % mod;
				denom1 = ((((2 * (n % mod)) % mod - 3 % mod) % mod) * (((2 % mod * n % mod) % mod - 2 % mod) %mod)) % mod;
 
				num2 = ((n % mod2 - 1 % mod2) % mod2 * (n % mod2 - 1 % mod2) % mod2 * n % mod2) % mod2;
				denom2 = ((((2 * (n % mod2)) % mod2 - 3 % mod2) % mod2) * (((2 % mod2 * n % mod2) % mod2 - 2 % mod2) %mod2)) % mod2;
 
 
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
 
				x = inverse(denom1, mod);
				y = inverse(denom2, mod2);
 
				ans1 = (x % mod * num1 % mod) % mod;
				ans2 = (y % mod2 * num2 % mod2) % mod2;
				// cout << num << " " << denom << endl;
				cout << ans1 % mod << " " << ans2 % mod2 << endl;
 
			}
 
		return 0;
	} 
