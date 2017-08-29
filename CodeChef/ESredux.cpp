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
#define e 2.7182818284

lli multiplier[4007], maxMultiplier[4007], ans[4007];

lli digitsInMultiplier = 1, digitsInMaxMultiplier = 0;


lli addToMultiplier()
{
	return 0;
}

int main()
	{
		lli n, i, sum = 0, num;
		string s;

		cin >> n;

		sum = e * n * n / 2;

		cout << sum << endl;

		return 0;
	}