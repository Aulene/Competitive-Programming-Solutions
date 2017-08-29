#include<iostream>
#include<algorithm>
#include<vector>
 
 
using namespace std;
 
#define lli long long int

struct interval
{
    int pointa;
    int pointb;
};
 
interval intervals[100007];
vector<int> fuck;
lli a[100007];

bool compare(interval a, interval b)
{
    return a.pointb < b.pointb;
}
 
int main()
{
    lli n, i, u, v, ans=0, f;
    cin >> n;
    
    for(i=0; i<n; i++)
        cin >> a[i];

    for(i=1; i<n; i++)
        {
            intervals[i-1].pointa=a[i-1];
            intervals[i-1].pointb=a[i];

            if(intervals[i-1].pointa > intervals[i-1].pointb)
                {
                    f=intervals[i-1].pointa;
                    intervals[i-1].pointa=intervals[i-1].pointb;
                    intervals[i-1].pointb=f;
                }
        }
 
    sort(intervals, intervals+n, compare);
 
    vector<int>::iterator it;
    bool c;
 
    for(i=0; i<n; i++)
        {
            c=1;
            for(it=fuck.begin(); it!=fuck.end(); it++)
                {
                    if(*it>=intervals[i].pointa && *it<=intervals[i].pointb)
                        {
                            c=0;
                            break;
                        }
                }
 
            if(c)
                {
                    fuck.push_back(intervals[i].pointb);
                    ans++;
                }
        }
 
    cout << ans << endl;
 
    return 0;
}