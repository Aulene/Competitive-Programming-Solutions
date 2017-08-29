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
int main()
{
    int n,k,p;

    scanf("%d %d %d",&n,&k,&p);

    int a[n];
    int te[n];
    
    for(int i=0;i<n;i++)
    	scanf("%d", a[i]);

    char ps[10000];
    cin >> ps;
    
    int ans=0;
    int len=strlen(ps);
    
    for(int i=0; i<len; i++)
    	{  
         	if(ps[i]=='!')
           		{	
	            	int tem=a[0];

					for(int i=0; i<n-2; i++)
						a[i]=a[i+1];
					a[n-1]=tem;
          		}
          else
          	{
				te[0]=a[0];
				
				int i;

				for(i=1; i<n; i++)
					te[i]=a[i]+te[i-1];

				//for(int i=0;i<n;i++)
				// printf("%d\n",te[i]);

				ans=te[min(n-1, k-1)];
				// printf("%d\n",ans);

				for(i=k; i<n; i++)
					{
						ans=max(ans,te[i]-te[i-k]);
						//printf("%d\n",i);
					}

				printf("%d\n", ans);
          	}
      }

    return 0;
}