/**************************************
 *    BISMILLAHIR RAHMANIR RAHIM      *
 *         MD: EMRUZ HOSSAIN          *
 *            CUET-CSE-12             *
 **************************************/
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 typedef unsigned long long ULL;

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
int dp[10][10][10][10][2];
string ss,ks,cs;
int rec(int kx,int ky,int cx,int cy,int p)
{
    if(cx==0)
    {
        if(p)
          return 1;
        else
            return 0;
    }
    int &ret=dp[kx][ky][cx][cy][p];
    if(ret!=-1)
        return ret;
    if(p==0)
    {
        int x,y;
        int q=0;
        for(int i=0;i<8;i++)
        {
            x=kx+KR[i];
            y=ky+KC[i];
            if(x>=0&&x<8&&y>=0&&y<8)
            {
                if(x==cx&&y==cy)
                    return ret=1;
                else
                    q|=!rec(x,y,cx,cy,!p);
            }
        }
        return ret=q;
    }
    else
    {
        int q=0;
        if(cx-1>=0&&cy-1>=0)
        {
            if(cx-1==kx&&cy-1==ky)
            {
                if(cx-2>=0&&cy-2>=0)
                    return ret=1;
                else
                {
                  if(cy+1<8)
                        q|=!rec(kx,ky,cx-1,cy+1,!p);
                  else
                    return ret=0;
                }
            }
            else
                q|=!rec(kx,ky,cx-1,cy-1,!p);
        }
        if(cx-1>=0&&cy+1<8)
        {
            if(cx-1==kx&&cy+1==ky)
            {
                if(cx-2>=0&&cy+2<8)
                    return ret=1;
                else
                {
                  if(cy-1>=0)
                        q|=!rec(kx,ky,cx-1,cy-1,!p);
                  else
                    return ret=0;
                }
            }
            else
                q|=!rec(kx,ky,cx-1,cy+1,!p);
        }
        return ret=q;
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,kx,ky,cx,cy;
   cin>>ss;
   cin>>ks>>cs;
   kx=ks[1]-'1';
   ky=ks[0]-'a';
   cx=cs[1]-'1';
   cy=cs[0]-'a';
   //pf("%d %d %d %d\n",kx,ky,cx,cy);
   mem(dp,-1);
   if(ss=="black")
   {
       if(rec(kx,ky,cx,cy,1))
        cout<<"Black"<<endl;
       else
        cout<<"White"<<endl;
   }
   else
   {
       if(rec(kx,ky,cx,cy,0))
       {
           cout<<"White"<<endl;
       }
       else
        cout<<"Black"<<endl;
   }

    return 0;
}




