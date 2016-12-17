
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
int ar[5000],br[5000],Lis[5000],Lds[5000],awt[5000],bwt[5000];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,iwt,dwt;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            br[n-1-i]=ar[i];
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&awt[i]);
            bwt[n-1-i]=awt[i];
        }
        for(i=0;i<n;i++)
        {
            Lis[i]=awt[i];
            Lds[i]=bwt[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(ar[j]>ar[i])
                {
                    Lis[j]=max(Lis[j],Lis[i]+awt[j]);
                }
                if(br[j]>br[i])
                {
                    Lds[j]=max(Lds[j],bwt[j]+Lds[i]);
                }
            }
        }
        iwt=0;dwt=0;
        for(i=0;i<n;i++)
        {
            iwt=max(iwt,Lis[i]);
            dwt=max(dwt,Lds[i]);
        }
        if(iwt>=dwt)
        {
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",x,iwt,dwt);
        }
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n",x,dwt,iwt);
    }


    return 0;
}
