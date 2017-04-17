/**************************************
 *     BISMILLAHIR RAHMANIR RAHIM     *
 *        MD: EMRUZ HOSSAIN           *
 *           CUET-CSE-12              *
 **************************************/
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;

#define     mem(x,y)   memset(x,y,sizeof(x))
#define     PB(x)      push_back(x)
#define     POB()      pop_back()
#define     SZ(a)      a.size()
#define     len(a)     strlen(a)
#define     SQR(a)     (a*a)
#define     all(v)     v.begin(),v.end()
#define     fr(i,a,b)  for(i=a;i<=b;i++)
#define     rfr(i,a,b) for(i=a;i>=b;i--)
#define     sf  scanf
#define     pf  printf
#define     mkp make_pair
#define     fs  first
#define     sd  second

#define     getx() getchar()
//#define     getx() getchar_unlocked()

#define     inf  1<<25
#define     sz   20002
#define     eps  1e-9
#define     mod  1000000007
#define     PI   2.0*acos(0.0)

template <typename T> T gcd(T a,T b){return (b != 0 ? gcd(b, a%b) : a);}
template <typename T> T lcm(T a, T b) { return (a/gcd(a,b)*b);}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Swap(T &a,T &b) {T tmp=a;a=b;b=tmp;}
int Set(int N,int pos){return N=N|(1<<pos);}
int Reset(int N,int pos){return N=N&~(1<<pos);}
bool Check(int N,int pos){return (bool)(N&(1<<pos));}
double DEG(double x) { return (180.0*x)/(PI);}
double RAD(double x) { return (x*(double)PI)/(180.0);}
int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
template<class T>inline bool readfast(T &x)
{
    int c=getx();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getx();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getx())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1}; //move in 8 direction
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2}; //move of knight

////code of sieve
//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i+=2){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';prm[1]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i+=2){if(prm[i]!='*')prime[np++]=i;}*/}
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

 /*****************************Code start from here**************************/
P ar[100005],bin;
int visit[100005],n;
double dist(P a,P b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

vector<pair<double ,int> >v1,v2;
double ans;
bool cmp(pair<double,int> a, pair<double,int> b)
{
    if(fabs(a.fs-b.fs)<eps)
        return a.sd<b.sd;
    else
        return a.fs>b.fs;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   P ad,br,bn;
   sf("%lf %lf %lf %lf %lf %lf",&ad.x,&ad.y,&br.x,&br.y,&bn.x,&bn.y);
   bin=bn;
   sf("%d",&n);
   for(i=0;i<n;i++)
   {
       sf("%lf %lf",&ar[i].x,&ar[i].y);
   }
   if(n==1)
   {
      pf("%.12lf\n",min(dist(ad,ar[0])+dist(bn,ar[0]),dist(br,ar[0])+dist(bn,ar[0])));
   }
   else
   {
        ans=0.0;

       for(i=0;i<n;i++)
       {
           ans+=2.0*dist(bn,ar[i]);
           v1.push_back(make_pair(dist(bn,ar[i])-dist(ad,ar[i]),i));
           v2.push_back(make_pair(dist(bn,ar[i])-dist(br,ar[i]),i));
       }
       sort(v1.begin(),v1.end(),cmp);
       sort(v2.begin(),v2.end(),cmp);
       if(v1[0].fs<0.0&&v2[0].fs<0.0)
         ans-=max(v1[0].fs,v2[0].fs);
       else
       {
           if(v1[0].sd==v2[0].sd)
           {
               if(max(0.0,v1[0].fs)+max(0.0,v2[1].fs)>max(0.0,v2[0].fs)+max(0.0,v1[1].fs))
                   ans-=max(0.0,v1[0].fs)+max(0.0,v2[1].fs);
                else
                    ans-=max(0.0,v2[0].fs)+max(0.0,v1[1].fs);
           }
           else
               ans-=max(0.0,v1[0].fs)+max(0.0,v2[0].fs);
       }
       pf("%.12lf\n",ans);
   }
    return 0;
}



