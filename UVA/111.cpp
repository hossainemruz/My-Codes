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
int ar[30],br[30],n,dp[30];
int rec(int ind)
{
    int i,mx;
    if(dp[ind]!=-1)
        return dp[ind];
    mx=0;
    for(i=ind+1;i<n;i++)
    {
        if(br[i]>br[ind])
            mx=max(mx,rec(i));
    }
    return dp[ind]=mx+1;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
    }
    while(scanf("%d",&p)==1)
    {
        memset(dp,-1,sizeof(dp));
        br[p]=1;
        for(i=2;i<=n;i++)
        {
            scanf("%d",&p);
            br[p]=i;
        }
        for(i=0;i<n;i++)
        {
            br[i]=ar[br[i+1]];
        }
        sm=0;
        for(i=0;i<n;i++)
            sm=max(sm,rec(i));
        printf("%d\n",sm);

    }

    return 0;
}
