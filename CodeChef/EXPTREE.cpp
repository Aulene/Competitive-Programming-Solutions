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

int powll(int b, int p, int m)
{
	if(!p)
		return 1;
	if(p == 1)
		return b % m;
	
	int x = powll(b, p / 2, m) % m;
	x = (x * x) % m;
	if(p & 1)
		x = (x * (b % m)) % m;
	return x % m;
}
 
int inverse(int a, int m)
{
	return powll(a, m-2, m);
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
 
			num1 = (((n % mod) + ((mod - 1) % mod)) % mod) % mod; 
			num1 *= ((n % mod) + ((mod - 1)) % mod) % mod; 
			num1 *= n % mod;
			denom1 = ((((2 % mod) % mod * (n % mod))) % mod + (mod - 3) % mod) % mod;
			denom1 *= ((((2 % mod) % mod * (n % mod))) % mod + (mod - 2) % mod) % mod;
 	
 			num2 = (((n % mod2) + ((mod2 - 1) % mod2)) % mod2) % mod2; 
			num2 *= ((n % mod2) + ((mod2 - 1)) % mod2) % mod2; 
			num2 *= n % mod2;
			denom2 = ((((2 % mod2) % mod2 * (n % mod2))) % mod2 + (mod2 - 3) % mod2) % mod2;
			denom2 *= ((((2 % mod2) % mod2 * (n % mod2))) % mod2 + (mod2 - 2) % mod2) % mod2;


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
 			
 		// 	cout << (denom1 * inverse(denom1, mod)) % mod << endl;
			// cout << (denom2 * inverse(denom2, mod2)) % mod2 << endl;

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
 