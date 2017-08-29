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

int main()
{
    lli n, m, k, x, y, t;
    lli maxAns, minAns, sergei;
    lli r, rem;
    cin >> n >> m >> k >> x >> y;
    
     if(k<=(n*m))
     {   
     	if(k!=(n*m))
        	 cout << "1 0 ";
        else
        	cout << "1 1 ";
         if(((x-1)*m+y)<=k)
       	 	cout<<1<<endl;
         else
         cout<<0<<endl;

         return 0;     
     }
     else
	     {
	     	if(n==1)
	     	{
	     		r=k/m;
	     		t=k%m;
	     		
	     		if(!t)
		     		{
		     			maxAns=r;
		     			minAns=r;
		     			sergei=r;
		     		}
		     	else
		     		{
		     			maxAns=r+1;
		     			minAns=r;
		     			if(y<=t)
		     				sergei=maxAns;
		     			else
		     				sergei=minAns;
		     		}
	     		cout<<maxAns<<" "<<minAns<<" "<<sergei;
	     		return 0;		
	     	}
	     	
	         r=(k-n*m);
	         r=r/(m*(n-1));
	         rem=(k-r*(m*(n-1))-n*m);
	         maxAns=1+r;
	         minAns=1;
	         if(rem)
	         	maxAns++;

	         minAns=minAns+(r/2);
	         if(r%2==0)
	         {  
	         	if(rem>m)
	                maxAns++;
	            if(x==1)
	             {
	                 sergei=minAns;
	                 if(y<=rem)
	                 sergei++;
	             }
	             
	          	else if(x==n)
	             {
	                sergei=minAns;
	                if((x-1)*m+y<=rem)
	                	sergei++;
	             }
	            else
		            { 
		            	sergei=maxAns;
		                if((x-1)*m+y<=rem)
		                	sergei++;
		            }
	         }
	         else
		        {
		            if(rem>m)
		                maxAns++;
		                 
		            if(x==n)
			            {
			                sergei=minAns;
			                if(y<=rem)
			                	sergei++;
			                 
			               
			            }
		            else if(x==1)
		             	sergei=minAns;
		            else
			            {
			             	sergei=maxAns;
			                if((n+1-x-1)*m+y<=rem)
			                	sergei++;
			            } 
		        }
	         cout<<maxAns<<" "<<minAns<<" "<<sergei<<endl;
	     }
    
    
}