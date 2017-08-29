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
#define pb push_back

int main()
	{
		ofstream fout ("inp.txt");

		int t=100;
		fout << t << endl;

		while(t--)
			{
				lli n=rand()%10;
				lli i;

				fout << n << endl;

				while(n--)
					{
						i=rand()%100;

						if(i!=0)
							fout << i << " ";
						else
							n++;
					}
				fout << endl;
			}
		return 0;
	}