//KAZUMA DESU
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int ans[1000007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, a, b, i, j, t, k;

		cin >> n >> a >> b;

		if(a == 1 || b == 1)
			{
				for(i = 1; i <= n; i++) cout << i << " "; cout << endl;
				exit(0);
			} 
	
		if(n % b == 0)
			{
				for(i = 1; i <= n; i += b)
					{
						t = i + 1;

						for(j = i; j < i + b - 1; j++)
							ans[j] = t, t++;
						ans[i + b - 1] = i;
					}

				for(i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
				exit(0);
			}

		if(n % a == 0)
			{
				for(i = 1; i <= n; i += a)
					{
						t = i + 1;

						for(j = i; j < i + a - 1; j++)
							ans[j] = t, t++;
						ans[i + a - 1] = i;
					}

				for(i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
				exit(0);
			}

		if(a > b)
			swap(a, b);

		for(i = 1;; i++) 
			{
				if(a * i > n)
					{
						cout << -1 << endl;
						exit(0);
					}

				if((n - i * a) % b == 0)
					{
	     				for(j = 1; j <= i * a; j += a)
		     				{
			       				k = j + 1;

			        			for(t = j; t < j + a - 1; t++)
				        			{
				        				ans[t] = k;
				        				k++;
				        			}
		        		
		        				ans[j + a - 1] = j;
	      					}

		      			for(j = i * a + 1; j <= n; j += b)
		      				{
		        				k = j + 1;

		       		 			for(t = j; t < j + b - 1; t++)
			       		 			{
				          				ans[t] = k;
				        				k++;
			        				}
		        			
		        				ans[j + b - 1] = j;
		     		 		}
		    			
		    			for(j = 1; j <= n; j++)
		        			cout << ans[j] << " ";
		    			cout << endl;
    					
    					exit(0);
   					}
			}

		return 0;
	}