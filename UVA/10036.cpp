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

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
int dp[10001][201];
int n,ar[10005],k;
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,p,x,y,i,j,l,q,r,t,cnt,sm,tmp,ind;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        dp[0][(ar[0]%k)+100]=1;
     for(ind=1;ind<n;ind++)
     {
       for(i=0;i<=199;i++)
       {
           if(dp[ind-1][i]==1)
           {
               p=i-100;
               p=p+ar[ind];
               p=p%k;
               p+=100;
               dp[ind][p]=1;
               p=i-100;
               p=p-ar[ind];
               p=p%k;
               p+=100;
               dp[ind][p]=1;
           }
       }
     }
       if(dp[n-1][100]==1)
        printf("Divisible\n");
       else
        printf("Not divisible\n");
    }

    return 0;
}