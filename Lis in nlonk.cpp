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
int ar[10005],Temp[10005],Lis[10005],seq[10005];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mxl,h,ind,top;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    Temp[0]=-inf;
    for(i=1;i<=n;i++)
        Temp[i]=inf;
    mxl=0;
    ind=0;
    for(i=0;i<n;i++)
    {
        l=0;h=mxl;
        while(l<=h)
        {
            m=(l+h)/2;
            if(Temp[m]<ar[i])
                l=m+1;
            else
                h=m-1;
        }
        Temp[l]=ar[i];
        Lis[i]=l;
        if(mxl<l)
        {
             mxl=l;
             ind=i;
        }

    }
    printf("%d\n",mxl);
    top=mxl-1;
    seq[top]=ar[ind];
    top--;
    for(i=ind-1;i>=0;i--)
    {
        if(ar[i]<ar[ind]&&Lis[i]==Lis[ind]-1)
        {
            seq[top]=ar[i];
            ind=i;
            top--;
        }
    }
    for(i=0;i<mxl;i++)
        printf("%d ",seq[i]);
    printf("\n");
    return 0;
}
