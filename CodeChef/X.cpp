#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main() {
    // your code goes here
    int t,n,i;
    cin>>t;
    while(t--)
    {
        int ac=0;
        int bc=0;
        string s;
        cin>>s;
        n=s.length();
        int x,y;
        cin>>x>>y;
        for(i=0;i<n;i++)
        {
            if(s[i]=='a')
            ac++;
            else
            bc++;
        }
        int xc=0,yc=0;
        while(ac>0 && bc>0)
        {
            while(xc<x && ac>0)
            {cout<<"a";ac--;xc++;}
            xc=0;
            while(yc<y && bc>0)
            {cout<<"b";bc--;yc++;}
            yc=0;
        }
        xc=0;yc=0;
        if(ac==0 )
        {
            while(bc>0)
            {
                while(yc<y && bc>0)
                {cout<<"b";bc--;yc++;}
                yc=0;
                cout<<"*";
            }
        }
        if(bc==0 )
        {
            while(ac>0)
            {
                while(xc<x && ac>0)
                {cout<<"a";ac--;xc++;}
                xc=0;
                if(ac>0)
                cout<<"*";
            }
        }
        cout<<endl;
    }
 
}