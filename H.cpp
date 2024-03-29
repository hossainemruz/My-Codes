/**************************************
 *           BISMILLAHIR RAHMANIR RAHIM             *
 *                MD: EMRUZ HOSSAIN                    *
 *                     CUET-CSE-12                          *
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
//prm[0]='*'prm[1]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i+=2){if(prm[i]!='*')prime[np++]=i;}*/}
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
char input[500][200],output[500][200];
int visit[500];
vector<char>invalid_character;
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   x=0;
   while(true)
   {
       sf("%d",&n);
       if(n==0)
        break;
       ++x;
       for(i=0;i<n;i++)
        sf("%s %s",&input[i],&output[i]);
       int flag=0;
       mem(visit,0);
       invalid_character.clear();
       for(i=0;i<n;i++)
       {
           l=strlen(output[i]);
           if(l>strlen(input[i]))
           {
               pf("Case %d: I_AM_UNDONE\n",x);
               flag=1;
               break;
           }
           for(j=1;j<l-1;j++)
           {
               if(input[i][j]!=output[i][j])
               {
                 pf("Case %d: I_AM_UNDONE\n",x);
                 flag=1;
                 break;
               }
           }
           if(flag)
            break;
           if(input[i][l-1]!='"'&&visit[input[i][l-1]]==0)
           {
               visit[input[i][l-1]]=1;
               invalid_character.push_back(input[i][l-1]);
           }

       }
       if(flag)
        continue;
       for(i=0;i<n;i++)
       {
           l=strlen(output[i]);
           for(j=1;j<l-1;j++)
           {
               for(k=0;k<invalid_character.size();k++)
               {
                   if(output[i][j]==invalid_character[k])
                   {
                       pf("Case %d: I_AM_UNDONE\n",x);
                       flag=1;
                       break;
                   }
               }
               if(flag)
                break;
           }
           if(flag)
            break;
       }
       if(flag)
        continue;
       set<char>S;
       int num=0,salpha=0,lalpha=0,mn=0,sa=0,la=0;
       for(i=0;i<n;i++)
       {
           l=strlen(output[i]);
           for(j=1;j<l-1;j++)
           {
               if(output[i][j]>='0'&&output[i][j]<='9')
               {
                    num=1;
                    mn=max(mn,(int)output[i][j]);
               }

               if(output[i][j]>='a'&&output[i][j]<='z')
               {
                    salpha=1;
                    sa=max(sa,(int)output[i][j]);
               }

               if(output[i][j]>='A'&&output[i][j]<='Z')
               {
                   lalpha=1;
                   la=max(la,(int)output[i][j]);
               }


           }
       }
       if(num)
        {
          for(i='0';i<=mn;i++)
          {
              if(visit[i]!=1)
                S.insert(i);
          }
       }
       if(lalpha)
       {
           for(i='0';i<='9';i++)
          {
              if(visit[i]!=1)
                S.insert(i);
          }
          for(i='A';i<=la;i++)
          {
              if(visit[i]!=1)
                S.insert(i);
          }
       }
       if(salpha)
       {
         for(i='0';i<='9';i++)
          {
              if(visit[i]!=1)
                S.insert(i);
          }
          for(i='A';i<='Z';i++)
          {
              if(visit[i]!=1)
                S.insert(i);
          }
          for(i='a';i<=sa;i++)
          {
              if(visit[i]!=1)
                S.insert(i);
          }
       }
       char ss[500];
       cnt=0;
       set<char>::iterator itt;
       for(itt=S.begin();itt!=S.end();++itt)
        ss[cnt++]=*itt;
       if(cnt==0)
       {
          for(i='0';i<='9';i++)
          {
              if(visit[i]!=1)
               {
                   ss[cnt++]=i;
                   break;
               }
          }
       }
       if(cnt==0)
          {
              for(i='A';i<='Z';i++)
              {
                  if(visit[i]!=1)
                  {
                      ss[cnt++]=i;
                      break;
                  }
              }
          }
        if(cnt==0)
          {
              for(i='a';i<='a';i++)
              {
                  if(visit[i]!=1)
                  {
                      ss[cnt++]=i;
                      break;
                  }
              }
          }
          if(cnt==0)
          {
               pf("Case %d: I_AM_UNDONE\n",x);
               continue;
          }
       ss[cnt]=0;
       pf("Case %d: [%s]\n",x,ss);
   }

    return 0;
}




