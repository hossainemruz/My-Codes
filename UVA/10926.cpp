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
vector<int>v[105];
int dp[105],visit[105];
int rec(int ind)
{
    int i,p=0;
//    if(dp[ind]!=-1)
//        return dp[ind];
    if(v[ind].size()==0)
        return 0;
    for(i=0;i<v[ind].size();i++)
    {
        if(visit[v[ind][i]]==0)
        {
            visit[v[ind][i]]=1;
             p+=(rec(v[ind][i])+1);

        }

    }
    return dp[ind]=p;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mx;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        memset(dp,-1,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&p);
            for(j=0;j<p;j++)
            {
                scanf("%d",&q);
                v[i].push_back(q);
            }
        }
        mx=0;
        for(i=1;i<=n;i++)
        {
            memset(visit,0,sizeof(visit));
            p=rec(i);
            if(p>mx)
            {
                mx=p;
                sm=i;
            }
        }
        if(mx==0)
            printf("1\n");
        else
            printf("%d\n",sm);
//    for(i=1;i<=n;i++)
//        printf("%d ",dp[i]);
//    printf("\n");
        for(i=0;i<=n;i++)
            v[i].clear();
    }

    return 0;
}
