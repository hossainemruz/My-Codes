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
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define     mem(x,y) memset(x,y,sizeof(x))
#define     PB(x) push_back(x)
#define     POB() pop_back()
#define     SZ(a) a.size()
#define     len(a) strlen(a)
#define     sf scanf
#define     pf printf

#define     inf 1<<25
#define     sz 2000
#define     eps 1e-9
#define     mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}
int Set(int N,int pos){return N=N|(1<<pos);}
int Reset(int N,int pos){return N=N&~(1<<pos);}
bool Check(int N,int pos){return (bool)(N&(1<<pos));}

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
 double ar[100];
 int CHK(double val,int mxi)
 {
     int i;
     double a,b,c,d,mxc,mnc,mxd,mnd,mxa,mxb,mna,mnb,mxab,mnab,mxcd,mncd;
     mxa=ar[0]+val;
     mna=ar[0]-val;
     mxb=ar[3]+val;
     mnb=ar[3]-val;
     mxc=ar[1]+val;
     mnc=ar[1]-val;
     mxd=ar[2]+val;
     mnd=ar[2]-val;
     mxab=max(mxa*mxb,max(mxa*mnb,max(mna*mxb,mna*mnb)));
    mnab=min(mxa*mxb,min(mxa*mnb,min(mna*mxb,mna*mnb)));
    mxcd=max(mxc*mxd,max(mxc*mnd,max(mnc*mxd,mnc*mnd)));
    mncd=min(mxc*mxd,min(mxc*mnd,min(mnc*mxd,mnc*mnd)));
    if(mnab>mxcd||mxab<mncd)
        return 0;
    return 1;


 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   double a,b,c,d,h,m,n,p,x,y,j,k,l,q,r,t,cnt,sm,tmp;
   double mx=-1000000005;
   int mxi=0;
   for(int i=0;i<4;i++)
   {
        sf("%lf",&ar[i]);
        if(ar[i]>mx)
        {
            mx=ar[i];
            mxi=i;
        }
   }
   l=0.00;h=1000000009;
   double mid;
   for(int i=0;i<100005;i++)
   {
       mid=(l+h)/2.00;
       if(CHK(mid,mxi))
        h=mid;
       else
        l=mid;
   }
   pf("%.10lf\n",l);


    return 0;
}
