//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct P
{
    double x,y;
    P(double x=0.0, double y=0.0)
    {
        this ->x=x;
        this ->y=y;
    }
};
P mkv(P ae,P be){return P(be.x-ae.x,be.y-ae.y);}
double dtp(P ae,P be){return (ae.x*be.x+ae.y*be.y);}
double crp(P ae,P be){return (ae.x*be.y-ae.y*be.x);}
double val(P ae){return sqrt(dtp(ae,ae));}
P vresize(P ae,double llen){double v=val(ae);return P(ae.x*llen/v,ae.y*llen/v);}
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}
 map<string,map<int,int> >mp,getcrd;
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,time,num;
    string home,away;
    char ch,crd;
    cin>>home>>away;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>time>>ch>>num>>crd;
        if(ch=='h')
        {
            if(mp[home][num]<2&&crd=='y')
            {
                mp[home][num]++;
                if(mp[home][num]>=2&&getcrd[home][num]==0)
                {
                    getcrd[home][num]=1;
                       cout<<home<<" "<<num<<" "<<time<<endl;
                }


            }
            else if(crd=='r'&&getcrd[home][num]==0)
            {
                getcrd[home][num]=1;
                 cout<<home<<" "<<num<<" "<<time<<endl;
            }

        }
        else
        {
            if(mp[away][num]<2&&crd=='y')
            {
                mp[away][num]++;
                if(mp[away][num]>=2&& getcrd[away][num]==0)
                {
                     getcrd[away][num]=1;
                     cout<<away<<" "<<num<<" "<<time<<endl;
                }


            }
            else if(crd=='r'&&getcrd[away][num]==0)
            {
                 getcrd[away][num]=1;
                cout<<away<<" "<<num<<" "<<time<<endl;
            }

        }
    }

    return 0;
}
