/***************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                *
 *                      MD: EMRUZ HOSSAIN                      *
 *                         CUET-CSE-12                         *
 ***************************************************************/
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
#define     read(n)       scanf("%d",&n)
#define     read2(m,n)    scanf("%d %d",&m,&n)
#define     read3(m,n,p)  scanf("%d %d %d",&m,&n,&p)
#define     readl(n)      scanf("%I64d",&n);
#define     readl2(m,n)   scanf("%I64d %I64d",&m,&n)
#define     readl3(m,n,p) scanf("%I64d %I64d %I64d",&m,&n,&p)

#define     getx() getchar()
//#define     getx() getchar_unlocked()

#define     inf  1<<25
#define     sz   20002
#define     eps  1e-9
//#define     mod  1000000007
#define     PI   2.0*acos(0.0)

template <typename T> T gcd(T a,T b){return (b != 0 ? gcd(b, a%b) : a);}
template <typename T> T lcm(T a, T b) { return (a/gcd(a,b)*b);}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Swap(T &a,T &b) {T tmp=a;a=b;b=tmp;}

template<typename T>
T MultiplyMod(T a, T b, T mod) { //computes a * b % mod
    T r = 0;
    a %= mod, b %= mod;
    while (b) {
        if (b & 1) r = (r + a) % mod;
        b >>= 1, a = ( a << 1) % mod;
    }
    return r;
}
template<typename T>
T PowerMod(T a, T n, T mod) {  //computes a^n % mod
    T r = 1;
    while (n) {
        if (n & 1) r = MultiplyMod(r, a, mod);
        n >>= 1, a = MultiplyMod(a, a, mod);
    }
    return r;
}
template<typename T>
bool isprime(T n) { //determines if n is a prime number
    const int pn = 9, p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for (int i = 0; i < pn; ++i)
        if (n % p[i] == 0) return n == p[i];
    if (n < p[pn - 1]) return 0;
    T s = 0, t = n - 1;
    while (~t & 1)
        t >>= 1, ++s;
    for (int i = 0; i < pn; ++i) {
        T pt = PowerMod<T> (p[i], t, n);
        if (pt == 1) continue;
        bool ok = 0;
        for (int j = 0; j < s && !ok; ++j) {
            if (pt == n - 1) ok = 1;
            pt = MultiplyMod(pt, pt, n);
        }
        if (!ok) return 0;
    }
    return 1;
}

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
int pml=12345,np=0;
char prm[12347];
//int prime[800000];
void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
prm[0]='*';prm[1]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
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

 /**************************************************Code start from here**************************/
int ar[12345];
struct st
{
    int prop,prime,l,r;
}tree[4*100005];
int check_prime(int p)
{
    if(p<=12345)
    {
        if(prm[p]!='*')
            return 1;
        else
            return 0;
    }
    return isprime(p);
}
void build(int rt,int beg,int endd)
{
    if(beg==endd)
    {
        tree[rt].prop=ar[beg];
        int p=tree[rt].prop;
        if(check_prime(p))
            tree[rt].prime=1;
        else
            tree[rt].prime=0;
        return;
    }
    tree[rt].prime=0;
    tree[rt].prop=0;
    tree[rt].l=beg;
    tree[rt].r=endd;
    int mid=(beg+endd)/2;
    build(2*rt,beg,mid);
    build(2*rt+1,mid+1,endd);
    tree[rt].prime=tree[2*rt].prime+tree[2*rt+1].prime;
}
void push_down(int rt,int prop)
{
    tree[rt].prop=0;
    tree[2*rt].prop=prop;
    tree[2*rt+1].prop=prop;
    if(check_prime(prop))
    {
        tree[2*rt].prime=tree[2*rt].r-tree[2*rt].l+1;
        tree[2*rt+1].prime=tree[2*rt+1].r-tree[2*rt+1].l+1;
    }
    else
    {
        tree[2*rt].prime=0;
        tree[2*rt+1].prime=0;
    }

}
void update(int rt,int beg,int endd,int idx,int val)
{
    if(beg==idx&&endd==idx)
    {
            tree[rt].prop+=val;
        int p=tree[rt].prop;
        if(check_prime(p))
            tree[rt].prime=1;
        else
            tree[rt].prime=0;
        return;
    }
    int mid=(beg+endd)/2;
    if(tree[rt].prop!=0)
            push_down(rt,tree[rt].prop);
    if(idx<=mid)
        update(2*rt,beg,mid,idx,val);
    else
        update(2*rt+1,mid+1,endd,idx,val);
    tree[rt].prime=tree[2*rt].prime+tree[2*rt+1].prime;

}
void update2(int rt,int beg,int endd,int l,int r,int val)
     {
            if(beg>r||endd<l)
                return;
            if(beg>=l&&endd<=r)
            {
                tree[rt].prop=val;
                if(check_prime(val))
                    tree[rt].prime=tree[rt].r-tree[rt].l+1;
                else
                    tree[rt].prime=0;
                return;
            }
            if(tree[rt].prop!=0)
                push_down(rt,tree[rt].prop);
            int mid=(beg+endd)/2;
            update2(2*rt,beg,mid,l,r,val);
            update2(2*rt+1,mid+1,endd,l,r,val);
            tree[rt].prime=tree[2*rt].prime+tree[2*rt+1].prime;
    }
int query(int rt,int beg,int endd,int l,int r)
{
    if(beg>r||endd<l)
        return 0;
    if(beg>=l&&endd<=r)
    {
       return tree[rt].prime;
    }
     if(tree[rt].prop!=0)
                push_down(rt,tree[rt].prop);
    int mid=(beg+endd)/2;
    return query(2*rt,beg,mid,l,r)+query(2*rt+1,mid+1,endd,l,r);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sieve();
  for(i=0;i<100000;i++)
  {
      a=100000+rand()%10001;
      check_prime(a);
  }
  pf("Complete.\n");
    return 0;
}



