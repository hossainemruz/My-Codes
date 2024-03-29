/**************************************************************
 *                          BISMILLAHIR RAHMANIR RAHIM               *
 *                                  MD: EMRUZ HOSSAIN                          *
 *                                           CUET-CSE-12                               *
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


/******************************************Code start from here**************************/
int dp[1001][1001];
int flag,sum;
struct BearPlaysDiv2{
    void rec(int a,int b)
    {
        int c=sum-(a+b);
        if(a==b&&b==c)
        {
            flag=1;
            return;
        }
        if(dp[a][b]==1)
            return;
        dp[a][b]=1;
        int ar[4];
        ar[0]=a;ar[1]=b;ar[2]=c;
        sort(ar,ar+3);
        rec(ar[0]+ar[0],ar[1]-ar[0]);
        rec(ar[0]+ar[0],ar[2]-ar[0]);
        rec(ar[1]+ar[1],ar[2]-ar[1]);

    }
string equalPiles(int A, int B, int C)
{
    string ret="impossible";
     int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
     sum=A+B+C;
     mem(dp,0);
     if(sum%3!=0);
      return ret;
      flag=0;
      if(A==B&&C==A)
        flag=1;
      int ar[4];
      ar[0]=A;ar[1]=B;ar[2]=C;
        sort(ar,ar+3);
       rec(ar[0],ar[1]);
       rec(ar[0],ar[2]);
       rec(ar[1],ar[2]);
      if(flag)
        ret="possible";

    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 15; int Arg2 = 35; string Arg3 = "possible"; verify_case(0, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; string Arg3 = "impossible"; verify_case(1, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 8; string Arg3 = "impossible"; verify_case(2, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 18; int Arg2 = 18; string Arg3 = "possible"; verify_case(3, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 225; int Arg1 = 500; int Arg2 = 475; string Arg3 = "possible"; verify_case(4, Arg3, equalPiles(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
BearPlaysDiv2 ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
