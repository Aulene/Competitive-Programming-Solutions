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
 
int main(){
 
    int t;
    scanf("%d",&t);
    while(t--){
 
        long long n,k,b,i;
        scanf("%lld %lld %lld",&n,&k,&b);
        long long data[n];
        for(i=0;i<n;i++)
            scanf("%lld",&data[i]);
        sort(data,data+n);
        long long m=data[0],req=k*data[0]+b,count=1,flag=0;
        for(i=1;i<n;i++){
            if(data[i]>=req){
                count++;
                m=data[i];
                req=k*m+b;
                flag=1;
            }
        }
        if(flag==0){
            printf("0\n");
            continue;
        }
        printf("%lld\n",count);
    }
    return 0;
}