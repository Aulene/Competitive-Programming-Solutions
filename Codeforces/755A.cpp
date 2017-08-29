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

bool primes[100007];

int sieve()
{
	int i, j;

	for(i=0; i<10007; i++)
		primes[i]=1;
	primes[0]=0;
	primes[0]=0;

	for(i=2; i<10007; i++)
		if(primes[i])
			{
				for(j=2*i; j<10007; j+=i)
					primes[j]=0;
			}

	return 0;
}

int main()
	{
		sieve();

		int n, m, i;

		cin >> n;

		for(i=1; i<=1000; i++)
			if(!primes[n*i+1])
				{
					cout << i << endl;
					return 0;
				}

		return 0;
	}