//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
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
int dp[209][209];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    for(i=1;i<=200;i++)
    {
        for(j=1;j<=200;j++)
        {
            if(j%2==1)
            {
                if(i%2==1)
                {
                    dp[i][j]=dp[i][j-1]+((i/2)+1);
                }
                else
                    dp[i][j]=dp[i][j-1]+i/2;
            }
            else
            {
                dp[i][j]=dp[i][j-1]+i/2;
            }
        }
    }
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        scanf("%d %d",&m,&n);
        if(m==1||n==1)
        printf("Case %d: %d\n",x,max(m,n));
        else if(m==2||n==2)
        {
            r=max(m,n);
            d=r/2;
            if(d%2==1)
            {
                d=d/2+1;
            }
            else
                d=d/2;
              printf("Case %d: %d\n",x,max(4*d,dp[m][n]));
        }

        else
        printf("Case %d: %d\n",x,dp[m][n]);
    }

    return 0;
}
