#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, s;
    cin>>m>>s;
    if(m==1&&s==0)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    string la = "", sm = "";
    if(s==0||s>m*9)la = "--";
    int i = 0, t = m;
    for(i=1;i<=s/9;i++,t--)
    {
        la+="9";
        if(s-sm.length()*9!=9)sm+="9";
    }
    i--;
    if(i++<m)
        la+=to_string(s%9);
    while(i<m)
    {
        la+="0";
        i++;
    }
    t = s-sm.length()*9;
    if(m-sm.length()==1)sm = to_string(t)+sm;
    else if(m!=sm.length())
    {
        if(t>1)sm = to_string(t-1)+sm;
        int l = sm.length();
        for(int i=0;i<m-l-1;i++)
            sm = "0"+sm;
        sm = "1"+sm;
    }
    cout<<((la[0]=='-')?"-1":sm)<<" "<<((la[0]=='-')?"-1":la)<<endl;
    return 0;
}