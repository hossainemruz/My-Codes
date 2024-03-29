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
int N,k,i,l,maxx;
vector<int>V;
int E[30],track[30];
void check(int ind,int sum)
{
    if(ind==k)
    {
        if(maxx<sum)
        {
            maxx=sum;
            l=V.size();
            for(i=0;i<l;i++)
                E[i]=V[i];
        }
        return;
    }

    if(sum+track[ind]<=N)
    {
        V.push_back(track[ind]);
        check(ind+1,sum+track[ind]);
        V.pop_back();
    }
        check(ind+1,sum);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    while(scanf("%d %d",&N,&k)==2)
    {
        maxx=0;
        memset(track,0,sizeof(track));
       for(i=0;i<k;i++)
        scanf("%d",&track[i]);
      V.clear();
      check(0,0);
       for(i=0;i<l;i++)
        printf("%d ",E[i]);
       printf("sum:%d\n",maxx);
    }

    return 0;
}



