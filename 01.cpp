#include<bits/stdc++.h>
#define per(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;
typedef long long ll;
const int inf =0x3f3f3f3f;
const double eps=1e-8;
#define siz 100005
int n,head[siz],Enum=0;
ll ans=0,jie;
struct Edge{int to,w,ne;}edge[siz*2];
void init(){
    ans=0;
    Enum=0;
    memset(head,-1,sizeof(head));
    jie=1;
    per(i,2,n-1)jie=jie*i%mod;
}
void add_edge(int a,int b,int c){
    edge[Enum].to=b;
    edge[Enum].w=c;
    edge[Enum].ne=head[a];
    head[a]=Enum++;
}
ll dfs(int u,int pre)
{
    ll sz=1,csz=0;
    ll tmp;
    for(int i=head[u];i!=-1;i=edge[i].ne){
        int v=edge[i].to;
        if(v==pre)continue;
        csz=dfs(v,u);
        tmp=(long long)csz*(n-csz)%mod*2%mod*jie%mod*edge[i].w%mod;
        ans=(ans+tmp)%mod;
        sz+=csz;
    }
    return sz;
}

int main()
{
    freopen("Data_In.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        init();
        int a,b,c;
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&a,&b,&c);
            add_edge(a,b,c);add_edge(b,a,c);
        }
        dfs(1,-1);
        printf("%lld\n",ans);
    }

    return 0;
}




